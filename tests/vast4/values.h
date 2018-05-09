
#ifndef CVAST_VALUES_H
#define CVAST_VALUES_H

#include "../../cvast/cvast_v4.hpp"
#include "validate.h"

class Values : public Validate {
public:
    Values(const std::string& content, int idx);
    void test_1 (Cvast::Cvast_v4& cvast);
    void test_2 (Cvast::Cvast_v4& cvast);
};

#endif //CVAST_VALUES_H
