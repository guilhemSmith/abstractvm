/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionSimple.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:04:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/06 10:51:12 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONSIMPLE_HPP
# define INSTRUCTIONSIMPLE_HPP

# include "IInstruction.hpp"

class InstructionSimple: public IInstruction {
public:
	InstructionSimple(void);
	virtual ~InstructionSimple(void);

	virtual void			activate(void) const \
								throw(AbstractVM::AbstractVMException);
	virtual eInstructionType	getType(void) const;
	virtual std::string			toString(void) const;
private:
	InstructionSimple(InstructionSimple const & rhs);
	InstructionSimple &		operator=(InstructionSimple & const rhs);
};
#endif