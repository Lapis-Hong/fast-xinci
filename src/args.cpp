//
// Created by Lapis-Hong  on 2018/6/21.
//
#include <iostream>
#include <stdlib.h>
#include "args.h"

namespace xinci {

Args::Args() {
    input = "test.txt";
    output = "result.txt";
    commonWordsDic = "common.dic";
    minCandidateLen = 2;
    maxCandidateLen = 5;
    leastWordCount = 5;
    solidRate = 0.018;
    entropyRate = 1.92;
    allWords = false;
}

void Args::parseArgs(const std::vector<std::string> &args) {
    std::string command(args[1]);
    for (int ai = 1; ai < args.size(); ai += 2) {
        if (args[ai][0] != '-') {
            std::cerr << "Provided argument without a dash! Usage:" << std::endl;
            printHelp();
            exit(EXIT_FAILURE);
        }
        try {
            if (args[ai] == "-h") {
                printHelp();
                exit(EXIT_FAILURE);
            } else if (args[ai] == "-input") {
                input = std::string(args.at(ai + 1));
            } else if (args[ai] == "-output") {
                output = std::string(args.at(ai + 1));
            } else if (args[ai] == "-commonWordsDic") {
                commonWordsDic = std::string(args.at(ai + 1));
            } else if (args[ai] == "-minCandidateLen") {
                minCandidateLen = std::stoi(args.at(ai + 1));
            } else if (args[ai] == "-maxCandidateLen") {
                maxCandidateLen = std::stoi(args.at(ai + 1));
            } else if (args[ai] == "-leastWordCount") {
                leastWordCount = std::stoi(args.at(ai + 1));
            } else if (args[ai] == "-solidRate") {
                solidRate = std::stof(args.at(ai + 1));
            } else if (args[ai] == "-entropyRate") {
                entropyRate = std::stof(args.at(ai + 1));
            } else if (args[ai] == "-a") {
                allWords = true;
                ai--;
            } else {
                std::cerr << "Unknown argument: " << args[ai] << std::endl;
                printHelp();
                exit(EXIT_FAILURE);
            }
        } catch (std::out_of_range) {
            std::cerr << args[ai] << " is missing an argument" << std::endl;
            printHelp();
            exit(EXIT_FAILURE);
        }
    }
    if (input.empty() || output.empty()) {
        std::cerr << "Empty input or output path." << std::endl;
        printHelp();
        exit(EXIT_FAILURE);
    }
}

void Args::printArgs() {
    std::cout
            << "Using following arguments:\n"
            << "  -input            " << input << "\n"
            << "  -output           " << output << "\n"
            << "  -commonWordsDic   " << commonWordsDic << "\n"
            << "  -minCandidateLen  " << minCandidateLen << "\n"
            << "  -maxCandidateLen  " << maxCandidateLen << "\n"
            << "  -leastWordCount   " << leastWordCount << "\n"
            << "  -solidRate        " << solidRate << "\n"
            << "  -entropyRate      " << entropyRate << "\n"
            << "  -a                " << allWords << std::endl;


}
void Args::printHelp() {
    std::cerr << "Usage: \n\txinci <args>\n"
            << "\nThe following arguments are mandatory:\n"
            << "  -input              input corpus file path\n"
            << "\nThe following arguments are optional:\n"
            << "  -output             output result file path [" << output << "]\n"
            << "  -commonWordsDic     common words dic file path [" << commonWordsDic << "]\n"
            << "  -minCandidateLen    min candidate word length [" << minCandidateLen << "]\n"
            << "  -maxCandidateLen    max candidate word length [" << maxCandidateLen << "]\n"
            << "  -leastWordCount     least word count threshold [" << leastWordCount << "]\n"
            << "  -solidRate          solid rate threshold [" << solidRate << "]\n"
            << "  -entropyRate        entropy rate threshold [" << entropyRate << "]\n"
            << "  -a                  set to all words mode, otherwise only new words [" << allWords << "]\n";
            //<< "  -verbose            verbosity level [" << verbose << "]\n";

}


//    void Args::save(std::ostream &out) {
//        out.write((char *) &(dim), sizeof(int));
//        out.write((char *) &(ws), sizeof(int));
//        out.write((char *) &(epoch), sizeof(int));
//        out.write((char *) &(minCount), sizeof(int));
//        out.write((char *) &(neg), sizeof(int));
//        out.write((char *) &(wordNgrams), sizeof(int));
//        out.write((char *) &(loss), sizeof(loss_name));
//        out.write((char *) &(model), sizeof(model_name));
//        out.write((char *) &(bucket), sizeof(int));
//        out.write((char *) &(minn), sizeof(int));
//        out.write((char *) &(maxn), sizeof(int));
//        out.write((char *) &(lrUpdateRate), sizeof(int));
//        out.write((char *) &(t), sizeof(double));
//    }
//
//    void Args::load(std::istream &in) {
//        in.read((char *) &(dim), sizeof(int));
//        in.read((char *) &(ws), sizeof(int));
//        in.read((char *) &(epoch), sizeof(int));
//        in.read((char *) &(minCount), sizeof(int));
//        in.read((char *) &(neg), sizeof(int));
//        in.read((char *) &(wordNgrams), sizeof(int));
//        in.read((char *) &(loss), sizeof(loss_name));
//        in.read((char *) &(model), sizeof(model_name));
//        in.read((char *) &(bucket), sizeof(int));
//        in.read((char *) &(minn), sizeof(int));
//        in.read((char *) &(maxn), sizeof(int));
//        in.read((char *) &(lrUpdateRate), sizeof(int));
//        in.read((char *) &(t), sizeof(double));
//    }
//
//    void Args::dump(std::ostream &out) const {
//        out << "dim" << " " << dim << std::endl;
//        out << "ws" << " " << ws << std::endl;
//        out << "epoch" << " " << epoch << std::endl;
//        out << "minCount" << " " << minCount << std::endl;
//        out << "neg" << " " << neg << std::endl;
//        out << "wordNgrams" << " " << wordNgrams << std::endl;
//        out << "loss" << " " << lossToString(loss) << std::endl;
//        out << "model" << " " << modelToString(model) << std::endl;
//        out << "bucket" << " " << bucket << std::endl;
//        out << "minn" << " " << minn << std::endl;
//        out << "maxn" << " " << maxn << std::endl;
//        out << "lrUpdateRate" << " " << lrUpdateRate << std::endl;
//        out << "t" << " " << t << std::endl;
//    }

}