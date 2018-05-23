
#ifndef CVAST_DURATION_HPP
#define CVAST_DURATION_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct Duration : VB<Duration> {
            TIME value;

            Duration () : VB("", A_TIME, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_DURATION_HPP
