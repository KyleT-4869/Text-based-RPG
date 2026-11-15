#include "../include/ProgressManager.h"
#include <fstream>
#include <stdexcept>
#include <string>

StorySchema::StorySchema() {}

void StorySchema::SetStorySchema() {
    std::ifstream file {"../data/story_schema.txt", std::ios::in};

    if(!file.is_open()) {
        throw std::runtime_error("Unable to open story_schema.txt");
    }
    
    string line {};

    while(std::getline(file, line)) {
        if(line == "act1:") {
            std::getline(file, line);
            this->act1_file_path = line;
        }
        else if(line == "act2:") {
            std::getline(file, line);
            this->act2_file_path = line;
        }
        else if(line == "act3:") {
            std::getline(file, line);
            this->act3_file_path = line;
        }
    }
}

void StorySchema::CreateStorySchema(string_view act1_file_path, string_view act2_file_path, string_view act3_file_path) {
    std::ofstream file {"../data/story_schema.txt", std::ios::out};

    if(!file.is_open()) {
        throw std::runtime_error("Unable to open story_schema.txt to write to");
    }

    file << "act1:" << "\n";
    file << act1_file_path << "\n";

    file << "act2:" << "\n";
    file << act2_file_path << "\n";

    file << "act3:" << "\n";
    file << act3_file_path << "\n";
}

