/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:12:50 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 10:17:18 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandInt16.hpp"

OperandInt16::OperandInt16(int16_t value, std::string const str): \
					value(value), str(str) {}
OperandInt16::~OperandInt16(void) {}
OperandInt16::OperandInt16(OperandInt16 const & rhs): \
					value(rhs.value), str(rhs.str) {} 

int					OperandInt16::getPrecision(void) const {
	return 2;
}
eOperandType		OperandInt16::getType(void) const {
	return eOperandType::Int16;
}

IOperand const *	OperandInt16::operator+( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt16::operator-( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt16::operator*( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt16::operator/( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}
IOperand const *	OperandInt16::operator%( IOperand const& rhs ) const {
	(void)rhs;
	return this;
}

std::string const &	OperandInt16::toString(void) const {
	return this->str;
}