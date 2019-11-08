/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 14:04:52 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandInt8.hpp"
#include "OperandInt16.hpp"
#include "OperandInt32.hpp"
#include "errors.hpp"

OperandInt8 const	OperandInt8::negate = OperandInt8(-1, "-1");
IOperand const *	OperandInt8::reverse8[] = {
	&OperandInt16::reverse,
	&OperandInt32::reverse,
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
		int8_t				other = stoi(rhs.toString());
		int8_t				val = this->value + other;
		if ((this->value > 0 && other > 0 && val < 0) \
			|| (this->value < 0 && other < 0 && val > 0)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandInt8::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				other = stoi(rhs.toString());
		int8_t				val = this->value - other;
		if ((this->value > 0 && other < 0 && val < 0) \
			|| (this->value < 0 && other > 0 && val > 0)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
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
		int8_t				other = stoi(rhs.toString());
		int8_t				val = this->value * other;
		if ((((this->value > 0 && other > 0) \
					|| (this->value < 0 && other < 0)) && val < 0) \
			|| (((this->value > 0 && other < 0) \
					|| (this->value < 0 && other > 0)) && val > 0)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		result = new OperandInt8(val, std::to_string(val));
	} else {
		result = rhs * *this;
	}
	return result;
}
IOperand const *	OperandInt8::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int8) {
		int8_t				other = stoi(rhs.toString());
		if (other == 0) {
			throw DivModByZero(true);
		}
		int8_t				val = this->value / other;
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
		int8_t				other = stoi(rhs.toString());
		if (other == 0) {
			throw DivModByZero(false);
		}
		int8_t				val = this->value % other;
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