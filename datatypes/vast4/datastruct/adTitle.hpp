//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_ADTITLE_HPP
#define CVAST_ADTITLE_HPP

namespace Vast4 {
    struct AdTitle : VB<AdTitle> {
    private:
        void setValue () {
            this->value = this->node->value();
        }

    public:
        std::string value;

        AdTitle* get () {
            return this;
        }
    };
}

#endif //CVAST_ADTITLE_HPP
