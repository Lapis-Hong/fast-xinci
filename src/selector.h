//
// Created by Lapis-Hong  on 2018/6/20.
//

#ifndef XINCI_SELECTOR_H
#define XINCI_SELECTOR_H

#include <string>

namespace xinci {

class CnTextSelector {
    const std::string document_;
    const long docLen_;
    int maxLen_;
    int minLen_;
    int pos_;
    int curLen_ = maxLen_;

  private:
    void adjustCurLen();

  public:
    CnTextSelector(const std::string &document, int maxLen, int minLen);

    std::string next();
    bool end();

};

}

#endif //XINCI_SELECTOR_H
