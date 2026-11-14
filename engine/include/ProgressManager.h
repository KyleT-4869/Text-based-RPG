#pragma once
#include <string_view>
#include <cstddef>
#include <ScriptReader.h>

using string_view = std::string_view;
using size_t = std::size_t;

enum ACT {
    ACT1,
    ACT2,
    ACT3,
};

class StorySchema {
    private:
        string_view act1_file_path;
        string_view act2_file_path;
        string_view act3_file_path;
    
    public:
        StorySchema();
        StorySchema(string_view file_path);
        void CreateStorySchema();
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