#include <iostream>
#include "celeba_crop.h"

int main() {
//    celeba_crop test;
//    test.run();

    std::fstream file("/Users/lixile/Documents/dataset/negative_face/train_non_face/filename.txt");
    std::ofstream file_out;
    file_out.open("/Users/lixile/Documents/dataset/negative_face/train_non_face/bounding_box.txt");

    while (!file.eof()) {
        string line;
        getline(file, line);
        if (line == "")
            continue;
        file_out << "0 0 0 0" << std::endl;
    }

    return 0;
}