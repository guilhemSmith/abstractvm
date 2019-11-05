/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:45:07 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/05 14:02:08 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"
#include "OperandInt8.hpp"
#include "OperandInt16.hpp"
#include "OperandInt32.hpp"
#include "OperandFloat.hpp"
#include "OperandDouble.hpp"


OperandFactory::OperandFactory(void) {}
OperandFactory::~OperandFactory(void) {}

OperandFactory::tOrandCreate const		OperandFactory::create_tab[] = {
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble,
};

IOperand const *		OperandFactory::createOperand \
							(eOperandType type, std::string const & val) const {
	if (type < 0 || type >= OperandFactory::nb_orand_type) {
		return NULL;
	}
	return (this->*create_tab[type])(val);
}
IOperand const *		OperandFactory::createInt8 \
							(std::string const& val) const {
	long double	large_val;
	int8_t		smoll_val;

	try {
		large_val = stol(val);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_val = (int8_t)large_val;
	if (large_val != smoll_val) {
		return NULL;
	}
	if (val[0] == '+') {
		return new OperandInt8(smoll_val, val.substr(1));
	}
	return new OperandInt8(smoll_val, val);
}
IOperand const *		OperandFactory::createInt16 \
							(std::string const& value) const {
	long double	large_value;
	int16_t		smoll_value;

	try {
		large_value = stol(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (int16_t)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandInt16(smoll_value, value.substr(1));
	}
	return new OperandInt16(smoll_value, value);
}
IOperand const *		OperandFactory::createInt32 \
							(std::string const& value) const {
	long double	large_value;
	int32_t		smoll_value;

	try {
		large_value = stod(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (int32_t)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandInt32(smoll_value, value.substr(1));
	}
	return new OperandInt32(smoll_value, value);
}
IOperand const *		OperandFactory::createFloat \
							(std::string const& value) const {
	long double	large_value;
	float		smoll_value;

	try {
		large_value = stod(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (float)large_value;
	if (large_value / smoll_value == 1) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandFloat(smoll_value, value.substr(1));
	}
	return new OperandFloat(smoll_value, value);
}
IOperand const *		OperandFactory::createDouble \
							(std::string const& value) const {
	long double	large_value;
	double		smoll_value;

	try {
		large_value = stod(value);
	} catch (std::exception e) {
		return NULL;
	}
	smoll_value = (double)large_value;
	if (large_value != smoll_value) {
		return NULL;
	}
	if (value[0] == '+') {
		return new OperandDouble(smoll_value, value.substr(1));
	}
	return new OperandDouble(smoll_value, value);
}
