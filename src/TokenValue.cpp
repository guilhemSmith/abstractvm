/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 18:06:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenValue.hpp"

TokenValue::TokenValue(std::string input_value): input_value(input_value) {}

TokenValue::~TokenValue(void) {}

TokenValue::TokenValue(TokenValue const & rhs): input_value(rhs.input_value) {}

TokenValue &	TokenValue::operator=(TokenValue const & rhs) {
	this->input_value = rhs.input_value;
	return *this;
}

eTokenType			TokenValue::getType(void) const {
	return eTokenType::Value;
}

std::string 		TokenValue::toString(void) const {
	std::string		output;
	output += "[val:'";
	output += this->input_value;
	output += "']";
	return output;
}