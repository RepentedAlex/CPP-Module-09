#include "PmergeMe.hpp"

std::vector<std::size_t>&	getJacobsthal(std::size_t size) {
  static std::vector<std::size_t>	jacobsthal;
  static bool					initialised = false;

  if (!initialised) {
    std::size_t first = 0;
    std::size_t second = 1;
    std::size_t	tmp = 0;

    jacobsthal.push_back(first);
    jacobsthal.push_back(second);
    while (true) {
      tmp = (first * 2) + second;
      if (tmp > size / 2) {
	break;
      }
      jacobsthal.push_back(tmp);
      first = second;
      second = tmp;
    }
    initialised = true;
  }
  return (jacobsthal);
}

template <typename T, class C>
C	sortFunction(const C& input) {
  (void)input;
  C<std::pair<T, T> >	pairContainer;
}

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
