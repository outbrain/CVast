
#ifndef CVAST_MEZZANINE_HPP
#define CVAST_MEZZANINE_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct Mezzanine : VB<Mezzanine> {
            URL value;

            Mezzanine () : VB("", A_URL, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_MEZZANINE_HPP
