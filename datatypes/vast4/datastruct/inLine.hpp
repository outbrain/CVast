//
// Created by Jonathan Sellam on 23/03/2018.
//

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

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct InLine : VB<InLine> {
    private:
        int childs[13] = {
                holder.nodeTypes.nodeTags["ADSYSTEM"],
                holder.nodeTypes.nodeTags["ADTITLE"],
                holder.nodeTypes.nodeTags["IMPRESSION"],
                holder.nodeTypes.nodeTags["CATEGORY"],
                holder.nodeTypes.nodeTags["DESCRIPTION"],
                holder.nodeTypes.nodeTags["ADVERTISER"],
                holder.nodeTypes.nodeTags["PRICING"],
                holder.nodeTypes.nodeTags["SURVEY"],
                holder.nodeTypes.nodeTags["VIEWABLEIMPRESSION"],
                holder.nodeTypes.nodeTags["ERROR"],
                holder.nodeTypes.nodeTags["EXTENSIONS"],
                holder.nodeTypes.nodeTags["ADVERIFICATIONS"],
                holder.nodeTypes.nodeTags["CREATIVES"],
        };

        void createChildren () {
            rapidxml::xml_node<> *sibling = this->node->first_node();

            while (sibling != NULL) {
                string name = sibling->name();
                VastUtils::toUpperCase(name);
                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);

                if (isChild != end(this->childs)) {
                    string path;
                    size_t counter;

                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::ADSYSTEM: {
                            path = this->path + "/adSystem";
                            this->adSystem.init(sibling, path);
                            break;
                        }
                        case V4T::ADTITLE: {
                            path = this->path + "/adTitle";
                            this->adTitle.init(sibling, path);
                            break;
                        }
                        case V4T::IMPRESSION: {
                            counter = this->impressions.size();
                            path = this->path + "/impression" + to_string(counter);

                            Impression impression;
                            impression.init(sibling, path);

                            this->impressions.push_back(impression);
                            break;
                        }
                        case V4T::CATEGORY: {
                            counter = this->categories.size();
                            path = this->path + "/categories" + to_string(counter);

                            Category category;
                            category.init(sibling, path);

                            this->categories.push_back(category);
                            break;
                        }
                        case V4T::DESCRIPTION: {
                            path = this->path + "/description";
                            this->description.init(sibling, path);
                            break;
                        }
                        case V4T::ADVERTISER: {
                            path = this->path + "/advertiser";
                            this->advertiser.init(sibling, path);
                            break;
                        }
                        case V4T::PRICING: {
                            path = this->path + "/pricing";
                            this->pricing.init(sibling, path);
                            break;
                        }
                        case V4T::SURVEY: {
                            counter = this->surveys.size();
                            path = this->path + "/surveys" + to_string(counter);

                            Survey survey;
                            survey.init(sibling, path);

                            this->surveys.push_back(survey);
                            break;
                        }
                        case V4T::VIEWABLEIMPRESSION: {
                            path = this->path + "/viewableImpression";
                            this->viewableImpression.init(sibling, path);
                            break;
                        }
                        case V4T::ERROR: {
                            counter = this->errors.size();
                            path = this->path + "/errors" + to_string(counter);

                            Error current;
                            current.init(sibling, path);

                            this->errors.push_back(current);
                            break;
                        }
                        case V4T::EXTENSIONS: {
                            path = this->path + "/extensions";
                            this->extensions.init(sibling, path);
                            break;
                        }
                        case V4T::ADVERIFICATIONS: {
                            path = this->path + "/adVerifications";
                            this->adVerifications.init(sibling, path);
                            break;
                        }
                        case V4T::CREATIVES: {
                            path = this->path + "/creatives";
                            this->creatives.init(sibling, path);
                            break;
                        }
                    }

                    sibling = sibling->next_sibling();
                } else {
                    stringstream err;

                    err << "Invalid tagName " << sibling->name() << " in element " << this->node->name();
                    throw invalid_argument(err.str());
                }
            }
        }

    public:
        AdSystem adSystem;
        AdTitle adTitle;
        std::vector<Impression> impressions;
        std::vector<Category> categories;
        Description description;
        Advertiser advertiser;
        Pricing pricing;
        std::vector<Survey> surveys;
        std::vector<Error> errors;
        Extensions extensions;
        ViewableImpression viewableImpression;
        AdVerifications adVerifications;
        Creatives creatives;

        InLine* get () {
            return this;
        }
    };
}

#endif //CVAST_INLINE_HPP
