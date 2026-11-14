#pragma once
#include <string>
#include <string_view>
#include <vector>

using string = std::string;
using string_view = std::string_view;

template <typename T>
using vector = std::vector<T>;

enum InputCondition {
    IS_LETTER,
    IS_NUMBER,
};

class InputHandler {
    private:
        string_view prompt;
        vector<string_view> allowed_inputs;
    
    public:
        InputHandler();
        InputHandler(string_view prompt, vector<string_view> allowed_inputs);
        void SetPrompt(string_view prompt);
        void SetAllowedInputs(vector<string_view> allowed_inputs);
        string_view GetPrompt();
        vector<string_view> GetAllowedInput();
        bool ValidateInput(string_view input, InputCondition condition);
};