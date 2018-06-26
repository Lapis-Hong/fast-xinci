//
// Created by Lapis-Hong  on 2018/6/21.
//

#ifndef XINCI_ARGS_H
#define XINCI_ARGS_H

#include <istream>
#include <ostream>
#include <string>
#include <vector>

namespace xinci {

class Args {
  public:
    Args();
    std::string input;
    std::string output;
    std::string commonWordsDic;
    int minCandidateLen;
    int maxCandidateLen;
    int leastWordCount;
    double solidRate;
    double entropyRate;
    bool allWords;

    void parseArgs(const std::vector<std::string>& args);
    void printArgs();
    void printHelp();
    void save(std::ostream&);
    void load(std::istream&);
    void dump(std::ostream&) const;
};

}
#endif //XINCI_ARGS_H
