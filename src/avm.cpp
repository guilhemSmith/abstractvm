/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:16:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 18:07:39 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "Lexer.hpp"

int		main(int argc, char *argv[]) {
	int				file_index;
	Lexer			lexer;

	if (argc == 1) {
		lexer.readInput(std::cin);
	} else {
		file_index = 0;
		while (++file_index < argc) {
			std::ifstream	file_stream (argv[file_index]);
			if (file_index > 1) {
				std::cout << std::endl;
			}
			if (file_stream.good()) {
				std::cout << "[File: " << file_index << "]: " \
					<< argv[file_index] << std::endl;
				lexer.readInput(file_stream);
			} else {
				std::cerr << "[File: " << file_index \
					<< "] - Invalid file name: " << argv[file_index] \
					<< std::endl;
			}
			file_stream.close();
		}
	}
	return 0;
}