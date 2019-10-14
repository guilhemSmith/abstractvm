/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 16:33:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandInt8.hpp"

OperandInt8::OperandInt8(int8_t value, std::string const & str): \
					value(value), str(str) {}
OperandInt8::~OperandInt8(void) {}

int					OperandInt8::getPrecision(void) const {
	return 1;
}
eOperandType		OperandInt8::getType(void) const {
	return eOperandType::Int8;
}

IOperand const *	OperandInt8::operator+( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt8::operator-( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt8::operator*( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt8::operator/( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt8::operator%( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}

std::string const &	OperandInt8::toString(void) const {
	return this->str;
}