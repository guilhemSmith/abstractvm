/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:06:28 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 13:37:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <list>
# include <vector>
// # include <exception>
// # include <stack>
# include "IToken.hpp"

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

	void		readInput(std::istream & input_src) throw();
	void		printList(void) const;
	void		clearList(void);

private:
	Lexer(const Lexer &rhs);
	Lexer&		operator=(const Lexer &rhs);
	
	std::list<std::vector<IToken *>> \
				input_list;

};

#endif