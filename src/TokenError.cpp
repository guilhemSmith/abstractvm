/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenError.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/19 16:45:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenError.hpp"

TokenError::TokenError(eTokenErrorType type, std::string input_value): \
					type(type), input_value(input_value) {}

TokenError::~TokenError(void) {}

TokenError::TokenError(TokenError const & rhs): input_value(rhs.input_value) {}

TokenError &		TokenError::operator=(TokenError const & rhs) {
	this->input_value = rhs.input_value;
	return *this;
}

eTokenType			TokenError::getType(void) const {
	return eTokenType::Error;
}

std::string 		TokenError::toString(void) const {
	std::string		output;
	output += "[err:(";
	if (this->type == ErrValue) {
		output += "value";
	} else if (this->type == ErrValueType) {
		output += "valueType";
	} else {
		output += "token";
	}
	output += ")'";
	output += this->input_value;
	output += "']";
	return output;
}