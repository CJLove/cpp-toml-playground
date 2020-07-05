#pragma once
#include <string>
#include <vector>
#include <map>

#include "toml.hpp"

// Sample user-provided datatype matching ../inputs/sample.toml

// See https://github.com/ToruNiina/toml11#conversion-between-toml-value-and-arbitrary-types

struct Sample {
    std::string top_string;
    int top_int;
    bool top_bool;

    std::vector<std::string> top_array;

    std::map<std::string, std::string> top_table;

    std::vector<std::vector<std::string>> nested_array;

    std::map<std::string, std::map<std::string, std::string>> nested_table;

    bool operator==(const Sample &rhs) const;

};

std::ostream &operator<<(std::ostream &os, const Sample &s);


// Implement specialization of toml::from for struct Sample
namespace toml
{
    template<>
    struct from<Sample>
    {
        static Sample from_toml(const value& v)
        {
            Sample s;
            s.top_string = find<std::string>(v,"top-string");
            s.top_int    = find<int>(v,"top-int");
            s.top_bool   = find<bool>(v,"top-bool");

            s.top_array   = find<std::vector<std::string>>(v,"top-array");

            s.nested_array = find<std::vector<std::vector<std::string>>>(v,"nested-array");

            s.top_table = find<std::map<std::string,std::string>>(v,"top-table");

            s.nested_table = find<std::map<std::string,std::map<std::string,std::string>>>(v,"nested-table");

            return s;           
        }
    };
}