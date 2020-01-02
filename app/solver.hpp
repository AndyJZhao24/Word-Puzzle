#ifndef __SOLVER__HPP
#define __SOLVER__HPP

#include <map>
#include <set>
#include <list>
#include <string>
#include <iostream>


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping);


bool recursiveSolve(const std::string& s1, const std::string& s2, const std::string& s3, bool& is_solution, const std::set<char>& distinct_chars, int num_dist_chars, std::string& S, std::list<char> U, std::map<char, unsigned> & mapping);

bool verifySolution(const std::string& s1, const std::string& s2, const std::string& s3, const std::map<char, unsigned> & mapping);

int string_to_int(const std::string& s, const std::map <char, unsigned> & mapping);


#endif