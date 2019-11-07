/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:48:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 11:35:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
# define ERRORS_HPP

# include <vector>
# include <tuple>
# include "AbstractVM.hpp"

class LexerFail: public AbstractVM::AbstractVMException {
	public:
		LexerFail(std::vector<std::tuple<int, std::string>> errors) throw();
		LexerFail(const LexerFail &rhs) throw();
		virtual ~LexerFail(void) throw();

	private:
		LexerFail(void) throw();
		LexerFail&				operator=(const LexerFail &rhs) throw();
	
};

class ParserFail: public AbstractVM::AbstractVMException {
	public:
		ParserFail(std::vector<std::tuple<int, std::string>> errors) throw();
		ParserFail(const ParserFail &rhs) throw();
		virtual ~ParserFail(void) throw();

	private:
		ParserFail(void) throw();
		ParserFail&				operator=(const ParserFail &rhs) throw();
	
};

class IncorrectExit: public AbstractVM::AbstractVMException {
	public:
		IncorrectExit(bool missing) throw();
		IncorrectExit(const IncorrectExit &rhs) throw();
		virtual ~IncorrectExit(void) throw();

	private:
		IncorrectExit(void) throw();
		IncorrectExit&				operator=(const ParserFail &rhs) throw();
	
};

#endif