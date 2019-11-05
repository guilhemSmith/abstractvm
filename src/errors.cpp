/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:50:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/05 10:54:21 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "errors.hpp"


LexerFail::LexerFail(std::vector<std::tuple<int, std::string>> errors) \
							throw() {
	std::stringstream	ss;

	ss << "Lexer failed: " << errors.size() << " invalid token." << std::endl;
	for (auto error : errors) {
		ss << "instruction " << std::get<0>(error) << ": " \
			<< std::get<1>(error) << std::endl;
	}
	this->message = ss.str();
}

LexerFail::LexerFail(const LexerFail &rhs) throw() {
	this->message = rhs.message;
}

LexerFail::~LexerFail(void) throw() {}