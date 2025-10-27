/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:33:57 by apetitco          #+#    #+#             */
/*   Updated: 2025/10/27 20:19:41 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <deque>

template <typename Container>
void	algo(Container& container) {
	if (container.size() < 2) {	//< Condition de sortie de l'appel récursif
		return (container);
	}

	Container	left;
	Container	right;

	// for all the numbers in the container two by two
		// IF left < right -> swap
		// even index -> left ; odd inex -> right
	
	// IF odd number of values in the original set, push last value on left

	// recursive call
	// Merge everything
	// return one of the containers (which one ?)
}

template <class Container>
void	merge(Container& left, Container& right) {
	// FOR each index in the Jacobsthal suite until the jacob number is bigger than the size of the left container
		// Insert the number
	// FOR ???
		// IF ???
	// insert number
}
