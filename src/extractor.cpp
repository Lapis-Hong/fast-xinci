//
// Created by Lapis-Hong  on 2018/6/21.
//
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <time.h>
#include "indexer.h"
#include "extractor.h"
#include "selector.h"
#include "model.h"


namespace xinci{

WordExtractor::WordExtractor(
        std::string document, std::string output, Dictionary dictionary,
        int minCandidateLen, int maxCandidateLen,
        int leastwordCount, double solidRate,
        double entropy, bool allWords)
        :document_(document), output_(output), dictionary_(dictionary),
         minCandidateLen_(minCandidateLen), maxCandidateLen_(maxCandidateLen),
         leastWordCount_(leastwordCount), solidRate_(solidRate),
         entropy_(entropy), allWords_(allWords){}

void WordExtractor::extract() {
    clock_t start, end;
    start = clock();
    int length = document_.size();
    std::set<std::string> stopwords = {"我", "你", "您", "他", "她", "谁", "哪", "那", "这",
                                       "的", "了", "着", "也", "是", "有", "不", "在", "与",
                                       "呢", "啊", "呀", "吧", "嗯", "哦", "哈", "呐"};
    std::set<std::string> words;
    CnTextIndexer indexer (document_);
    CnTextSelector selector (document_, maxCandidateLen_, minCandidateLen_);
    EntropyJudger judger (document_, leastWordCount_, solidRate_, entropy_);
    std::string candidate;
    while (!selector.end()) {
        candidate = selector.next();
        // std::cout << candidate << std::endl;

//            if (stopwords.find(candidate.at(0)) != stopwords.end() ||
//                stopwords.find(candidate.at(-1)) != stopwords.end()) {
//                continue;
//            }
        if (words.find(candidate) != words.end()) {
            continue;
        }
        if (!allWords_) {
            if (dictionary_.find(candidate)) {
                continue;
            }
        }
        if (judger.judge(candidate)) {
            words.insert(candidate);
        }
    }
    end = clock();
    std::cout << "Document Length: " << length << std::endl;
    std::cout << "Time Cost: " << (end-start)/1000 << "s" << std::endl;
    std::cout << "New words size: " << words.size() << std::endl;
    std::cout << "发现" << words.size() << "个新词如下:\n@新词\t@词频\n" << std::endl;

    std:: ofstream out (output_);
    assert (out.is_open());
    for (auto &w : words) {
        std::cout << w << "\t" << indexer.count(w) << std::endl;
        out << w << "\t" << indexer.count(w) << std::endl;
    }
    out.close();


}

}