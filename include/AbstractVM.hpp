/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:06:28 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/05 11:17:04 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <iostream>
# include <list>
# include <regex>
# include <exception>
# include "IToken.hpp"
# include "IOperand.hpp"

class AbstractVM {

public:
	class AbstractVMException: public std::exception {
		public:
			AbstractVMException(void) throw();
			AbstractVMException(const AbstractVMException &rhs) throw();
			virtual ~AbstractVMException(void) throw();
			virtual const char * \
							what(void) const throw();
		
		protected:
			std::string				message;

		private:
			AbstractVMException& \
							operator=(const AbstractVMException &rhs) throw();
	};

	AbstractVM(void);
	~AbstractVM(void);

	std::list<std::vector<IToken *>> const & \
							getList(void) const;

	void					readInput(std::istream & input_src) \
								throw(AbstractVMException);
	void					printList(void) const;
	void					clearList(void);

private:
	AbstractVM(const AbstractVM &rhs);
	AbstractVM&					operator=(const AbstractVM &rhs);
	
	std::list<std::vector<IToken *>> \
				input_list;

	void					checkErrors(void) throw(AbstractVMException);
	std::vector<IToken *>	tokenize(std::stringstream & ss) const;
	IToken *				createValue(std::string value_raw) const;
	IOperand const *		createOperand( eOperandType type, \
								std::string const& value ) const;
	IOperand const *		createInt8(std::string const& value) const;
	IOperand const *		createInt16(std::string const& value) const;
	IOperand const *		createInt32(std::string const& value) const;
	IOperand const *		createFloat(std::string const& value) const;
	IOperand const *		createDouble(std::string const& value) const;

	typedef IOperand const *(AbstractVM::*tOrandCreate)(std::string const&) const;

	static double const			epsilon;
	static int const			nb_orand_type = 5;
	static std::regex const		regex_orand;
	static tOrandCreate const	create_tab[nb_orand_type];
	static std::string const	identify_operand_type[nb_orand_type];

};

#endif