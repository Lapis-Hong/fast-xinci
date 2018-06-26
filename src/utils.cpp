//
// Created by Lapis-Hong  on 2018/6/20.
//
#include "utils.h"

namespace xinci {

bool TextUtils::match(std::string src, int off, std::string dest) {
    int len = dest.size();
    int src_len = src.size();
    for (int i = 0; i < len; i++) {
        if (src_len <= off + i) {
            return false;
        }
        if (dest.at(i) != src.at(off + i)) {
            return false;

        }
    }
    return true;
}
}