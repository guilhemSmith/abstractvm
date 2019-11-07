/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 10:17:04 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFloat.hpp"

OperandFloat::OperandFloat(float value, std::string const str): \
					value(value), str(str) {}
OperandFloat::~OperandFloat(void) {}
OperandFloat::OperandFloat(OperandFloat const & rhs): \
					value(rhs.value), str(rhs.str) {} 

int					OperandFloat::getPrecision(void) const {
	return 4;
}
eOperandType		OperandFloat::getType(void) const {
	return eOperandType::Float;
}

IOperand const *	OperandFloat::operator+( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandFloat::operator-( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandFloat::operator*( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandFloat::operator/( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandFloat::operator%( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}

std::string const &	OperandFloat::toString(void) const {
	return this->str;
}