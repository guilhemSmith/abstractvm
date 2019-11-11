/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/11 12:11:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionSimple.hpp"
#include "TokenValue.hpp"
#include "OperandInt8.hpp"
#include "errors.hpp"

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

std::tuple<IOperand const *, IOperand const *> \
					InstructionSimple::extractArg \
						(std::list<IOperand const *> & mem)
						throw(NotEnoughValue) {
	if (mem.size() < 2) {
		throw NotEnoughValue();
	}
	IOperand const *	second = mem.front();
	mem.pop_front();
	IOperand const *	first = mem.front();
	mem.pop_front();
	return std::make_tuple(first, second);
}

InstructionSimple::InstructionSimple (eOperationType const type): type(type) {

}
InstructionSimple::~InstructionSimple(void) {}

void				InstructionSimple::run(std::list<IOperand const *> & mem, \
							bool & exit) \
						throw(AbstractVM::AbstractVMException) {
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
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	if (mem.size() == 0) {
		throw PopFail();
	}
	delete mem.front();
	mem.pop_front(); 
}
void						InstructionSimple::instrDump \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	for (auto value: mem) {
		std::cout << value->toString() << std::endl;
	}
}
void						InstructionSimple::instrAdd \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	std::tuple<IOperand const *, IOperand const *>	arguments;
	IOperand const *								result;
	IOperand const *								first;
	IOperand const *								second;
	
	arguments = InstructionSimple::extractArg(mem);
	first = std::get<0>(arguments);
	second = std::get<1>(arguments);
	try {
		result = *first + *second;
	} catch (AbstractVM::AbstractVMException e) {
		delete first;
		delete second;
		throw e;
	}
	mem.push_front(result);
	delete first;
	delete second;
}
void						InstructionSimple::instrSub \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	std::tuple<IOperand const *, IOperand const *>	arguments;
	IOperand const *								result;
	IOperand const *								first;
	IOperand const *								second;
	
	arguments = InstructionSimple::extractArg(mem);
	first = std::get<0>(arguments);
	second = std::get<1>(arguments);
	try {
		result = *first - *second;
	} catch (AbstractVM::AbstractVMException e) {
		delete first;
		delete second;
		throw e;
	}
	mem.push_front(result);
	delete first;
	delete second;
}
void						InstructionSimple::instrMul \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	std::tuple<IOperand const *, IOperand const *>	arguments;
	IOperand const *								result;
	IOperand const *								first;
	IOperand const *								second;
	
	arguments = InstructionSimple::extractArg(mem);
	first = std::get<0>(arguments);
	second = std::get<1>(arguments);
	try {
		result = *first * *second;
	} catch (AbstractVM::AbstractVMException e) {
		delete first;
		delete second;
		throw e;
	}
	mem.push_front(result);
	delete first;
	delete second;
}
void						InstructionSimple::instrDiv \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	std::tuple<IOperand const *, IOperand const *>	arguments;
	IOperand const *								result;
	IOperand const *								first;
	IOperand const *								second;
	
	arguments = InstructionSimple::extractArg(mem);
	first = std::get<0>(arguments);
	second = std::get<1>(arguments);
	try {
		result = *first / *second;
	} catch (AbstractVM::AbstractVMException e) {
		delete first;
		delete second;
		throw e;
	}
	mem.push_front(result);
	delete first;
	delete second;
}
void						InstructionSimple::instrMod \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	std::tuple<IOperand const *, IOperand const *>	arguments;
	IOperand const *								result;
	IOperand const *								first;
	IOperand const *								second;
	
	arguments = InstructionSimple::extractArg(mem);
	first = std::get<0>(arguments);
	second = std::get<1>(arguments);
	try {
		result = *first % *second;
	} catch (AbstractVM::AbstractVMException e) {
		delete first;
		delete second;
		throw e;
	}
	mem.push_front(result);
	delete first;
	delete second;
}
void						InstructionSimple::instrPrint \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)exit;
	OperandInt8 const *	value;

	if (mem.size() == 0) {
		throw PrintFail(false);
	}
	value = dynamic_cast<OperandInt8 const *>(mem.front());
	if (value == NULL) {
		throw PrintFail(true);
	}
	std::cout << value->getChar();
}
void						InstructionSimple::instrExit \
								(std::list<IOperand const *> & mem, \
									bool & exit) \
								const throw(AbstractVM::AbstractVMException) {
	(void)mem;
	exit = true;
}