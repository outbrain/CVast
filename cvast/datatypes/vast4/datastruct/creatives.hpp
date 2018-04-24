
#ifndef CVAST_CREATIVES_HPP
#define CVAST_CREATIVES_HPP

#include "creative.hpp"

namespace Cvast {
    namespace Vast4 {
        struct Creatives : VB<Creatives> {
            vector<Creative> creatives;

            Creatives () {
                {
                    NodeWrapper<Creative, vector<Creative>> wrapper("creatives", true, true, this->creatives);
                    this->childs.insert(make_pair("CREATIVE", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_CREATIVES_HPP
