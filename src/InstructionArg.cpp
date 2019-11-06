/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionArg.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 17:15:39 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionArg.hpp"

InstructionArg::tInstrSelect const		InstructionArg::select[] = {
	&InstructionArg::instrPush,
	&InstructionArg::instrAssert,
};

InstructionArg::InstructionArg \
					(eOperationType const type, IOperand const * argument): \
					type(type), argument(argument) {

}
InstructionArg::~InstructionArg(void) {}

void				InstructionArg::run(std::list<IOperand const *> & mem) \
						const throw(AbstractVM::AbstractVMException) {
	(this->*select[this->type])(mem);
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

void				InstructionArg::instrPush \
						(std::list<IOperand const *> & mem) const \
						throw(AbstractVM::AbstractVMException) {
	mem.push_back(this->argument);
}

void				InstructionArg::instrAssert \
						(std::list<IOperand const *> & mem) const \
						throw(AbstractVM::AbstractVMException) {
	(void)mem;
	std::cout << this->toString() << std::endl;
}