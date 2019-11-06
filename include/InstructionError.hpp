/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionError.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 11:49:14 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONERROR_HPP
# define INSTRUCTIONERROR_HPP

# include <sstream>
# include "IInstruction.hpp"

enum eInstructionErrorType {
	TooManyArg,
	MissingArg,
	IncorrectInstr,
};

class InstructionError: public IInstruction {
public:
	InstructionError(std::string str, eInstructionErrorType type);
	virtual ~InstructionError(void);

	std::string const			getErrorMessage(void) const;
	virtual void				activate(void) const \
									throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const;
	
private:
	InstructionError(void);
	InstructionError(InstructionError const & rhs);
	InstructionError &		operator=(InstructionError const & rhs);

	std::string				instruction;
	eInstructionErrorType	type;
};
#endif