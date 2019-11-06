/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionError.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 10:51:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONERROR_HPP
# define INSTRUCTIONERROR_HPP

# include "IInstruction.hpp"

enum eInstructionErrorType {
	ErrToken,
	ErrValueType,
	ErrValue,
};

class InstructionError: public IInstruction {
public:
	InstructionError(void);
	virtual ~InstructionError(void);

	std::string const			getErrorMessage(void) const;
	virtual void				activate(void) const \
									throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void);
	virtual std::string			toString(void);
	
private:
	InstructionError(InstructionError const & rhs);
	InstructionError &		operator=(InstructionError & const rhs);

	std::string				instruction;
	eInstructionErrorType	type;
};
#endif