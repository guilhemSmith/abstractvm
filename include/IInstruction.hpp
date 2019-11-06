/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInstruction.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:07:31 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 16:44:33 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

# include "AbstractVM.hpp"

enum eInstructionType {
	Simple,
	Argument,
	InstError
};

class IInstruction {

public:
	virtual ~IInstruction(void) {}

	virtual void				run(std::list<IOperand const *> & mem) const \
									throw(AbstractVM::AbstractVMException) = 0;
	virtual eInstructionType	getType(void) const = 0;
	virtual std::string			toString(void) const = 0;
};

#endif