/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:33:53 by motoko            #+#    #+#             */
/*   Updated: 2024/03/27 17:32:31 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _result(0) {
	 //std::cout << "Constructor by default" << std::endl;
}

RPN::RPN(const RPN &rhs) {
	 //std::cout << "Constructor by copy" << std::endl;
	*this = rhs;
}

RPN& RPN::operator=(const RPN& rhs) {
	//std::cout << "Operator = called" << std::endl;
	if (this != &rhs) {
		this->_stack = rhs._stack;
		this->_result = rhs._result;
	}
	return (*this);
}

RPN::~RPN() {
	//std::cout << "Destructor by default" << std::endl;
}

void	RPN::reversePolishNotation(const std::string &expr)
{
	std::string token;

	for (std::size_t i = 0; i < expr.length(); i++)
	{
		char c = expr[i];
		if (c == ' ')
			continue;
		else if (isdigit(c))
			token += c;
		else if (isOperator(c))
		{
			if (_stack.size() < 2)
				throw insufficientOperands();
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();
			calculate(num1, num2, c);
		}
		else
			throw invalidToken();
		if (!token.empty())
		{
			_stack.push(atoi(token.c_str()));
			token.clear();
		}
	}
	if (_stack.size() != 1)
		throw tooManyOperands();
	_result = _stack.top();
	_stack.pop();
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::calculate(int num1, int num2, char op)
{
	switch (op)
	{
		case '+':
			_stack.push(num1 + num2);
			break;
		case '-':
			_stack.push(num1 - num2);
			break;
		case '*':
			_stack.push(num1 * num2);
			break;
		case '/':
			if (num2 == 0)
				throw divisionByZero();
			_stack.push(num1 / num2);
			break;
	}
}

int	RPN::getResult(void) const
{
	return (this->_result);
}

std::ostream&	operator<<(std::ostream& o, const RPN& i)
{
	o << i.getResult();
	return o;
}
