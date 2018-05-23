
#ifndef CVAST_IMPRESSION_HPP
#define CVAST_IMPRESSION_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct ImpressionAttrs {
            string id;
        };

        struct Impression : VB<Impression> {
            ImpressionAttrs attrs;
            URL value;

            Impression () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };
    }
}

#endif //CVAST_IMPRESSION_HPP
