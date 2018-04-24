
#ifndef CVAST_VAST_HPP
#define CVAST_VAST_HPP

#include "../../holder.hpp"
#include "../../vastBase.hpp"
#include "ad.hpp"
#include "error.hpp"

namespace Cvast {
    namespace Vast4 {
        struct VastAttrs {
            double version;
        };

        struct Vast : VB<Vast> {
            VastAttrs attrs;
            vector<Error> errors;
            vector<Ad> ads;

            Vast () {
                {
                    NodeWrapper<Ad, vector<Ad>> wrapper("ads", true, true, this->ads);
                    this->childs.insert(make_pair("AD", wrapper));
                }

                {
                    NodeWrapper<Error, vector<Error>> wrapper("errors", true, false, this->errors);
                    this->childs.insert(make_pair("ERROR", wrapper));
                }


                this->symbols.emplace_back("version", A_DOUBLE, false, &(this->attrs.version));
            }
        };
    }
}

#endif //CVAST_VAST_HPP
