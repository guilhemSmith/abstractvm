/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:06:35 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/05 10:53:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "errors.hpp"
#include "AbstractVM.hpp"
#include "TokenOperation.hpp"
#include "TokenError.hpp"
#include "TokenValue.hpp"
#include "OperandInt8.hpp"
#include "OperandInt16.hpp"
#include "OperandInt32.hpp"
#include "OperandFloat.hpp"
#include "OperandDouble.hpp"

std::regex const				AbstractVM::regex_orand = \
									std::regex("^(\\w+)\\(([+-]?[\\d.]+)\\)$");

AbstractVM::tOrandCreate const		AbstractVM::create_tab[] = {
	&AbstractVM::createInt8,
	&AbstractVM::createInt16,
	&AbstractVM::createInt32,
	&AbstractVM::createFloat,
	&AbstractVM::createDouble,
};

std::string const				AbstractVM::identify_operand_type[] = {
	"int8",
	"int16",
	"int32",
	"float",
	"double",
};

AbstractVM::AbstractVM(void) {}

AbstractVM::~AbstractVM(void) {}

std::list<std::vector<IToken *>> const & \
							AbstractVM::getList(void) const {
	return this->input_list;
}

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
	this->checkErrors();
}

void						AbstractVM::printList(void) const {
	std::list<std::vector<IToken *>>::const_iterator	vec;
	std::vector<IToken *>::const_iterator				tok;

	std::cout << " --- " << std::endl \
		<< "Printing input instructions list:" << std::endl;
	for (auto instruction : this->input_list) {
		for (auto token : instruction) {
			std::cout << token->toString();
		}
		std::cout << std::endl;
	}
	std::cout << " --- " << std::endl;
}

void						AbstractVM::clearList(void) {
	std::list<std::vector<IToken *>>::iterator	vec;
	std::vector<IToken *>::iterator				tok;

	for (vec=this->input_list.begin(); vec !=this->input_list.end(); vec++) {
		for (tok = vec->begin(); tok != vec->end(); tok++) {
			delete *tok;
		}
	}
	this->input_list = std::list<std::vector<IToken *>>();
}

void						AbstractVM::checkErrors(void) \
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

IToken *				AbstractVM::createValue(std::string value_raw) const {
	std::smatch				grps;

	if (std::regex_search(value_raw, grps, AbstractVM::regex_orand)) {
		if (grps.size() == 3) {
			for (size_t i = 0; i < AbstractVM::nb_orand_type; i++) {
				if (AbstractVM::identify_operand_type[i] != grps[1]) {
					continue;
				}
				IOperand const *	op = this->createOperand( \
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

IOperand const *		AbstractVM::createOperand( eOperandType type, \
						std::string const& value ) const {
	if (type < 0 || type >= AbstractVM::nb_orand_type) {
		return NULL;
	}
	return (this->*create_tab[type])(value);
}
IOperand const *		AbstractVM::createInt8(std::string const& value) const {
	long double	large_value;
	int8_t		smoll_value;

	try {
		large_value = stol(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (int8_t)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandInt8(smoll_value, value.substr(1));
	}
	return new OperandInt8(smoll_value, value);
}
IOperand const *		AbstractVM::createInt16(std::string const& value) const {
	long double	large_value;
	int16_t		smoll_value;

	try {
		large_value = stol(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (int16_t)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandInt16(smoll_value, value.substr(1));
	}
	return new OperandInt16(smoll_value, value);
}
IOperand const *		AbstractVM::createInt32(std::string const& value) const {
	long double	large_value;
	int32_t		smoll_value;

	try {
		large_value = stod(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (int32_t)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandInt32(smoll_value, value.substr(1));
	}
	return new OperandInt32(smoll_value, value);
}
IOperand const *		AbstractVM::createFloat(std::string const& value) const {
	long double	large_value;
	float		smoll_value;

	try {
		large_value = stod(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (float)large_value;
	if (large_value / smoll_value == 1) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandFloat(smoll_value, value.substr(1));
	}
	return new OperandFloat(smoll_value, value);
}
IOperand const *		AbstractVM::createDouble(std::string const& value) const {
	long double	large_value;
	double		smoll_value;

	try {
		large_value = stod(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (double)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandDouble(smoll_value, value.substr(1));
	}
	return new OperandDouble(smoll_value, value);
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