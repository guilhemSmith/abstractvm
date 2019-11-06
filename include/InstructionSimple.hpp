/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 17:28:35 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONSIMPLE_HPP
# define INSTRUCTIONSIMPLE_HPP

# include <sstream>
# include "TokenOperation.hpp"
# include "IInstruction.hpp"

class InstructionSimple: public IInstruction {
public:
	InstructionSimple(eOperationType const type);
	virtual ~InstructionSimple(void);

	virtual void			run(std::list<IOperand const *> & mem) const \
								throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const;
private:
	InstructionSimple(void);
	InstructionSimple(InstructionSimple const & rhs);
	InstructionSimple &		operator=(InstructionSimple const & rhs);
	
	eOperationType			type;

	void						instrPop(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrDump(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrAdd(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrSub(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrMul(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrDiv(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrMod(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrPrint(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);
	void						instrExit(std::list<IOperand const *> & mem) \
									const \
									throw(AbstractVM::AbstractVMException);

	typedef void (InstructionSimple::*tInstrSelect) \
								(std::list<IOperand const *> & mem) const;

	static tInstrSelect const	select[TokenOperation::last_operation_simple \
										- TokenOperation::last_operation_arg];
};
#endif