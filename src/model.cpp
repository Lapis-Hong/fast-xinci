//
// Created by Lapis-Hong  on 2018/6/20.
//
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include "model.h"

namespace xinci {

EntropyJudger::EntropyJudger(
        std::string document,
        const int leastWordCnt,
        const double solidRate,
        const double entropy)
        :document_(document), leastWordCount_(leastWordCnt),
        solidRate_(solidRate), entropy_(entropy), indexer(document) {};

bool EntropyJudger::judge(std::string candidate) {
    double solidRate = getSolidRate(candidate);
    double entropy = getEntropy(candidate);
    return solidRate < solidRate_ || entropy < entropy_;
}

double EntropyJudger::getSolidRate(std::string candidate) {
    if (candidate.size() < 2) {
        return 1.0;
    }
    int cnt = indexer.count(candidate);
    if (cnt < leastWordCount_) {
        return 0.0;
    }
    float rate = 0.0;
    for (auto &r: candidate) {
        rate *= cnt / 3; //indexer.charCntMap[r]; // error
    }
    return pow(rate, 1 / candidate.size()) * sqrt(candidate.size());
}

double EntropyJudger::getEntropy(std::string candidate) {
    std::map<std::string, std::size_t> left_char_dic;
    std::map<std::string, std::size_t> right_char_dic;
    std::vector<int> candidate_pos = indexer.find(candidate);
    std::string left_char, right_char;
    for (auto pos: candidate_pos) {
        left_char = indexer.at(pos - 1);
        ++left_char_dic[left_char];
        right_char = indexer.at(pos + candidate.size());
        ++right_char_dic[right_char];

        int left_char_cnt = 0;
        for (auto &w: left_char_dic) {
            left_char_cnt += w.second;
        }
        int right_char_cnt = 0;
        for (auto &w: right_char_dic) {
            right_char_cnt += w.second;
        }
        double l_entropy, r_entropy, p = 0.0;

        for (auto &w: left_char_dic) {
            p = w.second / left_char_cnt; // character frequency as prob
            l_entropy -= p * log(p);
        }
        for (auto &w: right_char_dic) {
            p = w.second / right_char_cnt;
            r_entropy -= p * log(p);
        }
        return std::min(l_entropy, r_entropy);
    }

}

}
