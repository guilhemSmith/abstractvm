/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:16:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/14 16:07:39 by gsmith           ###   ########.fr       */
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
				if (argc > 2) {
					std::cout << "[File: " << file_index << "]: " \
						<< argv[file_index] << std::endl;
				}
				lexer.readInput(file_stream);
			} else {
				std::cerr << "[File: " << file_index \
					<< "] - Invalid file name: " << argv[file_index] \
					<< std::endl;
			}
			file_stream.close();
			lexer.printList();
			lexer.clearList();
			lexer.printList();
		}
	}
	std::cout << "size of int8_t: " << sizeof(int8_t) * 8 << " bits" << std::endl;
	std::cout << "size of int16_t: " << sizeof(int16_t) * 8 << " bits" << std::endl;
	std::cout << "size of int32_t: " << sizeof(int32_t) * 8 << " bits" << std::endl;
	std::cout << "size of float: " << sizeof(float) * 8 << " bits" << std::endl;
	std::cout << "size of double: " << sizeof(double) * 8 << " bits" << std::endl;
	return 0;
}