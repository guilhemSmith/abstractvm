/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:16:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 17:15:25 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "AbstractVM.hpp"

int		main(int argc, char *argv[]) {
	int				file_index;
	AbstractVM		avm;

	if (argc == 1) {
		try {
			avm.readInput(std::cin);
			avm.parseTokens();
			avm.runInstructions();
		} catch (AbstractVM::AbstractVMException lf) {
			std::cerr << lf.what() << std::endl;
		}
		avm.printLists();
		avm.clearLists();
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
					avm.readInput(file_stream);
					avm.parseTokens();
					avm.runInstructions();
				} catch (AbstractVM::AbstractVMException lf) {
					std::cerr << lf.what() << std::endl;
				}
			} else {
				std::cerr << "[File: " << file_index \
					<< "] - Invalid file name: " << argv[file_index] \
					<< std::endl;
			}
			file_stream.close();
			avm.printLists();
			avm.clearLists();
		}
	}
	return 0;
}