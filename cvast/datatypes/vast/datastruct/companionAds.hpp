
#ifndef CVAST_COMPANIONADS_HPP
#define CVAST_COMPANIONADS_HPP

#include "companion.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct CompanionAdsAttrs {
            string required;
        };

        struct CompanionAds: VB<CompanionAds> {
            CompanionAdsAttrs attrs;
            vector<Companion> companion;

            CompanionAds () {
                {
                    NodeWrapper<Companion, vector<Companion>> wrapper("companion", true, false, this->companion);
                    this->childs.insert(make_pair("COMPANION", wrapper));
                }

                this->symbols.emplace_back("required", A_STRING, false, &(this->attrs.required));
            }
        };
    }
}

#endif //CVAST_COMPANIONADS_HPP
