
#ifndef CVAST_ADVERIFICATIONS_HPP
#define CVAST_ADVERIFICATIONS_HPP

#include "verification.hpp"
#include "resource.hpp"

namespace Cvast {
    namespace Vast4 {
        struct AdVerifications : VB<AdVerifications> {
            vector<Verification> verification;

            AdVerifications () {
                {
                    NodeWrapper<Verification, vector<Verification>> wrapper("verification", true, false, this->verification);
                    this->childs.insert(make_pair("VERIFICATION", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_ADVERIFICATIONS_HPP
