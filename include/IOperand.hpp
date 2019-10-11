/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:15:02 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 16:24:44 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <string>

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double,
};

class IOperand {

public:
	virtual int					getPrecision(void) const = 0;					// Precision of the type of the instance
	virtual eOperandType		getType(void) const = 0;						// Type of the instance

	virtual IOperand const *	operator+( IOperand const& rhs ) const = 0;		// Sum
	virtual IOperand const *	operator-( IOperand const& rhs ) const = 0;		// Difference
	virtual IOperand const *	operator*( IOperand const& rhs ) const = 0;		// Product
	virtual IOperand const *	operator/( IOperand const& rhs ) const = 0;		// Quotient
	virtual IOperand const *	operator%( IOperand const& rhs ) const = 0;		// Modulo

	virtual std::string const &	toString(void) const = 0;						// String representation of the instance

	virtual						~IOperand(void) {}

};

#endif