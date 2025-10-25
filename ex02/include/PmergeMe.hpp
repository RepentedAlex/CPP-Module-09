#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <deque>
#include <vector>



#include <ctime>
#include <cstdlib>

#define MAXPAIRS 10

void	sortPairs(std::pair<int, int> *pairArray);


/// @struct
typedef struct	s_pair {
	long long int	left;
	long long int	right;

	s_pair(long long int left, long long int right) : left(left), right(right) {}

	long long int	min() {
		return ((left < right) ? left : right);
	}

	long long int	max() {
		return ((left > right) ? left : right);
	}
}				t_pair;

class	PmergeMe {

private:
	std::vector<long long int>	container1_;	//<
	std::deque<long long int>	container2_;	//<
	
};

// std::pair;
// std::deque container1
// std::vector container2


// Ford-Jacobson
// Associate series from left to right in pairs
// e.g., [1,4,5,3] -> [1,4] ; [5,3]
// Then pair the pairs until one big single pair
// e.g., [1,4,5,3,6,9] -> [1,4] ; [5,3] ; [6,9] -> [[1,4] , [5,3]] ; [[6,9]] -> [[[1,4] ; [5,3] ; [6,9]]]
// Sort pairs so the lowest level pair with the biggest element is either on beginning or end of the lowest level pair
// e.g. (on a single pair, biggest element on left) [3,5] -> we get [5,3]
// 
//
// [ [3, 5]; [4, 6]] =>
//		[ 3, 5] >? [4, 6] 
//			[ 3 5] => 3 >? 5?
//				y swap
//			[4 6] => ...
//			[6 4]
//		5 >? 6 ?
//			=> swap
//	[[6 4][ 5 3]]
//
//
// list a big
// list b saml

#endif // !PMERGEME_HPP
