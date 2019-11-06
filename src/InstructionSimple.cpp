/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:33 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 15:54:13 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionSimple.hpp"

InstructionSimple::InstructionSimple (eOperationType const type): type(type) {

}
InstructionSimple::~InstructionSimple(void) {}

void				InstructionSimple::activate(void) const \
						throw(AbstractVM::AbstractVMException) {
	
}

eInstructionType	InstructionSimple::getType(void) const {
	return eInstructionType::Simple;
}

std::string			InstructionSimple::toString(void) const {
	std::stringstream	ss;

	ss << '{' << TokenOperation::opTypeToString(this->type) << '}';
	return ss.str();
}