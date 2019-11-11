/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:16:47 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/11 12:12:55 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.hpp"
#include "AbstractVM.hpp"
#include "errors.hpp"

int		main(int argc, char *argv[]) {
	int				file_index;
	AbstractVM		avm;

	if (argc == 1) {
		try {
			avm.readInput(std::cin);
			avm.parseTokens();
			avm.runInstructions();
		} catch (LexerFail lf) {
			std::cerr << lf.what() << std::endl;
		} catch (ParserFail pf) {
			std::cerr << pf.what() << std::endl;
		} catch (AbstractVM::AbstractVMException avm_exc) {
			std::cerr << "[instruction:" << avm.getLine() << "] - " \
				<< avm_exc.what() << std::endl;
		}
		avm.reset();
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
				} catch (LexerFail lf) {
					std::cerr << lf.what() << std::endl;
				} catch (ParserFail pf) {
					std::cerr << pf.what() << std::endl;
				} catch (AbstractVM::AbstractVMException avm_exc) {
					std::cerr << "[instruction:" << avm.getLine() << "] - " \
						<< avm_exc.what() << std::endl;
				}
			} else {
				std::cerr << "[File: " << file_index \
					<< "] - Invalid file name: " << argv[file_index] \
					<< std::endl;
			}
			file_stream.close();
			avm.reset();
		}
	}
	return 0;
}