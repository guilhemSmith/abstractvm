/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:50:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 13:13:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "errors.hpp"
#include "TokenValue.hpp"


LexerFail::LexerFail(std::vector<std::tuple<int, std::string>> errors) \
							throw() {
	std::stringstream	ss;

	ss << "Lexer failed: " << errors.size() << " lexical error(s)." << std::endl;
	for (auto error : errors) {
		ss << "instruction " << std::get<0>(error) << ": " \
			<< std::get<1>(error) << std::endl;
	}
	this->message = ss.str();
}

LexerFail::LexerFail(const LexerFail &rhs) throw() {
	this->message = rhs.message;
}

LexerFail::~LexerFail(void) throw() {}

ParserFail::ParserFail(std::vector<std::tuple<int, std::string>> errors) \
							throw() {
	std::stringstream	ss;

	ss << "Parser failed: " << errors.size() << " syntactic error(s)." << std::endl;
	for (auto error : errors) {
		ss << "instruction " << std::get<0>(error) << ": " \
			<< std::get<1>(error) << std::endl;
	}
	this->message = ss.str();
}

ParserFail::ParserFail(const ParserFail &rhs) throw() {
	this->message = rhs.message;
}

ParserFail::~ParserFail(void) throw() {}

IncorrectExit::IncorrectExit(bool missing) throw() {
	if (missing) {
		this->message = "Execution ended without an Exit instruction.";
	} else {
		this->message = "Exit called before the last instruction.";
	}
}

IncorrectExit::IncorrectExit(const IncorrectExit &rhs) throw() {
	this->message = rhs.message;
}

IncorrectExit::~IncorrectExit(void) throw() {}

AssertFail::AssertFail(IOperand const * expected, \
						IOperand const * real) throw() {
	std::stringstream	ss;

	ss << "Assert failed: expected '" \
		<< TokenValue::operandTypeToString[expected->getType()] << '(' \
		<< expected->toString() << ")', ";
	if (real != NULL) {
		ss << "found '" << TokenValue::operandTypeToString[real->getType()] \
			<< '(' << real->toString() << ")'.";
	} else {
		ss << "but the memory was empty.";
	}
	this->message = ss.str();
}

AssertFail::AssertFail(const AssertFail &rhs) throw() {
	this->message = rhs.message;
}

AssertFail::~AssertFail(void) throw() {}