/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:13:12 by motoko            #+#    #+#             */
/*   Updated: 2024/03/31 18:56:41 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "error_usage: ./PmergeMe \"<list of positive numbers>\"" << std::endl;
		return EXIT_FAILURE;
	}

	std::vector<int> data;
	int	i = 1;
	while (i < ac) {
		int	num = std::atoi(av[i]);
		if (num < 0) {
			std::cout << "error: only positive numbers" << std::endl;
			return EXIT_FAILURE;
		}
		data.push_back(num);
		i++;
	}

	std::cout << "Before" << std::endl;
	long unsigned int	j = 0;
	while (j < data.size()) {
		std::cout << data[j] << std::endl;
		j++;
	}

	std::vector<int> data_cpy = data;

	PmergeMe	test;

	clock_t		start = clock();
	test.merge_insertion_sort(data);
	clock_t		end = clock();
	double		duration = static_cast<double>(end - start);

	std::cout << "After" << std::endl;
	j = 0;
	while (j < data.size()) {
		std::cout << data[j] << std::endl;
		j++;
	}

	std::cout << "Time 1: " << duration << std::endl;

	start = clock();

	std::list<int> data_list(data_cpy.begin(), data_cpy.end());
	data_list.sort();
	data_cpy.assign(data_list.begin(), data_list.end());
	end = clock();
	duration = static_cast<double>(end - start);

	std::cout << "Time 2: " << duration << std::endl;

	return (0);
}
