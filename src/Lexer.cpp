/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:06:35 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 13:36:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "Lexer.hpp"
#include "TokenOperation.hpp"
#include "TokenError.hpp"
#include "TokenValue.hpp"

Lexer::Lexer(void) {}

Lexer::~Lexer(void) {}

void	Lexer::readInput(std::istream & input_src) throw() {
	std::string							input_buf;
	std::stringstream					ss;
	eOperationType						opType;
	bool								run = true;

	while (run) {
		std::getline(input_src, input_buf);
		if (input_src.bad() || input_src.eof()) {
			run = false;
			continue;
		}
		std::vector<IToken *>	vec = std::vector<IToken *>();
		ss = std::stringstream(input_buf);
		while (ss >> input_buf) {
			opType = TokenOperation::stringToOpType(input_buf);
			if (opType != eOperationType::Invalid) {
				vec.push_back(new TokenOperation(opType));
			} else {
				vec.push_back(new TokenError(input_buf));
			}
		}
		if (vec.size() > 0) {
			this->input_list.push_back(vec);
		}
	}
}

void	Lexer::printList(void) const {
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

void	Lexer::clearList(void) {
	std::list<std::vector<IToken *>>::iterator	vec;
	std::vector<IToken *>::iterator				tok;

	for (vec=this->input_list.begin(); vec !=this->input_list.end(); vec++) {
		for (tok = vec->begin(); tok != vec->end(); tok++) {
			delete *tok;
		}
	}
	this->input_list = std::list<std::vector<IToken *>>();
}