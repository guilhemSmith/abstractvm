/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenOperation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/05 18:37:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenOperation.hpp"

std::string const	TokenOperation::type_string_tab[] = {
	"push",
	"pop",
	"dump",
	"assert",
	"add",
	"sub",
	"Mul",
	"div",
	"mod",
	"print",
	"exit",
};

TokenOperation::TokenOperation(eOperationType type): type(type) {}

TokenOperation::~TokenOperation(void) {}

TokenOperation::TokenOperation(TokenOperation const & rhs): type(rhs.type) {}

TokenOperation &	TokenOperation::operator=(TokenOperation const & rhs) {
	this->type = rhs.type;
	return *this;
}

eOperationType		TokenOperation::getOperationType(void) const {
	return this->type;
}

bool				TokenOperation::expectArg(void) const {
	return this->type == eOperationType::Push \
		|| this->type == eOperationType::Assert; 
}

eTokenType			TokenOperation::getType(void) const {
	return eTokenType::Operation;
}

std::string 		TokenOperation::toString(void) const {
	std::string		output;
	output += "[ope:'";
	output += TokenOperation::opTypeToString(this->type);
	output += "']";
	return output;
}

std::string			TokenOperation::opTypeToString(eOperationType const & type) {
	int		i = -1;
	while (++i < TokenOperation::nb_type) {
		if (type == i) {
			return TokenOperation::type_string_tab[i];
		}
	}
	return "???";
}

eOperationType		TokenOperation::stringToOpType(std::string const & str) {
	int		i = -1;
	while (++i < TokenOperation::nb_type) {
		if (str == TokenOperation::type_string_tab[i]) {
			return (eOperationType)i;
		}
	}
	return eOperationType::Invalid;
}