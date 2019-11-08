/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:54:58 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 15:50:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDDOUBLE_HPP
# define OPERANDDOUBLE_HPP

# include "IOperand.hpp"

class OperandDouble: public IOperand {
	
public:
	OperandDouble(double value, std::string const str);
	virtual						~OperandDouble(void);
	OperandDouble(OperandDouble const & rhs);

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;

	virtual IOperand const *	operator+( IOperand const& rhs ) const;
	virtual IOperand const *	operator-( IOperand const& rhs ) const;
	virtual IOperand const *	operator*( IOperand const& rhs ) const;
	virtual IOperand const *	operator/( IOperand const& rhs ) const;
	virtual IOperand const *	operator%( IOperand const& rhs ) const;

	virtual std::string const &	toString(void) const;

	static OperandDouble const	reverse;

private:
	OperandDouble(void);
	OperandDouble& 				operator=(OperandDouble const & rhs);

	double						value;
	std::string const			str;

	static OperandDouble const	negate;
};

#endif