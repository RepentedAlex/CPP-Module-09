#ifndef PMERGEME_HPP
#define PMERGEME_HPP



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
