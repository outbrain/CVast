
#ifndef CVAST_ADTITLE_HPP
#define CVAST_ADTITLE_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct AdTitle : VB<AdTitle> {
            std::string value;

            AdTitle () : VB("", A_STRING, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_ADTITLE_HPP
