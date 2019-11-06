/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 15:53:28 by gsmith           ###   ########.fr       */
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

	virtual void			activate(void) const \
								throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const;
private:
	InstructionSimple(void);
	InstructionSimple(InstructionSimple const & rhs);
	InstructionSimple &		operator=(InstructionSimple const & rhs);
	
	eOperationType			type;
};
#endif