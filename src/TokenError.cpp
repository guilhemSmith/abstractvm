/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenError.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/12 12:05:55 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "TokenError.hpp"

std::string const	TokenError::errString[] = {
	"This word is not recognized",
	"This type is unknown",
	"This value is invalid",
	"This value overflow its type",
};

TokenError::TokenError(eTokenErrorType type, std::string input_value): \
					type(type), input_value(input_value) {}

TokenError::~TokenError(void) {}

TokenError::TokenError(TokenError const & rhs): input_value(rhs.input_value) {}

TokenError &		TokenError::operator=(TokenError const & rhs) {
	this->input_value = rhs.input_value;
	return *this;
}

std::string const	TokenError::getErrorMessage(void) const {
	std::string		out;

	out = TokenError::errString[this->type] + ": '" + this->input_value + '\'';
	return out;
}

eTokenType			TokenError::getType(void) const {
	return eTokenType::Error;
}

std::string 		TokenError::toString(void) const {
	return this->input_value;
}