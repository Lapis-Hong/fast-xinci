//
// Created by Lapis-Hong  on 2018/6/20.
//

#ifndef XINCI_MODEL_H
#define XINCI_MODEL_H

#endif //XINCI_MODEL_H

#include <string>
#include "indexer.h"

namespace xinci {

class EntropyJudger {

    std::string document_;
    const int leastWordCount_;
    const double solidRate_;
    const double entropy_;
    CnTextIndexer indexer;

    double getSolidRate(std::string candidate);
    double getEntropy(std::string candidate);

public:

    EntropyJudger(std::string document, const int leastWordCount, const double solidRate, const double entropy);

    bool judge(std::string candidate);

};

}