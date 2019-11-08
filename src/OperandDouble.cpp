/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 16:41:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <limits>
#include "OperandDouble.hpp"
#include "errors.hpp"

OperandDouble const	OperandDouble::negate = OperandDouble(-1, "-1");
OperandDouble const	OperandDouble::reverse = OperandDouble(1, "1");

OperandDouble::OperandDouble(double value, std::string const str): \
					value(value), str(str) {}
OperandDouble::~OperandDouble(void) {}
OperandDouble::OperandDouble(OperandDouble const & rhs): \
					value(rhs.value), str(rhs.str) {}

int					OperandDouble::getPrecision(void) const {
	return 5;
}
eOperandType		OperandDouble::getType(void) const {
	return eOperandType::Double;
}

IOperand const *	OperandDouble::operator+( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Double) {
		double				othr = stol(rhs.toString());
		if ((this->value > 0 \
				&& othr > std::numeric_limits<double>::max() - this->value) \
			|| (this->value < 0 \
				&& othr < std::numeric_limits<double>::lowest() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		double				val = this->value + othr;
		if (!std::isnormal(val)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandDouble(val, std::to_string(val));
	} else {
		result = rhs + *this;
	}
	return result;
}
IOperand const *	OperandDouble::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Double) {
		double				othr = stol(rhs.toString());
		if ((this->value > 0 \
				&& -othr > std::numeric_limits<double>::max() - this->value) \
			|| (this->value < 0 \
				&& -othr < std::numeric_limits<double>::lowest() - this->value)) {
			throw OverUnderFlow(true, eOperandType::Int8);
		}
		double				val = this->value - othr;
		if (!std::isnormal(val)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandDouble(val, std::to_string(val));
	} else {
		result = rhs - *this; 
		result = *result * OperandDouble::negate;
	}
	return result;
}
IOperand const *	OperandDouble::operator*( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Double) {
		double				othr = stol(rhs.toString());
		if (this->value > std::numeric_limits<double>::max() / othr \
			|| this->value < std::numeric_limits<double>::lowest() / othr) {
			throw OverUnderFlow(true, eOperandType::Double);
		}
		double				val = this->value * othr;
		if (!std::isnormal(val)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandDouble(val, std::to_string(val));
	} else {
		result = rhs * *this;
	}
	return result;
}
IOperand const *	OperandDouble::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Double) {
		double				othr = stol(rhs.toString());
		if (!std::isnormal(othr)) {
			throw DivModByZero(true);
		}
		double				val = this->value / othr;
		if (!std::isnormal(val)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandDouble(val, std::to_string(val));
	} else {
		return NULL;
	}
	return result;
}
IOperand const *	OperandDouble::operator%( IOperand const& rhs ) const {
	IOperand const *	result;

	if (rhs.getPrecision() <= (int)eOperandType::Double) {
		double				othr = stol(rhs.toString());
		if (!std::isnormal(othr)) {
			throw DivModByZero(false);
		}
		double				val = std::fmod(this->value, othr);
		if (!std::isnormal(val)) {
			throw OverUnderFlow(false, eOperandType::Float);
		}
		result = new OperandDouble(val, std::to_string(val));
	} else {
		return NULL;
	}
	return result;
}

std::string const &	OperandDouble::toString(void) const {
	return this->str;
}