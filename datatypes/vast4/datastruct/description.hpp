//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_DESCRIPTION_HPP
#define CVAST_DESCRIPTION_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct Description : VB<Description> {
    private:
        void setValue () {
            this->value = this->node->value();
        }

    public:
        std::string value;

        Description* get () {
            return this;
        }
    };
}

#endif //CVAST_DESCRIPTION_HPP
