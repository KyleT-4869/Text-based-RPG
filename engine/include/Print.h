#pragma once
#include <string_view>

using string_view = std::string_view;

class Print {
    public:
        Print();
        void PrintArrow();
        void PrintContent(string_view content);
    
};