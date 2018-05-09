
#ifndef CVAST_CREATIVE_HPP
#define CVAST_CREATIVE_HPP

#include "universalAdId.hpp"
#include "creativeExtensions.hpp"
#include "linear.hpp"
#include "nonLinearAds.hpp"
#include "companionAds.hpp"

namespace Cvast {
    namespace Vast4 {
        struct CreativeAttrs {
            string id;
            string adId;
            unsigned short sequence;
            string apiFramework;
        };

        struct Creative : VB<Creative> {
            CreativeAttrs attrs;
            vector<UniversalAdId> universalAdId;
            vector<CreativeExtensions> creativeExtensions;
            vector<Linear> linear;
            vector<NonLinearAds> nonLinearAds;
            vector<CompanionAds> companionAds;

            Creative () {
                {
                    NodeWrapper<UniversalAdId, vector<UniversalAdId>> wrapper("universalAdId", false, true, this->universalAdId);
                    this->childs.insert(make_pair("UNIVERSALADID", wrapper));
                }

                {
                    NodeWrapper<CreativeExtensions, vector<CreativeExtensions>> wrapper("creativeExtensions", false, false, this->creativeExtensions);
                    this->childs.insert(make_pair("CREATIVEEXTENSIONS", wrapper));
                }

                {
                    NodeWrapper<Linear, vector<Linear>> wrapper("linear", false, false, this->linear);
                    this->childs.insert(make_pair("LINEAR", wrapper));
                }

                {
                    NodeWrapper<NonLinearAds, vector<NonLinearAds>> wrapper("nonLinearAds", false, false, this->nonLinearAds);
                    this->childs.insert(make_pair("NONLINEARADS", wrapper));
                }

                {
                    NodeWrapper<CompanionAds, vector<CompanionAds>> wrapper("companionAds", false, false, this->companionAds);
                    this->childs.insert(make_pair("COMPANIONADS", wrapper));
                }

                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
                this->symbols.emplace_back("adId", A_STRING, false, &(this->attrs.adId));
                this->symbols.emplace_back("sequence", A_SHORT, false, &(this->attrs.sequence));
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
            }

            void onCreation () {
                if (!this->childs["LINEAR"].exists && !this->childs["NONLINEARADS"].exists)
                    ErrorsHandler::err(ErrorsHandler::INVALID_VAST, "A Linear or NonLinearAds tag must be provided in Creative tag");
            }
        };
    }
}

#endif //CVAST_CREATIVE_HPP
