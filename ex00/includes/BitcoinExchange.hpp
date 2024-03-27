/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:21:43 by motoko            #+#    #+#             */
/*   Updated: 2024/03/27 15:27:39 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, std::string>	_data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &rhs);
		BitcoinExchange&	operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		bool		isLeapYear(int year);
		int			ft_stoi(const std::string &str);
		double		ft_stod(const std::string &str);
		std::string	ft_itos(int value);

		std::string	ft_trim(std::string str);

		void	run(const std::string &filename);
		bool	allDigits(const std::string &str);
		bool    validDate(std::string &date);
		void	validNumber(const std::string &str);
};
