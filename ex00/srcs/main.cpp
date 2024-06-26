/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:10:01 by motoko            #+#    #+#             */
/*   Updated: 2024/03/25 15:09:49 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "error : Invalid number of parameters."<< std::endl;
        std::cout << "Usage: 1 parameter max." << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	exchange;

	exchange.run(av[1]);

	return (EXIT_SUCCESS);
}
