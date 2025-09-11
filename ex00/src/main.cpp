#include <iostream>

#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[]) {
	(void)argv;
	if (argc != 2) {
		std::cerr << "Usage: ./btc <database file>" << std::endl;
	}

	return (0);
}
