
#ifndef CVAST_UNIVERSALADID_HPP
#define CVAST_UNIVERSALADID_HPP

namespace Cvast {
    namespace Vast4 {
        struct UniversalAdIdAttrs {
            string idRegistry;
            string idValue;
        };

        struct UniversalAdId : VB<UniversalAdId> {
            UniversalAdIdAttrs attrs;
            string value;

            UniversalAdId () : VB("", A_STRING, true, &(this->value)) {
                this->symbols.emplace_back("idRegistry", A_STRING, true, &(this->attrs.idRegistry));
                this->symbols.emplace_back("idValue", A_STRING, true, &(this->attrs.idValue));
            }
        };
    }
}

#endif //CVAST_UNIVERSALADID_HPP
