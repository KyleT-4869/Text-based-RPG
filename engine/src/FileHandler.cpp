#include "../include/FileHandler.h"
#include <fstream>
#include <stdexcept>

void FileHandler::WriteToFile(string_view content, const char *file_name) {
    std::ofstream file {file_name, std::ios::out};

    if(!file) {
        throw std::runtime_error("Unable to open file to write to: ");
    }

    file << content;
}

string FileHandler::ReadFromFile(const char *file_name) {
    std::ifstream file {file_name, std::ios::in};

    if(!file) {
        throw std::runtime_error("Unable to open file to read from");
    }

    
}