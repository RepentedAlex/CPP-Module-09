#include <algorithm>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PmergeMe.hpp"


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
  std::deque<int64_t>	deq;

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
  getJacobsthal(vec.size());	//< Initialising Jacobsthal sequence.

  return (0);
}
