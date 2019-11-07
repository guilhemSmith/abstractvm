/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 10:29:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenValue.hpp"

std::string const	TokenValue::operandTypeToString[] = {
	"int8",
	"int16",
	"int32",
	"float",
	"double",
};

TokenValue::TokenValue(IOperand const * operand): operand(operand) {}

TokenValue::~TokenValue(void) {
	delete this->operand;
}

TokenValue::TokenValue(TokenValue const & rhs): operand(rhs.operand) {}

TokenValue &		TokenValue::operator=(TokenValue const & rhs) {
	this->operand = rhs.operand;
	return *this;
}

IOperand const *	TokenValue::getOperand(void) const {
	return this->operand;
}

eTokenType			TokenValue::getType(void) const {
	return eTokenType::Value;
}

std::string 		TokenValue::toString(void) const {
	std::stringstream	ss;

	ss << TokenValue::operandTypeToString[this->operand->getType()] << '(' \
		<< this->operand->toString() << ')';
	return ss.str();
}