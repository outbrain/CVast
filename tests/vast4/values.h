
#ifndef CVAST_VALUES_H
#define CVAST_VALUES_H

#include "../../cvast/cvast.hpp"
#include "validate.h"

class Values : public Validate {
public:
    Values(const std::string& content, int idx);
    void test_1 (Cvast::C_vast& cvast);
    void test_2 (Cvast::C_vast& cvast);
};

#endif //CVAST_VALUES_H
