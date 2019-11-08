/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 10:40:52 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandInt16.hpp"
#include "errors.hpp"

OperandInt16 const	OperandInt16::negate = OperandInt16(-1, "-1");

OperandInt16::OperandInt16(int16_t value, std::string const str): \
					value(value), str(str) {}
OperandInt16::~OperandInt16(void) {}
OperandInt16::OperandInt16(OperandInt16 const & rhs): \
					value(rhs.value), str(rhs.str) {} 

int					OperandInt16::getPrecision(void) const {
	return (int)eOperandType::Int16;
}
eOperandType		OperandInt16::getType(void) const {
	return eOperandType::Int16;
}

IOperand const *	OperandInt16::operator+( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int16) {
		int16_t				other = stoi(rhs.toString());
		int16_t				val = this->value + other;
		if ((this->value > 0 && other > 0 && val < 0) \
			|| (this->value < 0 && other < 0 && val > 0)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandInt16::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int16) {
		int16_t				other = stoi(rhs.toString());
		int16_t				val = this->value - other;
		if ((this->value > 0 && other < 0 && val < 0) \
			|| (this->value < 0 && other > 0 && val > 0)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = rhs - *this; 
		result = *result * OperandInt16::negate;
	}
	return result;
}
IOperand const *	OperandInt16::operator*( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt16::operator/( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt16::operator%( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}

std::string const &	OperandInt16::toString(void) const {
	return this->str;
}