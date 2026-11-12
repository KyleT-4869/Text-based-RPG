#include "../include/Print.hpp"
#include <iostream>

Print::Print() {}

void Print::PrintArrow() {
    std::cout << "> " ;
}

void Print::PrintContent(string_view content) {
    std::cout << content << "\n";
}