/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:20:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/07 10:28:48 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENVALUE_HPP
# define TOKENVALUE_HPP

# include <sstream>
# include "IToken.hpp"
# include "IOperand.hpp"

class TokenValue: public IToken {
public:
	TokenValue(IOperand const * operand);
	~TokenValue(void);
	TokenValue(TokenValue const & rhs);
	TokenValue &				operator=(TokenValue const & rhs);

	IOperand const *			getOperand(void) const;

	virtual eTokenType			getType(void) const;
	virtual std::string			toString(void) const;

	static std::string const	operandTypeToString[5];

private:
	TokenValue(void);

	IOperand const *			operand;
};

#endif