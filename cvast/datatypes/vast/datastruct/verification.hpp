
#ifndef CVAST_VERIFICATION_HPP
#define CVAST_VERIFICATION_HPP

#include "resource.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct VerificationAttrs {
            URL vendor;
        };

        struct Verification : VB<Verification> {
            VerificationAttrs attrs;
            vector<JavascriptResource> javascriptResource;
            vector<FlashResource> flashResource;
            vector<ViewableImpression> viewableImpression;

            Verification () {
                {
                    NodeWrapper<JavascriptResource, vector<JavascriptResource>> wrapper("javascriptResource", true, false, this->javascriptResource);
                    this->childs.insert(make_pair("JAVASCRIPTRESOURCE", wrapper));
                }

                {
                    NodeWrapper<FlashResource, vector<FlashResource>> wrapper("flashResource", true, false, this->flashResource);
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
