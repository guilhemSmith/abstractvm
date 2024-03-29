/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenError.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:20:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/12 11:59:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENERROR_HPP
# define TOKENERROR_HPP

# include "IToken.hpp"

enum eTokenErrorType {
	ErrToken,
	ErrValueType,
	ErrValue,
	ErrOverflow,
};

class TokenError: public IToken {
public:
	TokenError(eTokenErrorType type, std::string input_value);
	~TokenError(void);
	TokenError(TokenError const & rhs);
	TokenError &				operator=(TokenError const & rhs);

	std::string const			getErrorMessage(void) const;
	virtual eTokenType			getType(void) const;
	virtual std::string			toString(void) const;

private:
	TokenError(void);

	eTokenErrorType				type;
	std::string					input_value;

	static std::string const	errString[4];
};

#endif