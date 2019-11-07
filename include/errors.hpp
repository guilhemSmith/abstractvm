/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:48:12 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 13:35:04 by gsmith           ###   ########.fr       */
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

class AssertFail: public AbstractVM::AbstractVMException {
	public:
		AssertFail(IOperand const * expected, IOperand const * real) throw();
		AssertFail(const AssertFail &rhs) throw();
		virtual ~AssertFail(void) throw();

	private:
		AssertFail(void) throw();
		AssertFail&				operator=(const ParserFail &rhs) throw();
	
};

class PrintFail: public AbstractVM::AbstractVMException {
	public:
		PrintFail(bool wrong_type) throw();
		PrintFail(const PrintFail &rhs) throw();
		virtual ~PrintFail(void) throw();

	private:
		PrintFail(void) throw();
		PrintFail&				operator=(const ParserFail &rhs) throw();
	
};

#endif