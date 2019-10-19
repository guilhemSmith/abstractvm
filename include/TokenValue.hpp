/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenValue.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:20:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/19 15:01:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENVALUE_HPP
# define TOKENVALUE_HPP

# include "IToken.hpp"
# include "IOperand.hpp"

class TokenValue: public IToken {
public:
	TokenValue(IOperand const * operand);
	~TokenValue(void);
	TokenValue(TokenValue const & rhs);
	TokenValue &			operator=(TokenValue const & rhs);

	std::string const &			getInputValue(void) const;

	virtual eTokenType			getType(void) const;
	virtual std::string			toString(void) const;

private:
	TokenValue(void);

	IOperand const *			operand;
};

#endif