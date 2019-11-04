/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:16:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/04 15:51:11 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "Lexer.hpp"

int		main(int argc, char *argv[]) {
	int				file_index;
	Lexer			lexer;

	if (argc == 1) {
		try {
			lexer.readInput(std::cin);
		} catch (Lexer::LexerFail lf) {
			std::cout << lf.what() << std::endl;
		}
		lexer.printList();
		lexer.clearList();
	} else {
		file_index = 0;
		while (++file_index < argc) {
			std::ifstream	file_stream (argv[file_index]);
			if (file_index > 1) {
				std::cout << std::endl;
			}
			if (file_stream.good()) {
				if (argc > 2) {
					std::cout << "[File: " << file_index << "]: " \
						<< argv[file_index] << std::endl;
				}
				try {
					lexer.readInput(file_stream);
				} catch (Lexer::LexerFail lf) {
					std::cout << lf.what() << std::endl;
				}
			} else {
				std::cerr << "[File: " << file_index \
					<< "] - Invalid file name: " << argv[file_index] \
					<< std::endl;
			}
			file_stream.close();
			lexer.printList();
			lexer.clearList();
		}
	}
	return 0;
}