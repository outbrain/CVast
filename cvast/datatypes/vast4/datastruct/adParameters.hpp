
#ifndef CVAST_ADPARAMETERS_HPP
#define CVAST_ADPARAMETERS_HPP

namespace Cvast {
    namespace Vast4 {
        struct AdParametersAttrs {
            bool xmlEncoded;
        };

        struct AdParameters : VB<AdParameters> {
            AdParametersAttrs attrs;
            string value;

            AdParameters () : VB("", A_STRING, true, &(this->value)) {
                this->symbols.emplace_back("xmlEncoded", A_BOOL, false, &(this->attrs.xmlEncoded));
            }
        };
    }
}

#endif //CVAST_ADPARAMETERS_HPP
