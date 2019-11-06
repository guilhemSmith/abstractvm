/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 17:33:26 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionSimple.hpp"

InstructionSimple::tInstrSelect const		InstructionSimple::select[] = {
	&InstructionSimple::instrPop,
	&InstructionSimple::instrDump,
	&InstructionSimple::instrAdd,
	&InstructionSimple::instrSub,
	&InstructionSimple::instrMul,
	&InstructionSimple::instrDiv,
	&InstructionSimple::instrMod,
	&InstructionSimple::instrPrint,
	&InstructionSimple::instrExit,
};

InstructionSimple::InstructionSimple (eOperationType const type): type(type) {

}
InstructionSimple::~InstructionSimple(void) {}

void				InstructionSimple::run(std::list<IOperand const *> & mem) \
						const throw(AbstractVM::AbstractVMException) {
	(this->*select[this->type - TokenOperation::last_operation_arg - 1])(mem);
}

eInstructionType	InstructionSimple::getType(void) const {
	return eInstructionType::Simple;
}

std::string			InstructionSimple::toString(void) const {
	return TokenOperation::opTypeToString(this->type);
}

void						InstructionSimple::instrPop \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrDump \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrAdd \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrSub \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrMul \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrDiv \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrMod \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrPrint \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}
void						InstructionSimple::instrExit \
								(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
}