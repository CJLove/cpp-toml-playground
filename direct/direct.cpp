
#include <iostream>
#include <unistd.h>

#include "toml.hpp"
#include "sample.h"


void usage()
{
    std::cout << "Usage:\n"
    << "direct [-f <file>]\n";
    exit(1);
}

int main(int argc, char**argv)
{
    const char *file = "../inputs/sample.toml";
    int c = 0;

    while ((c = getopt(argc,argv,"f:?")) != EOF) {
        switch (c) {
        case 'f':
            file = optarg;
            break;
        case '?':
            usage();
            break;
        default:
            std::cerr << "Unexpected arg " << (char)c << "\n";
            usage();
        }
    }


    const auto data  = toml::parse(file);
    std::cout << "Loaded " << file << "\n";

    try {

        const Sample sample = toml::get<Sample>(data);

        std::cout << sample;
        
    } catch (std::exception &e) {
        std::cout << "Caught " << e.what() << "\n";
    }
}
