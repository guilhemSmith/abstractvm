/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/12 11:06:51 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cfenv>
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
	return (int)eOperandType::Double;
}
eOperandType		OperandDouble::getType(void) const {
	return eOperandType::Double;
}

IOperand const *	OperandDouble::operator+( IOperand const& rhs ) const {
	IOperand const *	result;

	double				othr = stold(rhs.toString());
	if ((this->value > 0 \
			&& othr > std::numeric_limits<double>::max() - this->value) \
		|| (this->value < 0 \
			&& othr < std::numeric_limits<double>::lowest() - this->value)) {
		throw OverUnderFlow(true, eOperandType::Int8);
	}
	std::feclearexcept(FE_ALL_EXCEPT);
	double				val = this->value + othr;
	if (std::fetestexcept(FE_UNDERFLOW)) {
		throw OverUnderFlow(false, eOperandType::Float);
	}
	result = new OperandDouble(val, std::to_string(val));
	return result;
}
IOperand const *	OperandDouble::operator-( IOperand const& rhs ) const {
	IOperand const *	result;

	double				othr = stold(rhs.toString());
	if ((this->value > 0 \
			&& -othr > std::numeric_limits<double>::max() - this->value) \
		|| (this->value < 0 \
			&& -othr < std::numeric_limits<double>::lowest() - this->value)) {
		throw OverUnderFlow(true, eOperandType::Int8);
	}
	std::feclearexcept(FE_ALL_EXCEPT);
	double				val = this->value - othr;
	if (std::fetestexcept(FE_UNDERFLOW)) {
		throw OverUnderFlow(false, eOperandType::Float);
	}
	result = new OperandDouble(val, std::to_string(val));
	return result;
}
IOperand const *	OperandDouble::operator*( IOperand const& rhs ) const {
	IOperand const *	result;

	double				othr = stold(rhs.toString());
	if (this->value > std::numeric_limits<double>::max() / othr \
		|| this->value < std::numeric_limits<double>::lowest() / othr) {
		throw OverUnderFlow(true, eOperandType::Double);
	}
	std::feclearexcept(FE_ALL_EXCEPT);
	double				val = this->value * othr;
	if (std::fetestexcept(FE_UNDERFLOW)) {
		throw OverUnderFlow(false, eOperandType::Float);
	}
	result = new OperandDouble(val, std::to_string(val));
	return result;
}
IOperand const *	OperandDouble::operator/( IOperand const& rhs ) const {
	IOperand const *	result;

	double				othr = stold(rhs.toString());
	if (!std::isnormal(othr)) {
		throw DivModByZero(true);
	}
	std::feclearexcept(FE_ALL_EXCEPT);
	double				val = this->value / othr;
	if (std::fetestexcept(FE_UNDERFLOW)) {
		throw OverUnderFlow(false, eOperandType::Float);
	}
	result = new OperandDouble(val, std::to_string(val));
	return result;
}
IOperand const *	OperandDouble::operator%( IOperand const& rhs ) const {
	IOperand const *	result;

	double				othr = stold(rhs.toString());
	if (!std::isnormal(othr)) {
		throw DivModByZero(false);
	}
	std::feclearexcept(FE_ALL_EXCEPT);
	double				val = std::fmod(this->value, othr);
	if (std::fetestexcept(FE_UNDERFLOW)) {
		throw OverUnderFlow(false, eOperandType::Float);
	}
	result = new OperandDouble(val, std::to_string(val));
	return result;
}

std::string const &	OperandDouble::toString(void) const {
	return this->str;
}