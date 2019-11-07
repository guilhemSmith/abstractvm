/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionArg.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 11:03:53 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionArg.hpp"
#include "TokenValue.hpp"

InstructionArg::tInstrSelect const		InstructionArg::select[] = {
	&InstructionArg::instrPush,
	&InstructionArg::instrAssert,
};

InstructionArg::InstructionArg \
					(eOperationType const type, IOperand const * argument): \
					type(type), argument(argument) {

}
InstructionArg::~InstructionArg(void) {}

void				InstructionArg::run(std::list<IOperand const *> & mem, \
							bool & exit) \
						const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	(this->*select[this->type])(mem);
}

eInstructionType	InstructionArg::getType(void) const {
	return eInstructionType::Argument;
}

std::string			InstructionArg::toString(void) const {
	std::stringstream	ss;

	ss << TokenOperation::opTypeToString(this->type) << ' ' \
		<< TokenValue::operandTypeToString[this->argument->getType()] << '(' \
		<< this->argument->toString() << ')';
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
	std::cout << "to implement: Assert" << std::endl; 
}