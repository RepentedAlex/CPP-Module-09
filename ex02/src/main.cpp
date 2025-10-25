#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <deque>

#include "PmergeMe.hpp"

#define MAX_VAL 3000

static std::vector<long long int>	jacobsthal;	//< vector holding the Jacobsthal Suite.

void	populateJacobsthal() {
	long long int	first = 0;
	long long int	second = 1;
	long long int	tmp = 0;

	jacobsthal.push_back(first);
	jacobsthal.push_back(second);

	for (int i = 2 ; i < 20 ; i++) {
		tmp = (first * 2) + second;
		jacobsthal.push_back(tmp);
		first = second;
		second = tmp;
		tmp = 0;
	}
}

std::vector<long long int>::iterator	isJacobsthal(long long int	num) {
	std::vector<long long int>::iterator	it = std::find(jacobsthal.begin(), jacobsthal.end(), num);
	if (it == jacobsthal.end()) {
		throw std::runtime_error("Number not in Jacobsthal Suite");
	}
	return (it);
}


/// Discard doubles, as per "we shall also confine our discussion to the cas of distinct keys, so that there are only two possible outcomes of any conversions [...] either Ki < Kj or Ki > Kj" (page 181)
void	parseArgs(char* args[], int argc) {

	for (int i = 1 ; i < argc ; i++) {
		std::string	tmp = args[i];
		std::stringstream	ss(tmp);
		long long int	num;
		ss >> num;
		if (num < 0) {
			throw std::runtime_error("Negative value in arguments");
		} else {

		}
	}
}

/*
int	main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;
	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
		return (1);
	} else if (argc == 2) {
		std::string	option = argv[1];
		if (option == "--version") {
			std::cout << "CPP09/ex02 v.2.3, made by apetitco" << std::endl;
			return (0);
		}

		
		try {
			parseArgs(argv, argc);
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		populateJacobsthal();
		std::vector<long long int>	container1;
		std::deque<long long int>	container2;
	}


	return (0);
}
*/

int	main(void) {
	std::pair<int, int>	pairs[MAXPAIRS];

	std::srand(std::clock());

	for (int i = 0; i < MAXPAIRS; i++) {
		pairs[i].first = std::rand() % 900;
		pairs[i].second = std::rand()% 900;
	}

	sortPairs(pairs);

}
