#include "histograph.h"

std::vector<std::string> parseInput(std::ifstream &fin) {
    std::string line;
    std::vector<std::string> words;

    while(getline(fin, line)) {
        std::string tempString;

        for(int i=0; i < line.size(); i++) {
            line[i] = tolower(line[i]);

            if(line[i] >= 'a' && line[i] <= 'z')
                tempString += line[i];

            else if(std::isspace(line[i]) && tempString != "") {
                words.push_back(tempString);
                tempString.clear();
            }
        }
        if(tempString != "")
            words.push_back(tempString);
    }
    return words;
}


std::map<std::string, int> countInstances(std::vector<std::string> inputText) {
    std::map<std::string, int> tempMap;

    for(int i=0; i < inputText.size(); i++) {
        if(tempMap.count(inputText[i]) == 0)
            tempMap[inputText[i]] = 1;
        else
            tempMap[inputText[i]]++;
    }
    return tempMap;
}


std::multimap<int, std::string> sort(std::map<std::string, int> histograph) {
    std::multimap<int, std::string> sortedHist;

    for(std::map<std::string, int>::iterator it = histograph.begin(); it != histograph.end(); it++)
        sortedHist.insert(make_pair(it -> second, it -> first));

    return sortedHist;
}


void printOutput(std::ofstream &fout, std::multimap<int, std::string> sortedHist) {
    for(std::multimap<int, std::string>::reverse_iterator rit = sortedHist.rbegin(); rit != sortedHist.rend(); rit++) {
        fout << std::setw(longestString(sortedHist)) << std::right << rit -> second << " | ";

        for(int i=0; i < rit -> first; i++)
            fout << "=";

        fout << " (" << rit -> first << ")\n";
    }
}


int longestString(std::multimap<int, std::string> words) {
    size_t maxLength = 0;

    for(std::multimap<int, std::string>::iterator it = words.begin(); it != words.end(); it++) {
        if(it -> second.length() > maxLength)
            maxLength = it -> second.length();
    }
    return maxLength;
}