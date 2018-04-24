
#ifndef CVAST_DESCRIPTION_HPP
#define CVAST_DESCRIPTION_HPP

namespace Cvast {
    namespace Vast4 {
        struct Description : VB<Description> {
            std::string value;

            Description () : VB("", A_STRING, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_DESCRIPTION_HPP
