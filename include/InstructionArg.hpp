/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionArg.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 10:42:45 by gsmith           ###   ########.fr       */
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

	virtual void				run(std::list<IOperand const *> & mem, \
										bool & exit) const \
									throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const; 

private:
	InstructionArg(void);
	InstructionArg(InstructionArg const & rhs);
	InstructionArg &			operator=(InstructionArg const & rhs);

	eOperationType				type;
	IOperand const *			argument;

	void						instrPush(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrAssert(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);


	typedef void (InstructionArg::*tInstrSelect) \
								(std::list<IOperand const *> & mem) const;

	static tInstrSelect const	select[TokenOperation::last_operation_arg + 1];
};
#endif