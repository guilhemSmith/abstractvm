/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IToken.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:06:13 by gsmith            #+#    #+#             */
/*   Updated: 2019/10/11 17:49:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOKEN_HPP
# define ITOKEN_HPP

# include <string>

enum eTokenType {
	Operation,
	Value,
	Error
};

class IToken {

public:
	virtual ~IToken(void) {}

	virtual eTokenType			getType(void) const = 0;

	virtual std::string			toString(void) const = 0;

};

#endif