#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include "../include/ScriptReader.hpp"

ScriptReader::ScriptReader() {}

void ScriptReader::AppendContent(std::string_view content) {
    this->content.append(content);
}

void ScriptReader::SetContent(std::string_view content) {
    this->content = content;
}

ScriptReader::ScriptReader(const char* script_path) {
    std::ifstream script{script_path, std::ios::in};

    if(!script.is_open()) {
        throw std::runtime_error("Failed to load script");
    }

    std::string line;

    while(std::getline(script, line)) {
        this->content.append(line);
        this->content.append("\n");
    }

    if(script.bad()) {
        throw std::runtime_error("Error while reading script");
    }
}