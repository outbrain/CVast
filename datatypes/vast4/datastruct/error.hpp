//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_ERROR_HPP
#define CVAST_ERROR_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct Error : VB<Error> {
    private:
        void setValue () {
            URL url(this->node->value());
            this->value = url;
        }

    public:
        URL value;

        Error* get () {
            return this;
        }
    };
}

#endif //CVAST_ERROR_HPP
