
#include "../../cvast/cvast.hpp"
#include "requirements.h"

using namespace std;

Requirements::Requirements (const string& content, int idx) {
    try {
        Cvast::C_vast cvast(content);
        this->errors.emplace_back("Vast xml should be invalid");
    } catch (...) {}

    this->printErrors();
}