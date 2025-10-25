#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <utility>
#include <typeinfo>
#include <vector>

#include "PmergeMe.hpp"

#define MAXPAIRS 10



template <typename T, typename U>
void	sortInnermostPairs(std::pair<T, U>& pair) {
	sortInnermostPairs(pair.first);
	sortInnermostPairs(pair.second);

	if (typeid(T) == typeid(int) && typeid(U) == typeid(int)) {
		if (pair.first > pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
}

template <typename T>
void	sortPairVector(std::vector<std::pair<T, T> >& pairVector) {
	for (typename std::vector<std::pair<T, T> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it) {
		sortInnermostPairs(*it);
	}
}

template <typename T>
void	recursivePairing(int *array, int len) {
	std::vector<std::pair<T, T> >	pairArray;

	for (int i = 0; i < len; i++) {
		T	first = array[i];
		if (++i < len) {
			T	second = array[i];
			pairArray.push_back(std::make_pair(first, second));
		}
	}
}
