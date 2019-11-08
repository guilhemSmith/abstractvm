/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt32.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:54:58 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/08 10:39:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDINT32_HPP
# define OPERANDINT32_HPP

# include "IOperand.hpp"

class OperandInt32: public IOperand {
	
public:
	OperandInt32(int32_t value, std::string const str);
	virtual						~OperandInt32(void);
	OperandInt32(OperandInt32 const & rhs);

	virtual int					getPrecision(void) const;
	virtual eOperandType		getType(void) const;

	virtual IOperand const *	operator+( IOperand const& rhs ) const;
	virtual IOperand const *	operator-( IOperand const& rhs ) const;
	virtual IOperand const *	operator*( IOperand const& rhs ) const;
	virtual IOperand const *	operator/( IOperand const& rhs ) const;
	virtual IOperand const *	operator%( IOperand const& rhs ) const;

	virtual std::string const &	toString(void) const;


private:
	OperandInt32(void);
	OperandInt32& 				operator=(OperandInt32 const & rhs);

	int32_t						value;
	std::string const			str;

	static OperandInt32 const	negate;
};

#endif