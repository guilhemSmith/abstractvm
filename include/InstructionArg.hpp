/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionArg.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 11:47:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONARG_HPP
# define INSTRUCTIONARG_HPP

# include "IInstruction.hpp"
# include "IOperand.hpp"

class InstructionArg: public IInstruction {
public:
	InstructionArg(void);
	virtual ~InstructionArg(void);

	virtual void			activate(void) const \
								throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const;
private:
	InstructionArg(InstructionArg const & rhs);
	InstructionArg &		operator=(InstructionArg const & rhs);

	IOperand *				argument;
};
#endif