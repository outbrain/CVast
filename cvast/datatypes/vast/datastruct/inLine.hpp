
#ifndef CVAST_INLINE_HPP
#define CVAST_INLINE_HPP

#include "adSystem.hpp"
#include "adTitle.hpp"
#include "category.hpp"
#include "impression.hpp"
#include "description.hpp"
#include "advertiser.hpp"
#include "pricing.hpp"
#include "survey.hpp"
#include "viewableImpression.hpp"
#include "adVerifications.hpp"
#include "extensions.hpp"
#include "creatives.hpp"
#include "error.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct InLine : VB<InLine> {
            vector<AdSystem> adSystem;
            vector<AdTitle> adTitle;
            vector<Impression> impression;
            vector<Category> category;
            vector<Description> description;
            vector<Advertiser> advertiser;
            vector<Pricing> pricing;
            vector<Survey> survey;
            vector<Error> error;
            vector<Extensions> extensions;
            vector<ViewableImpression> viewableImpression;
            vector<AdVerifications> adVerifications;
            vector<Creatives> creatives;

            InLine () {
                {
                    NodeWrapper<AdSystem, vector<AdSystem>> wrapper("adSystem", false, true, this->adSystem);
                    this->childs.insert(make_pair("ADSYSTEM", wrapper));
                }

                {
                    NodeWrapper<AdTitle, vector<AdTitle>> wrapper("adTitle", false, true, this->adTitle);
                    this->childs.insert(make_pair("ADTITLE", wrapper));
                }

                {
                    NodeWrapper<Impression, vector<Impression>> wrapper("impression", true, true, this->impression);
                    this->childs.insert(make_pair("IMPRESSION", wrapper));
                }

                {
                    NodeWrapper<Category, vector<Category>> wrapper("category", true, false, this->category);
                    this->childs.insert(make_pair("CATEGORY", wrapper));
                }

                {
                    NodeWrapper<Description, vector<Description>> wrapper("description", false, false, this->description);
                    this->childs.insert(make_pair("DESCRIPTION", wrapper));
                }

                {
                    NodeWrapper<Advertiser, vector<Advertiser>> wrapper("advertiser", false, false, this->advertiser);
                    this->childs.insert(make_pair("ADVERTISER", wrapper));
                }

                {
                    NodeWrapper<Pricing, vector<Pricing>> wrapper("pricing", false, false, this->pricing);
                    this->childs.insert(make_pair("PRICING", wrapper));
                }

                {
                    NodeWrapper<Survey, vector<Survey>> wrapper("survey", true, false, this->survey);
                    this->childs.insert(make_pair("SURVEY", wrapper));
                }

                {
                    NodeWrapper<Error, vector<Error>> wrapper("error", true, false, this->error);
                    this->childs.insert(make_pair("ERROR", wrapper));
                }

                {
                    NodeWrapper<Extensions, vector<Extensions>> wrapper("extensions", false, false, this->extensions);
                    this->childs.insert(make_pair("EXTENSIONS", wrapper));
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
                    NodeWrapper<Creatives, vector<Creatives>> wrapper("creatives", false, true, this->creatives);
                    this->childs.insert(make_pair("CREATIVES", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_INLINE_HPP
