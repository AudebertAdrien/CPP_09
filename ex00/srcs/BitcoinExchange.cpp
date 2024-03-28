/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:23:36 by motoko            #+#    #+#             */
/*   Updated: 2024/03/28 15:34:49 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "Constructor by default" << std::endl;
	std::ifstream file("data.csv");
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t delim = line.find(',');
		std::string date = ft_trim(line.substr(0, delim));
		float	value = ft_stof(ft_trim(line.substr(delim + 1, line.length())));

		_data[date] = value;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) {
	std::cout << "Constructor by copy" << std::endl;
	*this = rhs;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	std::cout << "Operator = called" << std::endl;
	if (this != &rhs) {
		_data = rhs._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "Destructor by default" << std::endl;
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int BitcoinExchange::ft_stoi(const std::string &str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    return value;
}

double BitcoinExchange::ft_stod(const std::string &str)
{
    std::stringstream ss(str);
    double value;

    ss >> value;

    return value;
}

float	BitcoinExchange::ft_stof(const std::string &str)
{
    std::stringstream ss(str);
	float value;

    ss >> value;

    return value;
}

std::string BitcoinExchange::ft_itos(int value)
{
    std::stringstream ss;

    ss << value;

    return ss.str();
}

std::string BitcoinExchange::ft_trim(std::string str) {
    std::string::iterator it = str.begin();
    std::string::reverse_iterator rit = str.rbegin();

    while (it != str.end() && (*it == ' ' || *it == '\t')) {
        ++it;
    }
    while (rit != str.rend() && (*rit == ' ' || *rit == '\t')) {
        ++rit;
    }
    str.erase(str.begin(), it);
    str.erase(rit.base(), str.end());
	return str;
}

bool	BitcoinExchange::allDigits(const std::string &str) {
   for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool	BitcoinExchange::validDate(std::string &date) {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	if(!allDigits(year) || !allDigits(month) || !allDigits(day))
		return false;

	//std::cout << std::string(50, '@') << std::endl;
	int yearInt, monthInt, dayInt;

	std::stringstream ssYears(year);
	std::stringstream ssMonth(month);
	std::stringstream ssDay(day);

	ssYears >> yearInt;
	ssMonth >> monthInt;
	ssDay >> dayInt;

	if ((yearInt < 2009 || yearInt > 2022) ||
			(monthInt < 1 || monthInt > 12) ||
			(dayInt < 1 || dayInt > 31))
		return false;

	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
		return false;

	if (monthInt == 2) {
		bool isLeap = isLeapYear(yearInt);
		if (dayInt > (isLeap ? 29 : 28))
			return false;
	}
	return true;
}

void BitcoinExchange::validateNumber(const std::string &str) {
	double value;

	if (std::find(str.begin(), str.end(), '.') != str.end()) {
		size_t decimalPoint = str.find('.');
		if (std::find(str.begin() + decimalPoint + 1, str.end(), '.') != str.end())
			throw std::invalid_argument("too many decimal points");
	}

	bool hasSign = str[0] == '+' || str[0] == '-';
	int i = 0;
	if (hasSign) 
		i++;
	while(str[i]) {
		if (isdigit(str[i]) || str[i] == '.') 
			i++;
		else
			throw std::invalid_argument("not a number => " + str);
	}

	value = ft_stod(str);


	if (value < 0)
		throw std::invalid_argument("not a positive number");

	if (value > 1000.0)
		throw std::invalid_argument("too large a number");
}


float	BitcoinExchange::getExchangeRate(const std::string &date) const {
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it != _data.begin() && (it == _data.end() || it->first != date)) 
		--it;
	return (it->second);
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
		std::string quantity  = ft_trim(line.substr(delim + 1));

		try {
			if (!validDate(date))
				throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));
			if(quantity.empty())
				throw std::invalid_argument("invalid value: " + (quantity.empty() ? "\"\"" : "'" + quantity + "'"));

		validateNumber(quantity);

		float ratio = getExchangeRate(date);

		std::cout << "date >> " << date << std::endl;
		std::cout << "quantity >> " << quantity  << std::endl;
		std::cout << "ratio >> " << ft_stof(quantity) * ratio  << std::endl;

		} catch (std::exception &e) {
			std::cerr << "error : " << e.what() << std::endl;
		}
	}
	file.close();
}
