/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:23:36 by motoko            #+#    #+#             */
/*   Updated: 2024/03/25 16:48:36 by motoko           ###   ########.fr       */
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

	while (std::getline(file, line) {
		size_t delim = line.find('|');
		if (delim == string::npos) {
			std::cout << "Error: bad input >> " << line << std::endl;
			continue;
		}
	}

	strind date = trim(line.substr(0, delim);
	strind value = trim(line.substr(delime + 1);

	try {

	} catch (std::exception &e) {
		std::cerr << "error : " << e.what() << std::endl;
	}
}
