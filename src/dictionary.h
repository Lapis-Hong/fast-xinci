//
// Created by Lapis-Hong  on 2018/6/20.
//

#ifndef XINCI_DICTIONARY_H
#define XINCI_DICTIONARY_H

#include <string>
#include <vector>
#include <set>

namespace xinci {

class Dictionary {

    const std::string COMMON_DIC_PATH;

    void init();

  public:
    Dictionary(std::string common_dic_path);

    std::set<std::string> vocab_;

    bool find(std::string);

};
}

#endif //XINCI_DICTIONARY_H
