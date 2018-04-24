
#ifndef CVAST_ADVERTISER_HPP
#define CVAST_ADVERTISER_HPP

namespace Cvast {
    namespace Vast4 {
        struct Advertiser : VB<Advertiser> {
            string value;

            Advertiser () : VB("", A_STRING, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_ADVERTISER_HPP
