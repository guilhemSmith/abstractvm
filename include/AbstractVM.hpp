/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:06:28 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 16:05:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include <iostream>
# include <list>
# include <regex>
# include <exception>
# include "IOperand.hpp"
# include "IToken.hpp"
# include "OperandFactory.hpp"

class IInstruction;

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

	void						readInput(std::istream & input_src) \
									throw(AbstractVMException);
	void						parseTokens(void) \
									throw(AbstractVMException);
	void						printLists(void) const;
	void						clearLists(void);

	static std::string			tokensToString(std::vector<IToken *> tok);

private:
	AbstractVM(const AbstractVM &rhs);
	AbstractVM &				operator=(const AbstractVM & rhs);
	
	OperandFactory				factory;
	std::list<std::vector<IToken *>> \
								input_list;
	std::list<IInstruction *>	instruction_list;
	std::list<IOperand *>		memory;

	void						checkLexErrors(void) const \
									throw(AbstractVMException);
	void						checkSynErrors(void) const \
									throw(AbstractVMException);
	std::vector<IToken *>		tokenize(std::stringstream & ss) const;
	void						addInstruction(std::vector<IToken *> tok);
	IToken *					createValue(std::string value_raw) const;

	static double const			epsilon;
	static std::regex const		regex_orand;
	static std::string const	get_operand_type[OperandFactory::nb_orand_type];

};

#endif