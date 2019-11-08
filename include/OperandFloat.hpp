/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:54:58 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 15:49:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFLOAT_HPP
# define OPERANDFLOAT_HPP

# include "IOperand.hpp"

class OperandFloat: public IOperand {
	
public:
	OperandFloat(float value, std::string const str);
	virtual						~OperandFloat(void);
	OperandFloat(OperandFloat const & rhs);

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;

	virtual IOperand const *	operator+( IOperand const& rhs ) const;
	virtual IOperand const *	operator-( IOperand const& rhs ) const;
	virtual IOperand const *	operator*( IOperand const& rhs ) const;
	virtual IOperand const *	operator/( IOperand const& rhs ) const;
	virtual IOperand const *	operator%( IOperand const& rhs ) const;

	virtual std::string const &	toString(void) const;

	static OperandFloat const	reverse;

private:
	OperandFloat(void);
	OperandFloat& 				operator=(OperandFloat const & rhs);

	float						value;
	std::string const			str;

	static OperandFloat const	negate;
	static IOperand const *		reverseFloat[1];
};

#endif