/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt32.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 15:25:10 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "OperandInt32.hpp"
#include "errors.hpp"

OperandInt32 const	OperandInt32::negate = OperandInt32(-1, "-1");
OperandInt32 const	OperandInt32::reverse = OperandInt32(1, "1");
IOperand const *	OperandInt32::reverse32[] = {
};

OperandInt32::OperandInt32(int32_t value, std::string const str): \
					value(value), str(str) {}
OperandInt32::~OperandInt32(void) {}
OperandInt32::OperandInt32(OperandInt32 const & rhs): \
					value(rhs.value), str(rhs.str) {} 

int					OperandInt32::getPrecision(void) const {
	return (int)eOperandType::Int32;
}
eOperandType		OperandInt32::getType(void) const {
	return eOperandType::Int32;
}

IOperand const *	OperandInt32::operator+( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int32) {
		int32_t				othr = stoi(rhs.toString());
		if ((this->value > 0 \
				&& othr > std::numeric_limits<int16_t>::max() - this->value) \
			|| (this->value < 0 \
				&& othr < std::numeric_limits<int16_t>::min() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int32_t				val = this->value + othr;
		result = new OperandInt32(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandInt32::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int32) {
		int32_t				othr = stoi(rhs.toString());
		if ((this->value > 0 \
				&& -othr > std::numeric_limits<int16_t>::max() - this->value) \
			|| (this->value < 0 \
				&& -othr < std::numeric_limits<int16_t>::min() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		int32_t				val = this->value - othr;
		result = new OperandInt32(val, std::to_string(val));
	} else {
		result = rhs - *this; 
		result = *result * OperandInt32::negate;
	}
	return result;
}
IOperand const *	OperandInt32::operator*( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int32) {
		int32_t				othr = stoi(rhs.toString());
		int32_t				val = this->value * othr;
		if (this->value > std::numeric_limits<int32_t>::max() / othr \
			|| this->value < std::numeric_limits<int32_t>::min() / othr) {
			throw OverUnderFlow(true, eOperandType::Int32);
		}
		result = new OperandInt32(val, std::to_string(val));
	} else {
		result = rhs * *this;
	}
	return result;
}
IOperand const *	OperandInt32::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int32) {
		int32_t				othr = stoi(rhs.toString());
		if (othr == 0) {
			throw DivModByZero(true);
		}
		int32_t				val = this->value / othr;
		result = new OperandInt32(val, std::to_string(val));
	} else {
		result = *(OperandInt32::reverse32[rhs.getPrecision() \
				- eOperandType::Float]) * *this;
		result = *result / rhs;
	}
	return result;
}
IOperand const *	OperandInt32::operator%( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Int32) {
		int32_t				othr = stoi(rhs.toString());
		if (othr == 0) {
			throw DivModByZero(false);
		}
		int32_t				val = this->value % othr;
		result = new OperandInt32(val, std::to_string(val));
	} else {
		result = *(OperandInt32::reverse32[rhs.getType() \
				- eOperandType::Float]) * *this;
		result = *result % rhs;
	}
	return result;
}

std::string const &	OperandInt32::toString(void) const {
	return this->str;
}