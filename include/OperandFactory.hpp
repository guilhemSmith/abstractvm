/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:24 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/12 11:52:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

# include "IOperand.hpp"

class OperandFactory {
public:
	class InvalidValue: public std::exception {};
	class ValueOverflow: public std::exception {};
	OperandFactory(void);
	~OperandFactory(void);

	IOperand const *		createOperand( eOperandType type, \
								std::string const& value ) const;

	static int const			nb_orand_type = 5;

private:
	OperandFactory(OperandFactory const & rhs);
	OperandFactory &		operator=(OperandFactory const & rhs);
	
	IOperand const *		createInt8(std::string const& value) const;
	IOperand const *		createInt16(std::string const& value) const;
	IOperand const *		createInt32(std::string const& value) const;
	IOperand const *		createFloat(std::string const& value) const;
	IOperand const *		createDouble(std::string const& value) const;

	typedef IOperand const *(OperandFactory::*tOrandCreate) \
								(std::string const&) const;

	static tOrandCreate const	create_tab[nb_orand_type];
};

#endif