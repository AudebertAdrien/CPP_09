/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:04:10 by motoko            #+#    #+#             */
/*   Updated: 2024/03/27 17:30:46 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h> 

class RPN {
	private:
		std::stack<int> _stack;
		int				_result;

	public:
		RPN(void);
		RPN(const RPN& obj);
		virtual ~RPN(void);

		RPN&	operator=(const RPN& obj);

		void	reversePolishNotation(const std::string &expr);
		bool	isOperator(char c);
		void	calculate(int num1, int num2, char op);

		int		getResult(void) const;

	protected:
		class insufficientOperands : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: insufficient operands");
				}
		};

		class invalidToken : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: invalid token");
				}
		};

		class tooManyOperands : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: too many operands");
				}
		};

		class divisionByZero : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: division by zero");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const RPN& i);
