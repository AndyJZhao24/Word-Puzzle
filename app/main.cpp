#include "solver.hpp"

int main()
{
	std::string w1, w2, w3;
	std::map<char, unsigned> mapping;

	std::cout << "Please enter your first word: ";
	std::cin >> w1;
	std::cout << "Please enter your second word: ";
	std::cin >> w2;
	std::cout << "Please enter your third word: ";
	std::cin >> w3;

	if (puzzleSolver(w1, w2, w3, mapping))
	{
		for(auto it = mapping.begin(); it != mapping.end(); it++)
		{
			std::cout << it->first << " : " << it->second << std::endl;
		}
	}
	else
	{
		std::cout << "No solution";
	}

    return 0;
}



