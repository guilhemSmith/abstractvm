/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenOperation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:31:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 11:38:33 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenOperation.hpp"

TokenOperation::tTypeString const	TokenOperation::type_string_tab[] = {
	{eOperationType::Push, "push"},
	{eOperationType::Pop, "pop"},
	{eOperationType::Dump, "dump"},
	{eOperationType::Assert, "assert"},
	{eOperationType::Add, "add"},
	{eOperationType::Sub, "sub"},
	{eOperationType::Mul, "Mul"},
	{eOperationType::Div, "div"},
	{eOperationType::Mod, "mod"},
	{eOperationType::Print, "print"},
	{eOperationType::Exit, "exit"},
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
		if (type == TokenOperation::type_string_tab[i].type) {
			return TokenOperation::type_string_tab[i].str;
		}
	}
	return "???";
}

eOperationType		TokenOperation::stringToOpType(std::string const & str) {
	int		i = -1;
	while (++i < TokenOperation::nb_type) {
		if (str == TokenOperation::type_string_tab[i].str) {
			return TokenOperation::type_string_tab[i].type;
		}
	}
	return eOperationType::Invalid;
}