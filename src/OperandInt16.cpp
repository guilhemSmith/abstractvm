/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 15:22:44 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "OperandInt16.hpp"
#include "OperandInt32.hpp"
#include "errors.hpp"

OperandInt16 const	OperandInt16::negate = OperandInt16(-1, "-1");
OperandInt16 const	OperandInt16::reverse = OperandInt16(1, "1");
IOperand const *	OperandInt16::reverse16[] = {
	&OperandInt32::reverse,
};

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
		int16_t				othr = stoi(rhs.toString());
		if ((this->value > 0 \
				&& othr > std::numeric_limits<int16_t>::max() - this->value) \
			|| (this->value < 0 \
				&& othr < std::numeric_limits<int16_t>::min() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int16_t				val = this->value + othr;
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandInt16::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int16) {
		int16_t				othr = stoi(rhs.toString());
		if ((this->value > 0 \
				&& -othr > std::numeric_limits<int16_t>::max() - this->value) \
			|| (this->value < 0 \
				&& -othr < std::numeric_limits<int16_t>::min() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int16_t				val = this->value - othr;
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = rhs - *this; 
		result = *result * OperandInt16::negate;
	}
	return result;
}
IOperand const *	OperandInt16::operator*( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int16) {
		int16_t				othr = stoi(rhs.toString());
		if (this->value > std::numeric_limits<int16_t>::max() / othr \
			|| this->value < std::numeric_limits<int16_t>::min() / othr) {
			throw OverUnderFlow(true, eOperandType::Int16);
		}
		int16_t				val = this->value * othr;
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = rhs * *this;
	}
	return result;
}
IOperand const *	OperandInt16::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int16) {
		int16_t				othr = stoi(rhs.toString());
		if (othr == 0) {
			throw DivModByZero(true);
		}
		int16_t				val = this->value / othr;
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = *(OperandInt16::reverse16[rhs.getType() \
				- eOperandType::Int32]) * *this;
		result = *result / rhs;
	}
	return result;
}
IOperand const *	OperandInt16::operator%( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int16) {
		int16_t				othr = stoi(rhs.toString());
		if (othr == 0) {
			throw DivModByZero(false);
		}
		int16_t				val = this->value % othr;
		result = new OperandInt16(val, std::to_string(val));
	} else {
		result = *(OperandInt16::reverse16[rhs.getType() \
				- eOperandType::Int32]) * *this;
		result = *result % rhs;
	}
	return result;
}

std::string const &	OperandInt16::toString(void) const {
	return this->str;
}