/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:10:01 by motoko            #+#    #+#             */
/*   Updated: 2024/03/27 17:34:33 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "error_usage: ./RPN \"<expression>\"" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		RPN rpn;
		rpn.reversePolishNotation(av[1]);
		std::cout << rpn << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
