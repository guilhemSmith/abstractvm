/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:06:35 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 18:06:54 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "Lexer.hpp"
#include "TokenOperation.hpp"
#include "TokenError.hpp"
#include "TokenValue.hpp"

Lexer::Lexer(void) {}

Lexer::~Lexer(void) {}

void	Lexer::readInput(std::istream & input_src) throw() {
	std::string				input_buf;
	std::queue<IToken *>	input_queue;
	bool					run = true;

	while (run) {
		std::getline(input_src, input_buf);
		if (input_src.bad() || input_src.eof()) {
			run = false;
			continue;
		}
		input_queue.push(new TokenOperation(eOperationType::Exit));
		input_queue.push(new TokenError("nope"));
		input_queue.push(new TokenValue("42"));
	}
	while (!input_queue.empty()) {
		std::cout << input_queue.front()->toString() << std::endl;
		delete input_queue.front();
		input_queue.pop();
	}
}