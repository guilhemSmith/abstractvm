/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 12:32:29 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenValue.hpp"

TokenValue::TokenValue(IOperand * operand): operand(operand) {}

TokenValue::~TokenValue(void) {}

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