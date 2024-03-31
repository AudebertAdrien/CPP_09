/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:58:41 by motoko            #+#    #+#             */
/*   Updated: 2024/03/31 18:56:17 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &rhs) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs){
	if (this != &rhs) {}
	return *this;
}

void    PmergeMe::merge_insertion_sort(std::vector<int> &vector) {
	if (vector.size() <= 1)
		return ;

	size_t m = vector.size() / 2;
	std::vector<int>	left(vector.begin(), vector.begin() + m);
	std::vector<int>	right(vector.begin() + m, vector.end());

	merge_insertion_sort(left);
	merge_insertion_sort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vector.begin());
}

PmergeMe::~PmergeMe() {
	std::cout << "Destructor called" << std::endl;
}


