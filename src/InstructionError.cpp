/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionError.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:16:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/12 12:08:44 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionError.hpp"

std::string const	InstructionError::errString[] = {
	"Too many arguments given.",
	"This instruction need an argument.",
	"This instruction is not valid.",
};

InstructionError::InstructionError \
					(std::string str, eInstructionErrorType type): \
					instruction(str), type(type) {}
InstructionError::~InstructionError(void) {}

std::string const	InstructionError::getErrorMessage(void) const {
	std::string		out;

	out = '\'' + this->instruction + "': " \
		+ InstructionError::errString[this->type];
	return out;
}

void				InstructionError::run(std::list<IOperand const *> & mem, \
							bool & exit) \
						throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
}

eInstructionType	InstructionError::getType(void) const {
	return eInstructionType::InstError;
}

std::string			InstructionError::toString(void) const {
	return this->instruction;
}