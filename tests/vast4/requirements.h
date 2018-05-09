
#ifndef CVAST_REQUIREMENTS_H
#define CVAST_REQUIREMENTS_H

#include "validate.h"

class Requirements : public Validate {
public:
    Requirements (const std::string& content, int idx);
};


#endif //CVAST_REQUIREMENTS_H
