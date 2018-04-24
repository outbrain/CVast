
#ifndef CVAST_VERIFICATION_HPP
#define CVAST_VERIFICATION_HPP

#include "resource.hpp"

namespace Cvast {
    namespace Vast4 {
        struct VerificationAttrs {
            URL vendor;
        };

        struct Verification : VB<Verification> {
            VerificationAttrs attrs;
            vector<JavascriptResource> javascriptResources;
            vector<FlashResource> flashResources;
            vector<ViewableImpression> viewableImpression;

            Verification () {
                {
                    NodeWrapper<JavascriptResource, vector<JavascriptResource>> wrapper("javascriptResources", true, false, this->javascriptResources);
                    this->childs.insert(make_pair("JAVASCRIPTRESOURCE", wrapper));
                }

                {
                    NodeWrapper<FlashResource, vector<FlashResource>> wrapper("flashResources", true, false, this->flashResources);
                    this->childs.insert(make_pair("FLASHRESOURCE", wrapper));
                }

                {
                    NodeWrapper<ViewableImpression, vector<ViewableImpression>> wrapper("viewableImpression", false, false, this->viewableImpression);
                    this->childs.insert(make_pair("VIEWABLEIMPRESSION", wrapper));
                }

                this->symbols.emplace_back("vendor", A_URL, false, &(this->attrs.vendor));
            }
        };
    }
}

#endif //CVAST_VERIFICATION_HPP
