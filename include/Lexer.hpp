/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:06:28 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 15:34:13 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
// # include <exception>
// # include <stack>

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

	void		read_input(std::istream & input_src) throw();

private:
	Lexer(const Lexer &rhs);
	Lexer&		operator=(const Lexer &rhs);

};

#endif