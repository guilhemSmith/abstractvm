/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionArg.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 15:46:56 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONARG_HPP
# define INSTRUCTIONARG_HPP

#include <sstream>
# include "IInstruction.hpp"
# include "IOperand.hpp"
# include "TokenOperation.hpp"

class InstructionArg: public IInstruction {
public:
	InstructionArg(eOperationType const type, IOperand const * argument);
	virtual ~InstructionArg(void);

	virtual void				activate(void) const \
									throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const; 

private:
	InstructionArg(void);
	InstructionArg(InstructionArg const & rhs);
	InstructionArg &		operator=(InstructionArg const & rhs);

	eOperationType			type;
	IOperand const *		argument;
};
#endif