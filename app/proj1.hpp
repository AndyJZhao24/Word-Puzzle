#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <map>
#include <set>
#include <list>
#include <string>

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
 */


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping);


bool recursiveSolve(const std::string& s1, const std::string& s2, const std::string& s3, bool& is_solution, const std::set<char>& distinct_chars, int num_dist_chars, std::string& S, std::list<char> U, std::map<char, unsigned> & mapping);

bool verifySolution(const std::string& s1, const std::string& s2, const std::string& s3, const std::map<char, unsigned> & mapping);

int string_to_int(const std::string& s, const std::map <char, unsigned> & mapping);


#endif