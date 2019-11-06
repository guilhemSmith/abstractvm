/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenError.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 11:46:06 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "TokenError.hpp"

TokenError::TokenError(eTokenErrorType type, std::string input_value): \
					type(type), input_value(input_value) {}

TokenError::~TokenError(void) {}

TokenError::TokenError(TokenError const & rhs): input_value(rhs.input_value) {}

TokenError &		TokenError::operator=(TokenError const & rhs) {
	this->input_value = rhs.input_value;
	return *this;
}

std::string const	TokenError::getErrorMessage(void) const {
	std::stringstream	ss;

	if (this->type == ErrValue) {
		ss << "This type can't match its value" ;
	} else if (this->type == ErrValueType) {
		ss << "This type is unknown";
	} else {
		ss << "This instruction is not recognized";
	}
	ss << ": '" << this->input_value << "'";
	return ss.str();
}

eTokenType			TokenError::getType(void) const {
	return eTokenType::Error;
}

std::string 		TokenError::toString(void) const {
	return this->input_value;
}