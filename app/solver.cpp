#include "solver.hpp"


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	std::list<char> U = {'0','1','2','3','4','5','6','7','8','9'}; //Represents every possible integer that a character could map to.
	std::string S = ""; //String that will be used to store the "character ints" from set U.
	std::set<char> distinct_chars; //Set that will hold the distinct characters from all three strings.

	std::string all_chars = s1 + s2 + s3; //Concatenate the three strings into a single.
	distinct_chars.insert(all_chars.begin(), all_chars.end()); //Inserts every character in the concatenated string into the character set. Sets do not have duplicates.
	int dist_char_len = distinct_chars.size(); //Stores the number of distinct characters in the set.
	bool is_solution = false; //Will be used to check whether there is a solution to the summation puzzle.

	return recursiveSolve(s1, s2, s3, is_solution, distinct_chars, dist_char_len, S, U, mapping); //Returns true if there is solution, else false.
	
}


bool recursiveSolve(const std::string& s1, const std::string& s2, const std::string& s3, bool& is_solution, const std::set<char>& distinct_chars, int num_dist_chars, std::string& S, std::list<char> U, std::map<char, unsigned> & mapping)
{
	for(std::list<char>::iterator it = U.begin(); it != U.end();) //Iterates through the  list of characters until the last element is passed.
	{
		char c = *it; //Saves the int character at the current iterator.

		it = U.erase(it); //Removes the element that the iterator is currently pointing to. The iterator now points to the next value in the list.
		S.push_back(c); //Appends character c to the end of the string.

		if (num_dist_chars == 1) //When number of distinct characters = 1, then this means that we have formed a string of integers of the desired length.
		{
			int k = 0; //Used to index through the string of integers.
			for(std::set<char>::iterator char_it = distinct_chars.begin(); char_it != distinct_chars.end(); char_it++)
			{
				mapping[*char_it] = S[k] - '0'; //Creates a mapping for each characer in the set. *char_it returns an alphabetic character.
				//S[k] returns an integer character from the string. S[k] minus '0' subtracts the two integer characters based on their ASCII value and returns an int
				//equivalent to S[k].
				k++; //Increments the index.
			}
			is_solution = verifySolution(s1, s2, s3, mapping); //Passes the 3 strings as well as the mapping to helper function. is_solution set to true or false.
			if (!is_solution) //If the current string and mapping combination is not a solution.
			{
				mapping.clear(); //Clear the mapping
			}
			else //Current string and mppaing combination is a solution.
			{
				return is_solution; //Return true.
			}
		}
		else //String of integers is not of desired length yet.
		{
			recursiveSolve(s1, s2, s3, is_solution, distinct_chars, num_dist_chars - 1, S, U, mapping); //Recursive call getting closer to the base case.
			if (is_solution) //If a solution was found. This "if" statement will be reached every time after the if(num_dist_chars == 1) block is finished executed.
				return is_solution; //Return true.
		}

		U.insert(it, c); //Insert the int character at the position of the current iterator. However, the iterator still points to the position before insertion.
		S.pop_back(); //Remove the character that was appended to the end of the string.

		if (is_solution) //If a solution was found. This will help return out of the recursive calls sooner.
			return is_solution; //Return true
	}
	return is_solution; //Returns false if all recursive calls were executed and no solution was found, else true.
}



bool verifySolution(const std::string& s1, const std::string& s2, const std::string& s3, const std::map<char, unsigned> & mapping)
{	
	//Each function call converts the string of characters into an int
    return ( (string_to_int(s1, mapping) + string_to_int(s2, mapping)) == string_to_int(s3, mapping)); 
}	


int string_to_int(const std::string& s, const std::map <char, unsigned> & mapping)
{
	std::string str_value = ""; //Integer characters will be appended to the string
	for(int i = 0; i < s.length(); i++)
	{
		str_value += std::to_string(mapping.at(s[i])); //Gets the mapping at index i of string s.
	}

	return std::stoi(str_value); //Convert the integer string into an actual integer.
}

