/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:54:58 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 10:30:41 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDINT8_HPP
# define OPERANDINT8_HPP

# include "IOperand.hpp"

class OperandInt8: public IOperand {
	
public:
	OperandInt8(int8_t value, std::string const str);
	virtual						~OperandInt8(void);
	OperandInt8(OperandInt8 const & rhs);

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;

	virtual IOperand const *	operator+( IOperand const& rhs ) const;
	virtual IOperand const *	operator-( IOperand const& rhs ) const;
	virtual IOperand const *	operator*( IOperand const& rhs ) const;
	virtual IOperand const *	operator/( IOperand const& rhs ) const;
	virtual IOperand const *	operator%( IOperand const& rhs ) const;

	virtual std::string const &	toString(void) const;
	char						getChar(void) const;


private:
	OperandInt8(void);
	OperandInt8& 				operator=(OperandInt8 const & rhs);

	int8_t						value;
	std::string const			str;

	static OperandInt8 const	negate;
};

#endif