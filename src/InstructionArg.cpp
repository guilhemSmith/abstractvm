/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionArg.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 16:07:13 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionArg.hpp"

InstructionArg::InstructionArg \
					(eOperationType const type, IOperand const * argument): \
					type(type), argument(argument) {

}
InstructionArg::~InstructionArg(void) {}

void				InstructionArg::activate(void) const \
						throw(AbstractVM::AbstractVMException) {
	
}

eInstructionType	InstructionArg::getType(void) const {
	return eInstructionType::Argument;
}

std::string			InstructionArg::toString(void) const {
	std::stringstream	ss;

	ss << TokenOperation::opTypeToString(this->type) << ' ' \
		<< this->argument->toString();
	return ss.str();
}