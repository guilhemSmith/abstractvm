/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenError.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 18:07:56 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenError.hpp"

TokenError::TokenError(std::string input_value): input_value(input_value) {}

TokenError::~TokenError(void) {}

TokenError::TokenError(TokenError const & rhs): input_value(rhs.input_value) {}

TokenError &	TokenError::operator=(TokenError const & rhs) {
	this->input_value = rhs.input_value;
	return *this;
}

eTokenType			TokenError::getType(void) const {
	return eTokenType::Error;
}

std::string 		TokenError::toString(void) const {
	std::string		output;
	output += "[err:'";
	output += this->input_value;
	output += "']";
	return output;
}