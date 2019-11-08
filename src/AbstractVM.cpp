/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:06:35 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 16:25:36 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "errors.hpp"
#include "AbstractVM.hpp"
#include "InstructionArg.hpp"
#include "InstructionError.hpp"
#include "InstructionSimple.hpp"
#include "OperandInt8.hpp"
#include "OperandInt16.hpp"
#include "OperandInt32.hpp"
#include "OperandFloat.hpp"
#include "OperandDouble.hpp"
#include "TokenOperation.hpp"
#include "TokenError.hpp"
#include "TokenValue.hpp"

std::regex const				AbstractVM::regex_orand = \
									std::regex("^(\\w+)\\(([+-]?[\\d.]+)\\)$");

std::string const				AbstractVM::get_operand_type[] = {
	"int8",
	"int16",
	"int32",
	"float",
	"double",
};

AbstractVM::AbstractVM(void): factory(), input_list(), memory(), \
							exit_flag(false), line(0) {}

AbstractVM::~AbstractVM(void) {}

void						AbstractVM::readInput(std::istream & input_src) \
								throw(AbstractVMException) {
	std::string							input_buf;
	std::stringstream					ss;

	while (input_src.good()) {
		std::getline(input_src, input_buf);
		if (!input_src.good() && !input_src.eof()) {
			continue;
		}
		size_t	endl = input_buf.find(";");
		ss = std::stringstream(input_buf.substr(0, endl));
		std::vector<IToken *>	vec = this->tokenize(ss);
		if (vec.size() > 0) {
			this->input_list.push_back(vec);
		}
		if (endl != input_buf.npos && input_buf[endl + 1] == ';') {
			break;
		}
	}
	this->checkLexErrors();
}

void						AbstractVM::parseTokens(void) \
								throw (AbstractVMException) {
	std::vector<std::tuple<int, std::string>>	error_vec;
	size_t										i = 1;
	
	for (auto instruction : this->input_list) {
		this->addInstruction(instruction);
		i++;
	}
	this->checkSynErrors();
}

void						AbstractVM::runInstructions(void) \
									throw(AbstractVMException) {
	for (auto instruction: this->instruction_list) {
		this->line++;
		if (this->exit_flag) {
			throw IncorrectExit(false);
		}
		instruction->run(this->memory, this->exit_flag);
	}
	if (!this->exit_flag) {
		throw IncorrectExit(true);
	}
}

void						AbstractVM::printLists(void) const {
	std::list<std::vector<IToken *>>::const_iterator	vec;
	std::vector<IToken *>::const_iterator				tok;

	std::cout << " --- " << std::endl \
		<< "Printing tokens list:" << std::endl;
	for (auto instruction : this->input_list) {
		for (auto token : instruction) {
			std::cout << "{" << token->toString() << "}";
		}
		std::cout << std::endl;
	}
	std::cout << " --- " << std::endl;
	std::cout << "Printing instruction list:" << std::endl;
	for (auto instruction : this->instruction_list) {
		std::cout << "[" << instruction->toString() << "]" << std::endl;
	}
	std::cout << " --- " << std::endl;
	std::cout << "Printing ";
	this->printMemory(std::cout);
	std::cout << " --- " << std::endl;
}

void						AbstractVM::printMemory(std::ostream & out) const {
	out << "stack:" <<std::endl;
	for (auto value: this->memory) {
		out << value->toString() << std::endl;
	}
}

void						AbstractVM::reset(void) {
	std::list<std::vector<IToken *>>::iterator	vec;
	std::vector<IToken *>::iterator				tok;

	for (auto instruction : this->input_list) {
		for (auto token : instruction) {
			delete token;
		}
	}
	this->input_list = std::list<std::vector<IToken *>>();
	for (auto instruction: this->instruction_list) {
		delete instruction;
	}
	this->instruction_list = std::list<IInstruction *>();
	for (auto value: this->memory) {
		delete value;
	}
	this->memory = std::list<IOperand const *>();
	this->exit_flag = false;
	this->line = 0;
}

size_t const &				AbstractVM::getLine(void) const {
	return this->line;
}

void						AbstractVM::checkLexErrors(void) const \
								throw(AbstractVMException) {
	std::vector<std::tuple<int, std::string>>	error_vec;
	size_t										i = 1;
	
	for (auto instruction : this->input_list) {
		for (auto token : instruction) {
			if (token->getType() == eTokenType::Error) {
				TokenError * const	error = dynamic_cast<TokenError *>(token);
				std::tuple<int, std::string> msg(i, error->getErrorMessage());
				error_vec.push_back(msg);
			}
		}
		i++;
	}
	if (error_vec.size() > 0) {
		throw LexerFail(error_vec);
	}
}

void						AbstractVM::checkSynErrors(void) const \
								throw(AbstractVMException) {
	std::vector<std::tuple<int, std::string>>	error_vec;
	size_t										i = 1;
	
	for (auto instruction : this->instruction_list) {
		if (instruction->getType() == eInstructionType::InstError) {
			InstructionError * const	error = \
				dynamic_cast<InstructionError *>(instruction);
			std::tuple<int, std::string> msg(i, error->getErrorMessage());
			error_vec.push_back(msg);
		}
		i++;
	}
	if (error_vec.size() > 0) {
		throw ParserFail(error_vec);
	}
}

std::vector<IToken *>	AbstractVM::tokenize(std::stringstream & ss) const {
	std::string				input_buf;
	eOperationType			opType;
	std::vector<IToken *>	vec = std::vector<IToken *>();

	while (ss >> input_buf) {
		opType = TokenOperation::stringToOpType(input_buf);
		if (opType != eOperationType::Invalid) {
			vec.push_back(new TokenOperation(opType));
		} else {
			vec.push_back(this->createValue(input_buf));
		}
	}
	return vec;
}

void					AbstractVM::addInstruction(std::vector<IToken *> tok) {
	IInstruction *		new_instr;
	TokenOperation *	first;
	std::string			inst_str;

	inst_str = AbstractVM::tokensToString(tok);
	first = dynamic_cast<TokenOperation *>(tok[0]);
	if (first != NULL) {
		if ((first->expectArg() && tok.size() == 2) \
			|| (!first->expectArg() && tok.size() == 1)) {
			if (first->expectArg()) {
				TokenValue *	second = dynamic_cast<TokenValue *>(tok[1]);
				if (second != NULL) {
					new_instr = \
						new InstructionArg(first->getOperationType(), \
							second->getOperand());
				} else {
					new_instr = new InstructionError(inst_str, IncorrectInstr);
				}
			} else {
				new_instr = new InstructionSimple(first->getOperationType());
			}
		} else if (first->expectArg() && tok.size() < 2) {
			new_instr = new InstructionError(inst_str, MissingArg);
		} else {
			new_instr = new InstructionError(inst_str, TooManyArg);
		}
	} else {
		new_instr = new InstructionError(inst_str, IncorrectInstr);
	}
	this->instruction_list.push_back(new_instr);
}

IToken *				AbstractVM::createValue(std::string value_raw) const {
	std::smatch				grps;

	if (std::regex_search(value_raw, grps, AbstractVM::regex_orand)) {
		if (grps.size() == 3) {
			for (size_t i = 0; i < this->factory.nb_orand_type; i++) {
				if (AbstractVM::get_operand_type[i] != grps[1]) {
					continue;
				}
				IOperand const *	op = this->factory.createOperand( \
											(eOperandType)i, grps[2]);
				if (op == NULL) {
					return new TokenError(ErrValue, grps[0]);
				}
				return new TokenValue(op);
			}
		}
		return new TokenError(ErrValueType, value_raw);
	}
	return new TokenError(ErrToken, value_raw);
}

std::string				AbstractVM::tokensToString(std::vector<IToken *> tok) {
	std::stringstream	ss;
	int					i = tok.size();

	for (auto token: tok) {
		i--;
		ss << token->toString();
		if (i > 0) {
			ss << ' ';
		}
	}
	return ss.str();
}

AbstractVM::AbstractVMException::AbstractVMException(void) throw() {
	this->message = "";
}

AbstractVM::AbstractVMException::AbstractVMException(const AbstractVMException &rhs) \
							throw() : message(rhs.message) {}

AbstractVM::AbstractVMException::~AbstractVMException(void) throw() {}

const char *			AbstractVM::AbstractVMException::what(void) const throw() {
	return this->message.c_str();
}