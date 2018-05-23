
#ifndef CVAST_VASTADTAGURI_HPP
#define CVAST_VASTADTAGURI_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct VastAdTagUri: VB<VastAdTagUri> {
            URL value;

            VastAdTagUri () : VB("", A_URL, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_VASTADTAGURI_HPP
