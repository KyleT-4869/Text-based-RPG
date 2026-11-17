#pragma once
#include <string_view>
#include <string>

using string_view = std::string_view;
using string = std::string;

namespace FileHandler {
    void WriteToFile(string_view content, const char *file_name);
    string ReadFromFile(const char *file_name);
};