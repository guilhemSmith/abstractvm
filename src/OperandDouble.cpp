/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/04 13:41:33 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandDouble.hpp"

OperandDouble::OperandDouble(double value, std::string const str): \
					value(value), str(str) {}
OperandDouble::~OperandDouble(void) {}

int					OperandDouble::getPrecision(void) const {
	return 5;
}
eOperandType		OperandDouble::getType(void) const {
	return eOperandType::Double;
}

IOperand const *	OperandDouble::operator+( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandDouble::operator-( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandDouble::operator*( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandDouble::operator/( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandDouble::operator%( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}

std::string const &	OperandDouble::toString(void) const {
	return this->str;
}