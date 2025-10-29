/// @file PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdint.h>

#include <vector>

#define MAX_VAL 256
#define SUB_VER "3.0"



std::vector<std::size_t>&	getJacobsthal(std::size_t size);

///	@brief Parses command-line arguments into a container of non-negative integers.
///	@tparam C Container type that supports push_back operation (e.g., std::vector or std::deque).
///	@param[in] args Array of C-style strings containing command-line arguments.
///	@param[in] argc Number of arguments in the args array.
///	@param[out] container Reference to container where parsed integers will be stored.
///	@throws std::runtime_error	If any argument cannot be parsed as a valid non-negative integer, or if the argument
/// 							contains trailing non-numeric characters.
///	@note Arguments are processed starting from index 1 (index 0 is typically the program name).
///	@warning All values must be non-negative (>= 0).
template <class C>
void	parseArgs(char* args[], int argc, C& container);

template <class C>
C	sortFunction(const C& input);


// 1. Take a set of numbers
// 2. 


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
