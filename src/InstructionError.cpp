/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionError.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:16:34 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 15:55:21 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionError.hpp"

InstructionError::InstructionError \
					(std::string str, eInstructionErrorType type): \
					instruction(str), type(type) {}
InstructionError::~InstructionError(void) {}

std::string const	InstructionError::getErrorMessage(void) const {
	std::stringstream	ss;

	ss << "'" << this->instruction << "': ";
	if (this->type == TooManyArg) {
		ss << "Too many arguments given." ;
	} else if (this->type == MissingArg) {
		ss << "this instruction need an argument.";
	} else {
		ss << "This instruction is not valid.";
	}
	return ss.str();
}

void				InstructionError::activate(void) const \
								throw(AbstractVM::AbstractVMException) {}

eInstructionType	InstructionError::getType(void) const {
	return eInstructionType::InstError;
}

std::string			InstructionError::toString(void) const {
	std::stringstream	ss;

	ss << "{err:(";
	if (this->type == TooManyArg) {
		ss << "tooManyArg";
	} else if (this->type == MissingArg) {
		ss << "missingArg";
	} else {
		ss << "incorrectInstr";
	}
	ss << ")'" << this->instruction << "'}";
	return ss.str();
}