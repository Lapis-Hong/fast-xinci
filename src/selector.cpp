//
// Created by Lapis-Hong  on 2018/6/20.
//
#include <iostream>
#include <string>
#include "selector.h"

namespace xinci{

CnTextSelector::CnTextSelector(
        const std::string &document,
        int maxLen,
        int minLen)
        :document_(document), maxLen_(maxLen), minLen_(minLen),
         pos_(0), docLen_(document.size()) {}

void CnTextSelector::adjustCurLen() {
    curLen_ = pos_ + maxLen_ > docLen_ ? docLen_ - pos_ : maxLen_;
}

std::string CnTextSelector::next() {
    if (curLen_ < minLen_) {
        pos_++;
        adjustCurLen();
    }
    if (!end()) {
        return document_.substr(pos_, curLen_--);
    } else {
        return "";
    }

}

bool CnTextSelector::end() {
    return pos_ + minLen_ >= docLen_ - 1;
}

}
