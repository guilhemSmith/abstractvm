/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 15:52:52 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "OperandInt8.hpp"
#include "OperandInt16.hpp"
#include "OperandInt32.hpp"
#include "OperandFloat.hpp"
#include "OperandDouble.hpp"
#include "errors.hpp"

OperandInt8 const	OperandInt8::negate = OperandInt8(-1, "-1");
IOperand const *	OperandInt8::reverse8[] = {
	&OperandInt16::reverse,
	&OperandInt32::reverse,
	&OperandFloat::reverse,
	&OperandDouble::reverse,
};

OperandInt8::OperandInt8(int8_t value, std::string const str): \
					value(value), str(str) {}
OperandInt8::~OperandInt8(void) {}
OperandInt8::OperandInt8(OperandInt8 const & rhs): \
					value(rhs.value), str(rhs.str) {} 

int					OperandInt8::getPrecision(void) const {
	return (int)eOperandType::Int8;
}
eOperandType		OperandInt8::getType(void) const {
	return eOperandType::Int8;
}

IOperand const *	OperandInt8::operator+( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				othr = stoi(rhs.toString());
		if ((this->value > 0 \
				&& othr > std::numeric_limits<int8_t>::max() - this->value) \
			|| (this->value < 0 \
				&& othr < std::numeric_limits<int8_t>::min() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int8_t				val = this->value + othr;
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandInt8::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				othr = stoi(rhs.toString());
		if ((this->value > 0 \
				&& -othr > std::numeric_limits<int8_t>::max() - this->value) \
			|| (this->value < 0 \
				&& -othr < std::numeric_limits<int8_t>::min() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int8_t				val = this->value - othr;
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = rhs - *this; 
		result = *result * OperandInt8::negate;
	}
	return result;
}
IOperand const *	OperandInt8::operator*( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				othr = stoi(rhs.toString());
		if (this->value > std::numeric_limits<int8_t>::max() / othr \
			|| this->value < std::numeric_limits<int8_t>::min() / othr) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int8_t				val = this->value * othr;
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = rhs * *this;
	}
	return result;
}
IOperand const *	OperandInt8::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				othr = stoi(rhs.toString());
		if (othr == 0) {
			throw DivModByZero(true);
		}
		int8_t				val = this->value / othr;
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = *(OperandInt8::reverse8[rhs.getType() \
				- eOperandType::Int16]) * *this;
		result = *result / rhs;
	}
	return result;
}
IOperand const *	OperandInt8::operator%( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				othr = stoi(rhs.toString());
		if (othr == 0) {
			throw DivModByZero(false);
		}
		int8_t				val = this->value % othr;
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = *(OperandInt8::reverse8[rhs.getType() \
				- eOperandType::Int16]) * *this;
		result = *result % rhs;
	}
	return result;
}

std::string const &	OperandInt8::toString(void) const {
	return this->str;
}

char				OperandInt8::getChar(void) const {
	return (char)this->value;
}