
#ifndef CVAST_ADSYSTEM_HPP
#define CVAST_ADSYSTEM_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct AdSystemAttrs {
            string version;
        };

        struct AdSystem : VB<AdSystem> {
            AdSystemAttrs attrs;
            string value;

            AdSystem () : VB("", A_STRING, true, &(this->value)) {
                this->symbols.emplace_back("version", A_STRING, false, &(this->attrs.version));
            }
        };
    }
}

#endif //CVAST_ADSYSTEM_HPP
