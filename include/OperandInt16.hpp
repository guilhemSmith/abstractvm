/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:54:58 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 10:32:28 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDINT16_HPP
# define OPERANDINT16_HPP

# include "IOperand.hpp"

class OperandInt16: public IOperand {
	
public:
	OperandInt16(int16_t value, std::string const str);
	virtual						~OperandInt16(void);
	OperandInt16(OperandInt16 const & rhs);

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;

	virtual IOperand const *	operator+( IOperand const& rhs ) const;
	virtual IOperand const *	operator-( IOperand const& rhs ) const;
	virtual IOperand const *	operator*( IOperand const& rhs ) const;
	virtual IOperand const *	operator/( IOperand const& rhs ) const;
	virtual IOperand const *	operator%( IOperand const& rhs ) const;

	virtual std::string const &	toString(void) const;

private:
	OperandInt16(void);
	OperandInt16& 				operator=(OperandInt16 const & rhs);

	int16_t						value;
	std::string const			str;

	static OperandInt16 const	negate;
};

#endif