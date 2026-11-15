#pragma once
#include <string_view>
#include <string>
#include <cstddef>
#include <ScriptReader.h>

using string_view = std::string_view;
using string = std::string;
using size_t = std::size_t;

enum ACT {
    ACT1,
    ACT2,
    ACT3,
};

class StorySchema {
    private:
        string act1_file_path;
        string act2_file_path;
        string act3_file_path;
    
    public:
        StorySchema();
        void SetStorySchema();
        void CreateStorySchema(string_view act1_file_path, string_view act2_file_path, string_view act3_filepath);
};

class ProgressManager {
    private:
        ACT current_act;
        size_t last_read_position;
        ScriptReader script_reader;

    public:
        ProgressManager();
        ProgressManager(ACT current_act, size_t last_read_position, ScriptReader scrip_reader);
        void SetAct(ACT current_act);
        void SetLastReadPosition(size_t last_read_position);
};