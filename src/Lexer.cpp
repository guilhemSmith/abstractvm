/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:06:35 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 15:34:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "Lexer.hpp"

Lexer::Lexer(void) {}

Lexer::~Lexer(void) {}

void	Lexer::read_input(std::istream & input_src) throw() {
	std::string				input_buf;
	std::queue<std::string>	input_queue;
	bool					run = true;

	while (run) {
		std::getline(input_src, input_buf);
		if (input_src.bad() || input_src.eof()) {
			run = false;
			continue;
		}
		input_queue.push(input_buf);
	}
	while (!input_queue.empty()) {
		std::cout << input_queue.front() << std::endl;
		input_queue.pop();
	}
}