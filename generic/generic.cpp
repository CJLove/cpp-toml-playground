#include "toml.hpp"
#include <iostream>
#include <unistd.h>

void usage()
{
    std::cout << "Usage:\n"
              << "generic [-f <file>]\n";
    exit(1);
}


int main(int argc, char**argv)
{
    const char *file = "../inputs/sample.toml";
    int c = 0;
    while ((c = getopt(argc, argv, "f:?")) != EOF)
    {
        switch (c)
        {
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

    const auto topString = toml::find<std::string>(data,"top-string");
    std::cout << "top-string = " << topString << "\n";

    const auto topInt = toml::find<int>(data,"top-int");
    std::cout << "top-int = " << topInt << "\n";

    const auto topArray = toml::find<std::vector<std::string>>(data,"top-array");
    std::cout << "top-array = " << topArray[0] << "\n";

    const auto nestedArray = toml::find(data,"nested-array");
    std::cout << "nested-array = " << nestedArray << "\n";
    std::cout << "nested-array[0][0] = " << nestedArray[0][0] << "\n";

    const auto nestedTable = toml::find(data,"nested-table");
    std::cout << "nested-table.key1.key1-subkey2 = " << toml::find(nestedTable,"key1") << "\n";

    const auto nestedTable2 = toml::find(data,"nested-table2");
    std::cout << "nested-table2 = " << nestedTable2 << "\n";

    const auto key1 = toml::find(nestedTable2,"key1");
    std::cout << "key1 = " << key1 << "\n";

    const auto subkey1 = toml::find(key1,"key1-subkey1");
    std::cout << "key1-subkey1 = " << subkey1 << "\n";
}