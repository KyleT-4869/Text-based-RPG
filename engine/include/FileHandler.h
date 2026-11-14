#pragma once
#include <string_view>

using string_view = std::string_view;

class FileHandler {
    public:
        void WriteToFile(string_view file_path);
        void ReadFromFile(string_view file_path);
};