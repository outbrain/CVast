
#ifndef CVAST_COMPANIONADS_HPP
#define CVAST_COMPANIONADS_HPP

#include "companion.hpp"

namespace Cvast {
    namespace Vast4 {
        struct CompanionAdsAttrs {
            string required;
        };

        struct CompanionAds: VB<CompanionAds> {
            CompanionAdsAttrs attrs;
            vector<Companion> companions;

            CompanionAds () {
                {
                    NodeWrapper<Companion, vector<Companion>> wrapper("companions", true, false, this->companions);
                    this->childs.insert(make_pair("COMPANION", wrapper));
                }

                this->symbols.emplace_back("required", A_STRING, false, &(this->attrs.required));
            }
        };
    }
}

#endif //CVAST_COMPANIONADS_HPP
