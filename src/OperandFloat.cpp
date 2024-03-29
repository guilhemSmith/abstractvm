/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/12 11:10:48 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cfenv>
#include <limits>
#include "OperandFloat.hpp"
#include "OperandDouble.hpp"
#include "errors.hpp"

OperandFloat const	OperandFloat::negate = OperandFloat(-1, "-1");
OperandFloat const	OperandFloat::reverse = OperandFloat(1, "1");
IOperand const *	OperandFloat::reverseFloat[] = {
	&OperandDouble::reverse,
};

OperandFloat::OperandFloat(float value, std::string const str): \
					value(value), str(str) {}
OperandFloat::~OperandFloat(void) {}
OperandFloat::OperandFloat(OperandFloat const & rhs): \
					value(rhs.value), str(rhs.str) {} 

int					OperandFloat::getPrecision(void) const {
	return (int)eOperandType::Float;
}
eOperandType		OperandFloat::getType(void) const {
	return eOperandType::Float;
}

IOperand const *	OperandFloat::operator+( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Float) {
		float				othr = stold(rhs.toString());
		if ((this->value > 0 \
				&& othr > std::numeric_limits<float>::max() - this->value) \
			|| (this->value < 0 \
				&& othr < std::numeric_limits<float>::lowest() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		std::feclearexcept(FE_ALL_EXCEPT);
		float				val = this->value + othr;
		if (std::fetestexcept(FE_UNDERFLOW)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandFloat(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandFloat::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Float) {
		float				othr = stold(rhs.toString());
		if ((this->value > 0 \
				&& -othr > std::numeric_limits<float>::max() - this->value) \
			|| (this->value < 0 \
				&& -othr < std::numeric_limits<float>::lowest() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		std::feclearexcept(FE_ALL_EXCEPT);
		float				val = this->value - othr;
		if (std::fetestexcept(FE_UNDERFLOW)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandFloat(val, std::to_string(val));
	} else {
		result = rhs - *this; 
		result = *result * OperandFloat::negate;
	}
	return result;
}
IOperand const *	OperandFloat::operator*( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Float) {
		float				othr = stold(rhs.toString());
		if (this->value > std::numeric_limits<float>::max() / othr \
			|| this->value < std::numeric_limits<float>::lowest() / othr) {
			throw OverUnderFlow(true, eOperandType::Float);
		}
		std::feclearexcept(FE_ALL_EXCEPT);
		float				val = this->value * othr;
		if (std::fetestexcept(FE_UNDERFLOW)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandFloat(val, std::to_string(val));
	} else {
		result = rhs * *this;
	}
	return result;
}
IOperand const *	OperandFloat::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Float) {
		float				othr = stold(rhs.toString());
		if (!std::isnormal(othr)) {
			throw DivModByZero(true);
		}
		std::feclearexcept(FE_ALL_EXCEPT);
		float				val = this->value / othr;
		if (std::fetestexcept(FE_UNDERFLOW)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandFloat(val, std::to_string(val));
	} else {
		result = *(OperandFloat::reverseFloat[rhs.getPrecision() \
				- eOperandType::Double]) * *this;
		result = *result / rhs;
	}
	return result;
}
IOperand const *	OperandFloat::operator%( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Float) {
		float				othr = stold(rhs.toString());
		if (!std::isnormal(othr)) {
			throw DivModByZero(false);
		}
		std::feclearexcept(FE_ALL_EXCEPT);
		float				val = std::fmod(this->value, othr);
		if (std::fetestexcept(FE_UNDERFLOW)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandFloat(val, std::to_string(val));
	} else {
		result = *(OperandFloat::reverseFloat[rhs.getType() \
				- eOperandType::Double]) * *this;
		result = *result % rhs;
	}
	return result;
}

std::string const &	OperandFloat::toString(void) const {
	return this->str;
}