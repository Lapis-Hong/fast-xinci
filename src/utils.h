//
// Created by Lapis-Hong  on 2018/6/20.
//

#ifndef XINCI_UTILS_H
#define XINCI_UTILS_H

#include <string>

namespace xinci {

class TextUtils {

public:
    bool isChinese(std::string s);

    bool isEnglish(std::string s);

    bool isNumeric(std::string s);

    bool isBlank(std::string s);

    static bool match(std::string src, int off, std::string dest);

};

}

#endif //XINCI_UTILS_H
