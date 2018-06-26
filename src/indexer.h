//
// Created by Lapis-Hong  on 2018/6/20.
//

#ifndef XINCI_INDEXER_H
#define XINCI_INDEXER_H

#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace xinci {

class CnTextIndexer {
    std::string document_;
    long docLen_;

    void initCharMapping();

public:
    CnTextIndexer(std::string document);
    std::map<char, std::vector<int>> charPosMap;
    std::map<char, std::size_t> charCntMap;

    int count(std::string target);
    std::vector<int> find(std::string target);
    char at(int index);
};

}

#endif //XINCI_INDEXER_H
