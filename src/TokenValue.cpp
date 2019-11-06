/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 15:17:55 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenValue.hpp"

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
	return this->operand->toString();
}