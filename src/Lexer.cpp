/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:06:35 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 19:06:10 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "Lexer.hpp"
#include "TokenOperation.hpp"
#include "TokenError.hpp"
#include "TokenValue.hpp"

std::regex const				Lexer::regex_orand = \
									std::regex("^(\\w+)\\(([\\d.]+)\\)$");

Lexer::tOrandCreate const		Lexer::create_tab[] = {
	&Lexer::createInt8,
	&Lexer::createInt16,
	&Lexer::createInt32,
	&Lexer::createFloat,
	&Lexer::createDouble,
};

Lexer::Lexer(void) {}

Lexer::~Lexer(void) {}

void						Lexer::readInput(std::istream & input_src) throw() {
	std::string							input_buf;
	std::stringstream					ss;
	bool								run = true;

	while (run) {
		std::getline(input_src, input_buf);
		if (input_src.bad() || input_src.eof()) {
			run = false;
			continue;
		}
		ss = std::stringstream(input_buf);
		std::vector<IToken *>	vec = this->tokenize(ss);
		if (vec.size() > 0) {
			this->input_list.push_back(vec);
		}
	}
}

void						Lexer::printList(void) const {
	std::list<std::vector<IToken *>>::const_iterator	vec;
	std::vector<IToken *>::const_iterator				tok;

	std::cout << " --- " << std::endl \
		<< "Printing input instructions list:" << std::endl;
	for (vec = this->input_list.begin(); vec !=this->input_list.end(); vec++) {
		for (tok = vec->begin(); tok != vec->end(); tok++) {
			std::cout << (*tok)->toString();
		}
		std::cout << std::endl;
	}
	std::cout << " --- " << std::endl;
}

void						Lexer::clearList(void) {
	std::list<std::vector<IToken *>>::iterator	vec;
	std::vector<IToken *>::iterator				tok;

	for (vec=this->input_list.begin(); vec !=this->input_list.end(); vec++) {
		for (tok = vec->begin(); tok != vec->end(); tok++) {
			delete *tok;
		}
	}
	this->input_list = std::list<std::vector<IToken *>>();
}

std::vector<IToken *>	Lexer::tokenize(std::stringstream & ss) const {
	std::string				input_buf;
	eOperationType			opType;
	std::vector<IToken *>	vec = std::vector<IToken *>();
	std::smatch				grps;

	while (ss >> input_buf) {
		opType = TokenOperation::stringToOpType(input_buf);
		if (opType != eOperationType::Invalid) {
			vec.push_back(new TokenOperation(opType));
		} else {
			if (std::regex_search(input_buf, grps, Lexer::regex_orand)) {
				for (size_t i = 1; i < grps.size(); i++) {
					std::cout << grps[i] << ";";
				}
				std::cout << std::endl;
			} else {
				vec.push_back(new TokenError(input_buf));
			}
		}
	}
	return vec;
}

IOperand const *		Lexer::createOperand( eOperandType type, \
						std::string const& value ) const {
	if (type < 0 || type >= Lexer::nb_orand_type) {
		return NULL;
	}
	return (this->*create_tab[type])(value);
}
IOperand const *		Lexer::createInt8(std::string const& value) const {
	(void)value;
	return NULL;
}
IOperand const *		Lexer::createInt16(std::string const& value) const {
	(void)value;
	return NULL;
}
IOperand const *		Lexer::createInt32(std::string const& value) const {
	(void)value;
	return NULL;
}
IOperand const *	Lexer::createFloat(std::string const& value) const {
	(void)value;
	return NULL;
}
IOperand const *		Lexer::createDouble(std::string const& value) const {
	(void)value;
	return NULL;
}