/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:23:36 by motoko            #+#    #+#             */
/*   Updated: 2024/03/25 18:10:13 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "Constructor by default" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) {
	std::cout << "Constructor by copy" << std::endl;
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	std::cout << "Operator = called" << std::endl;
	if (this != &rhs) {
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "Destructor by default" << std::endl;
}

/*
std::string&	ft_trim(std::string *str) {

	return (str);
}
*/

bool	BitcoinExchange::allDigits(const std::string &str) {
   for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool	validDate(std::string &date) {
	std::cout << "len : " << date.length() << std::endl;

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	return true;
}

void	BitcoinExchange::run(const std::string &filename) {
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open()) {
		std::cerr << "error : file does not exist" << std::endl; 
		exit(EXIT_FAILURE);
	}

	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cerr << "error : file is empty" << std::endl; 
		exit(EXIT_FAILURE);
	}

	std::getline(file, line);

	if (line != "date | value") {
		std::cout << "Error: invalid file format" << std::endl;
		exit(EXIT_FAILURE);	
	}

	while (std::getline(file, line)) {
		std::cout << std::string(50, '#') << std::endl;
		size_t delim = line.find('|');

		if (delim == std::string::npos) {
			std::cout << "Error: bad input >> " << line << std::endl;
			continue;
		}

		std::string date = ft_trim(line.substr(0, delim));
		std::string value = ft_trim(line.substr(delim + 1));
		std::cout << "date >> " << date << std::endl;
		std::cout << "value >> " << value << std::endl;

		try {
			if (!validDate(date))
				throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));
		} catch (std::exception &e) {
			std::cerr << "error : " << e.what() << std::endl;
		}
	}
}
