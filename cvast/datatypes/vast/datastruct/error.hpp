
#ifndef CVAST_ERROR_HPP
#define CVAST_ERROR_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct Error : VB<Error> {
            URL value;

            Error () : VB("", A_STRING, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_ERROR_HPP
