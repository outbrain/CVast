
#ifndef CVAST_PRICING_HPP
#define CVAST_PRICING_HPP

namespace Cvast {
    namespace Vast4 {
        struct PricingAttrs {
            PRICING_MODEL model;
            CURRENCY currency;
        };

        struct Pricing : VB<Pricing> {
            PricingAttrs attrs;
            double value;

            Pricing () : VB("", A_DOUBLE, true, &(this->value)) {
                this->symbols.emplace_back("model", A_PRICING_MODEL, true, &(this->attrs.model));
                this->symbols.emplace_back("currency", A_CURRENCY, true, &(this->attrs.currency));
            }
        };
    }
}

#endif //CVAST_PRICING_HPP
