//
// Created by Lapis-Hong  on 2018/6/20.
//
#include <string>
#include <vector>
#include "indexer.h"
#include "utils.h"

namespace xinci {

CnTextIndexer::CnTextIndexer(std::string document)
        : document_(document), docLen_(document.size()){
    initCharMapping();
}

void CnTextIndexer::initCharMapping() {
    int pos = 0;
    for (auto &w: document_) {
        ++charCntMap[w];
        charPosMap[w].push_back(pos);
        pos ++;
    }
}

int CnTextIndexer::count(std::string target) {
    if (target.empty()) return 0;
    std::vector<int> index = charPosMap[target.at(0)]; // error
    if (index.size() == 0) return 0;
    if (target.size() == 0) return index.size();
    int cnt = 0;
    for (auto &pos: index) {
        if (TextUtils::match(document_, pos, target)) cnt++;
    }
    return cnt;
}

std::vector<int> CnTextIndexer::find(std::string target) {
    std::vector<int> pos; //empty
    if (target.empty()) return pos;
    std::vector<int> index = charPosMap[target.at(0)];
    if (index.size() == 0) return pos;
    if (target.size() == 0) pos = index;
    for (auto &i: index) {
        if (TextUtils::match(document_, i, target)) {
            pos.push_back(i);
        }
    }
    return pos;
}
 char CnTextIndexer::at(int index) {
    if (index < 0 || index >= document_.size()) {
        return 0;
    }
    return document_[index];
}

}
