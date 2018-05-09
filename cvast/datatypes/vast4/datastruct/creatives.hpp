
#ifndef CVAST_CREATIVES_HPP
#define CVAST_CREATIVES_HPP

#include "creative.hpp"

namespace Cvast {
    namespace Vast4 {
        struct Creatives : VB<Creatives> {
            vector<Creative> creative;

            Creatives () {
                {
                    NodeWrapper<Creative, vector<Creative>> wrapper("creative", true, true, this->creative);
                    this->childs.insert(make_pair("CREATIVE", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_CREATIVES_HPP
