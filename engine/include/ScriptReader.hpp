#pragma once
#include <string>

class ScriptReader {
    private:
        std::string content;
    
    public:
        ScriptReader();
        ScriptReader(const char *script_path);
        void AppendContent(std::string_view content);
        void SetContent(std::string_view content);
};