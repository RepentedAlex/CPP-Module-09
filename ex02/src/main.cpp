#include <algorithm>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PmergeMe.hpp"


static std::vector<int64_t>	jacobsthal; //< vector holding the Jacobsthal Suite.

void populateJacobsthal() {
  int64_t first = 0;
  int64_t second = 1;
  int64_t tmp = 0;

  jacobsthal.push_back(first);
  jacobsthal.push_back(second);

  for (int i = 2; i < MAX_VAL; i++) {
	tmp = (first * 2) + second;
	jacobsthal.push_back(tmp);
	first = second;
	second = tmp;
	tmp = 0;
  }
}

std::vector<int64_t>::iterator isJacobsthal(int64_t num) {
  std::vector<int64_t>::iterator it =
	std::find(jacobsthal.begin(), jacobsthal.end(), num);
  if (it == jacobsthal.end()) {
	throw std::runtime_error("Number not in Jacobsthal Suite");
  }
  return (it);
}

template <class C>
void parseArgs(char *args[], int argc, C &container) {
  for (int i = 1; i < argc; i++) {
	std::string tmp = args[i];
	std::stringstream strgstrm(tmp);
	int64_t num = 0;
	strgstrm >> num;
	if ( strgstrm.fail() || !strgstrm.eof() || num < 0) {
	  std::stringstream	error;
	  error << "Invalid argument at position" << i << ": '" << tmp << "'";
	  throw std::runtime_error(error.str());
	}
	container.push_back(num);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int64_t>	vec;
  std::deque<int64_t>		deq;

  if (argc < 2) {
	std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
	return (1);
  }
  if (argc == 2) {
	std::string	option = argv[1];
	if (option == "--version") {
	  std::cout << "CPP09/ex02 v." << SUB_VER << ", made by apetitco" << std::endl;
	  return (0);
	}
  }

  try {
	parseArgs(argv, argc, vec);
	parseArgs(argv, argc, deq);
  } catch (const std::runtime_error& e) {
	std::cerr << "Error: " << e.what() << std::endl;
  }

  return (0);
}
