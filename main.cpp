#include "histograph.h"

int main(int argc, char const *argv[])
{
    std::ifstream fin;
    fin.open("input.txt");

    if(!fin) {
        std::cerr << "Input file not found" << std::endl;
        return 1;
    }

    std::vector<std::string> inputText = parseInput(fin);
    std::map<std::string, int> histograph = countInstances(inputText);
    std::multimap<int, std::string> sortedHist = sort(histograph);

    std::ofstream fout;
    fout.open("output.txt");

    printOutput(fout, sortedHist);
    return 0;
}