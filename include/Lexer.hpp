/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:06:28 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/04 13:38:35 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <list>
# include <regex>
# include <vector>
# include <exception>
// # include <stack>
# include "IToken.hpp"
# include "IOperand.hpp"

class Lexer {

public:
	// class LexerFail: public std::exception {
	// 	public:
	// 		LexerFail(std::stack<char *> err_stack) throw();
	// 		virtual ~LexerFail(void) throw();
	// 		virtual const char *	what(void) const throw();

	// 	private:
	// 		std::stack<char *>		err_stack;

	// 		LexerFail(void) throw();
	// 		LexerFail(const LexerFail &rhs) throw();
	// 		LexerFail&				operator=(const LexerFail &rhs) throw();
		
	// };

	Lexer(void);
	~Lexer(void);

	std::list<std::vector<IToken *>> const & \
							getList(void) const;

	void					readInput(std::istream & input_src) throw();
	void					printList(void) const;
	void					clearList(void);

private:
	Lexer(const Lexer &rhs);
	Lexer&					operator=(const Lexer &rhs);
	
	std::list<std::vector<IToken *>> \
				input_list;

	std::vector<IToken *>	tokenize(std::stringstream & ss) const;
	IToken *				createValue(std::string value_raw) const;
	IOperand const *		createOperand( eOperandType type, \
								std::string const& value ) const;
	IOperand const *		createInt8(std::string const& value) const;
	IOperand const *		createInt16(std::string const& value) const;
	IOperand const *		createInt32(std::string const& value) const;
	IOperand const *		createFloat(std::string const& value) const;
	IOperand const *		createDouble(std::string const& value) const;

	typedef IOperand const *(Lexer::*tOrandCreate)(std::string const&) const;

	static double const			epsilon;
	static int const			nb_orand_type = 5;
	static std::regex const		regex_orand;
	static tOrandCreate const	create_tab[nb_orand_type];
	static std::string const	identify_operand_type[nb_orand_type];

};

#endif