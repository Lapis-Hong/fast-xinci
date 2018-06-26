//
// Created by Lapis-Hong  on 2018/6/20.
//
#include <iostream>
#include <fstream>
#include "dictionary.h"

namespace xinci {

Dictionary::Dictionary(
    std::string common_dic_path)
    : COMMON_DIC_PATH(common_dic_path) {
    init();
}

void Dictionary::init() {
    std::ifstream in (COMMON_DIC_PATH);  // ifstream in; in.open(COMMON_DIC_PATH
    assert (in.is_open());
    // if (!in) std::cout << "error" << std::endl;
    std::string s;
    int count = 0;
    while (getline(in, s)) {
        vocab_.insert(s);
        count += 1;
    }
    std::cout << "Read " << count << " common words." << std::endl;
    in.close();
}

bool Dictionary::find(std::string str) {
    return vocab_.find(str) != vocab_.end();

}

}