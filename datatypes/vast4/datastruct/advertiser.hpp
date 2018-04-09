//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_ADVERTISER_HPP
#define CVAST_ADVERTISER_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct Advertiser : VB<Advertiser> {
    private:
        void setValue () {
            this->value = this->node->value();
        }

    public:
        std::string value;

        Advertiser* get () {
            return this;
        }
    };
}

#endif //CVAST_ADVERTISER_HPP
