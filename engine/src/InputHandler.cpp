#include "../include/InputHandler.h"
#include <stdexcept>
#include <cctype>

InputHandler::InputHandler() {}

InputHandler::InputHandler(string_view prompt, vector<string_view> allowed_inputs) {
    this->prompt = prompt;
    this->allowed_inputs = allowed_inputs;
}

void InputHandler::SetPrompt(string_view prompt)  {
    this->prompt = prompt;
}

void InputHandler::SetAllowedInputs(vector<string_view> allowed_inputs) {
    this->allowed_inputs = allowed_inputs;
}

string_view InputHandler::GetPrompt() {
    return this->prompt;
}

vector<string_view> InputHandler::GetAllowedInput() {
    return this->allowed_inputs;
}
    
bool InputHandler::ValidateInput(string_view input, InputCondition condition) {
    if(input.size() == 0) {
        return false;
    }

    int (*func)(int) = nullptr;

    switch(condition) {
        case IS_LETTER:
            func = static_cast<int (*)(int)>(&std::isalpha);
            break;
        case IS_NUMBER:
            func = static_cast<int (*)(int)>(&std::isdigit);
            break;
        default:
            throw std::runtime_error("No input condition checking was provided");
    }

    if(func == nullptr) {
        throw std::runtime_error("failed to assign function ptr");
    }

    for(std::size_t i = 0; i < input.size(); i++) {
        if(func(static_cast<unsigned char>(input[i])) == 0) {
            return false;
        }
    }

    return true;
}