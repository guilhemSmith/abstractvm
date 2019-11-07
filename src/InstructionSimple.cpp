/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 11:40:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionSimple.hpp"
#include "TokenValue.hpp"

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

void				InstructionSimple::run(std::list<IOperand const *> & mem, \
							bool & exit) \
						const throw(AbstractVM::AbstractVMException) {
	(this->*select[this->type - TokenOperation::last_operation_arg - 1]) \
		(mem, exit);
}

eInstructionType	InstructionSimple::getType(void) const {
	return eInstructionType::Simple;
}

std::string			InstructionSimple::toString(void) const {
	return TokenOperation::opTypeToString(this->type);
}

void						InstructionSimple::instrPop \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)exit;
	mem.pop_back(); 
}
void						InstructionSimple::instrDump \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)exit;
	for (auto value = mem.rbegin(); value != mem.rend(); value++) {
		IOperand const *	val = *value; 
		std::cout << val->toString() << std::endl;
	}
}
void						InstructionSimple::instrAdd \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
	std::cout << "to implement: Add" << std::endl; 
}
void						InstructionSimple::instrSub \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
	std::cout << "to implement: Sub" << std::endl; 
}
void						InstructionSimple::instrMul \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
	std::cout << "to implement: Mul" << std::endl; 
}
void						InstructionSimple::instrDiv \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
	std::cout << "to implement: Div" << std::endl; 
}
void						InstructionSimple::instrMod \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
	std::cout << "to implement: Mod" << std::endl; 
}
void						InstructionSimple::instrPrint \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	(void)exit;
	std::cout << "to implement: Print" << std::endl; 
}
void						InstructionSimple::instrExit \
								(std::list<IOperand const *> & mem, \
									bool & exit) const \
								throw(AbstractVM::AbstractVMException) {
	(void)mem;
	exit = true;
}