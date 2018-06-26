//
// Created by Lapis-Hong  on 2018/6/21.
//

#ifndef XINCI_EXTRACTOR_H
#define XINCI_EXTRACTOR_H

#include <string>
#include <set>
#include "dictionary.h"

namespace xinci {

class WordExtractor {
    std::string document_;
    Dictionary dictionary_;
    int minCandidateLen_;
    int maxCandidateLen_;
    int leastWordCount_;
    double solidRate_;
    double entropy_;
    bool allWords_;


public:
    WordExtractor(std::string document, Dictionary dictionary,
                  int minCandidateLen, int maxCandidateLen,
                  int leastwordCount, double solidRate,
                  double entropy, bool allWords);

    void extract();
};

}


#endif //XINCI_EXTRACTOR_H
