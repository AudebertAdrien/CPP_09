/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:52:23 by motoko            #+#    #+#             */
/*   Updated: 2024/03/31 18:46:55 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe& operator=(const PmergeMe &rhs);
		~PmergeMe();

		void	merge_insertion_sort(std::vector<int> &vector);
	private:
};
