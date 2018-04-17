#ifndef HISTOGRAPH_H_
#define HISTOGRAPH_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <string>

std::vector<std::string> parseInput(std::ifstream&);          //reads input file into a vector as lowercase words 
std::map<std::string, int> countInstances(std::vector<std::string>);          //stores unique words and their counts in a map
std::multimap<int, std::string> sort(std::map<std::string, int>);          //stores histograph in a multimap with the wordcount as key and word as value
void printOutput(std::ofstream&, std::multimap<int, std::string>);          //prints wordcount and associated word to output file in descending order
int longestString(std::multimap<int, std::string>);         //returns the size of the longest word 

#endif /*HISTOGRAPH_H_*/