#include "counter.h"

int main(int argc, char *argv[]) {
    Counter counter; //Create object

    if (argc != 3) {
        std::cerr << "Check the number of arguments!" << std::endl;
        return 1;
    }

    //Do some work
    std::string inputFileName(argv[1]);
    std::string outputFileName(argv[2]);

    try {
        counter.read(inputFileName);
        counter.sortAndWrite(outputFileName);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    //Return
    return 0;
}