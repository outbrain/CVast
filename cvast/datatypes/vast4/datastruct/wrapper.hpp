
#ifndef CVAST_WRAPPER_HPP
#define CVAST_WRAPPER_HPP

#include "impression.hpp"
#include "vastAdTagUri.hpp"
#include "adSystem.hpp"
#include "pricing.hpp"
#include "error.hpp"
#include "viewableImpression.hpp"
#include "adVerifications.hpp"
#include "extensions.hpp"
#include "creatives.hpp"

namespace Cvast {
    namespace Vast4 {
        struct WrapperAttrs {
            bool followAdditionalWrappers;
            bool allowMultipleAds;
            bool fallbackOnNoAd;
        };

        struct Wrapper: VB<Wrapper> {
            WrapperAttrs attrs;
            vector<Impression> impressions;
            vector<VastAdTagUri> vastAdTagUri;
            vector<AdSystem> adSystem;
            vector<Pricing> pricing;
            vector<Error> errors;
            vector<ViewableImpression> viewableImpression;
            vector<AdVerifications> adVerifications;
            vector<Extensions> extensions;
            vector<Creatives> creatives;

            Wrapper () {
                {
                    NodeWrapper<Impression, vector<Impression>> wrapper("impressions", true, true, this->impressions);
                    this->childs.insert(make_pair("IMPRESSION", wrapper));
                }

                {
                    NodeWrapper<VastAdTagUri, vector<VastAdTagUri>> wrapper("vastAdTagUri", false, true, this->vastAdTagUri);
                    this->childs.insert(make_pair("VASTADTAGURI", wrapper));
                }

                {
                    NodeWrapper<AdSystem, vector<AdSystem>> wrapper("adSystem", false, true, this->adSystem);
                    this->childs.insert(make_pair("ADSYSTEM", wrapper));
                }

                {
                    NodeWrapper<Pricing, vector<Pricing>> wrapper("pricing", false, false, this->pricing);
                    this->childs.insert(make_pair("PRICING", wrapper));
                }

                {
                    NodeWrapper<Error, vector<Error>> wrapper("errors", true, false, this->errors);
                    this->childs.insert(make_pair("ERROR", wrapper));
                }

                {
                    NodeWrapper<ViewableImpression, vector<ViewableImpression>> wrapper("viewableImpression", false, false, this->viewableImpression);
                    this->childs.insert(make_pair("VIEWABLEIMPRESSION", wrapper));
                }

                {
                    NodeWrapper<AdVerifications, vector<AdVerifications>> wrapper("adVerifications", false, false, this->adVerifications);
                    this->childs.insert(make_pair("ADVERIFICATIONS", wrapper));
                }

                {
                    NodeWrapper<Extensions, vector<Extensions>> wrapper("extensions", false, false, this->extensions);
                    this->childs.insert(make_pair("EXTENSIONS", wrapper));
                }

                {
                    NodeWrapper<Creatives, vector<Creatives>> wrapper("creatives", false, false, this->creatives);
                    this->childs.insert(make_pair("CREATIVES", wrapper));
                }

                this->symbols.emplace_back("followAdditionalWrappers", A_BOOL, false, &(this->attrs.followAdditionalWrappers));
                this->symbols.emplace_back("allowMultipleAds", A_BOOL, false, &(this->attrs.allowMultipleAds));
                this->symbols.emplace_back("fallbackOnNoAd", A_BOOL, false, &(this->attrs.fallbackOnNoAd));
            }
        };
    }
}

#endif //CVAST_WRAPPER_HPP
