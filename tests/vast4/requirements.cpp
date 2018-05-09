
#include "../../cvast/cvast_v4.hpp"
#include "requirements.h"

using namespace std;

Requirements::Requirements (const string& content, int idx) {
    try {
        Cvast::Cvast_v4 cvast(content);
        this->errors.push_back("Vast xml should be invalid");
    } catch (...) {}

    this->printErrors();
}