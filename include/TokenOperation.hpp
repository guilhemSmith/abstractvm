/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenOperation.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:20:27 by gsmith            #+#    #+#             */
/*   Updated: 2019/11/05 18:37:35 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENOPERATION_HPP
# define TOKENOPERATION_HPP

# include "IToken.hpp"

enum eOperationType {
	Push,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit,
	Invalid,
};

class TokenOperation: public IToken {
public:
	TokenOperation(eOperationType type);
	~TokenOperation(void);
	TokenOperation(TokenOperation const & rhs);
	TokenOperation &			operator=(TokenOperation const & rhs);

	eOperationType				getOperationType(void) const;
	bool						expectArg(void) const;
	virtual eTokenType			getType(void) const;
	virtual std::string			toString(void) const;
	static std::string			opTypeToString(eOperationType const & type);		
	static eOperationType		stringToOpType(std::string const & str);		

private:
	TokenOperation(void);

	eOperationType		type;

	static int const			nb_type = 11;
	static std::string const	type_string_tab[nb_type];

};

#endif