//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_PRICING_HPP
#define CVAST_PRICING_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct PricingAttrs {
        PRICING_MODEL model;
        CURRENCY currency;
    };

    struct Pricing : VB<Pricing> {
    private:
        void setValue () {
            this->value = VastUtils::castStringToDbl(this->node->value());
        }

        void setAttributes() {
            if (this->attributes.find("model") != this->attributes.end()) {
                PRICING_MODEL model(this->attributes["model"]);
                this->attrs.model = model;
            }
            if (this->attributes.find("currency") != this->attributes.end()) {
                CURRENCY currency(this->attributes["currency"]);
                this->attrs.currency = currency;
            }
        }

    public:
        PricingAttrs attrs;
        double value;

        Pricing* get () {
            return this;
        }
    };
}

#endif //CVAST_PRICING_HPP
