/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/19 15:05:05 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenValue.hpp"

TokenValue::TokenValue(IOperand const * operand): operand(operand) {}

TokenValue::~TokenValue(void) {
	delete this->operand;
}

TokenValue::TokenValue(TokenValue const & rhs): operand(rhs.operand) {}

TokenValue &	TokenValue::operator=(TokenValue const & rhs) {
	this->operand = rhs.operand;
	return *this;
}

eTokenType			TokenValue::getType(void) const {
	return eTokenType::Value;
}

std::string 		TokenValue::toString(void) const {
	std::string		output;
	output += "[val:'";
	output += this->operand->toString();
	output += "']";
	return output;
}