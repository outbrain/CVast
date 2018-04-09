//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_AD_HPP
#define CVAST_AD_HPP

#include "../holder.hpp"
#include "inLine.hpp"
#include "wrapper.hpp"

extern struct Vast4::Holder holder;

namespace Vast4 {

    struct AdAttrs {
        string id;
        unsigned short sequence;
        bool conditionalAd;
    };

    struct Ad : VB<Ad> {
    private:
        int childs[2] = { holder.nodeTypes.nodeTags["INLINE"], holder.nodeTypes.nodeTags["WRAPPER"] };

        void setAttributes () {
            if (this->attributes.find("id") != this->attributes.end()) {
                this->attrs.id = this->attributes["id"];
            }

            if (this->attributes.find("sequence") != this->attributes.end()) {
                this->attrs.sequence = VastUtils::castStringToShort(this->attributes["sequence"]);
            }

            if (this->attributes.find("conditionalad") != this->attributes.end()) {
                this->attrs.conditionalAd = !strcmp(this->attributes["conditionalad"].c_str(), "true");
            }
        }

        void createChildren () {
            rapidxml::xml_node<> *sibling = this->node->first_node();

            while (sibling != NULL) {
                string name = sibling->name();
                VastUtils::toUpperCase(name);
                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);

                if (isChild != end(this->childs)) {
                    string path;

                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::INLINE: {
                            path = this->path + "/inLine";
                            this->inLine.init(sibling, path);
                            break;
                        }
                        case V4T::WRAPPER: {
                            path = this->path + "/wrapper";
                            this->wrapper.init(sibling, path);
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
        AdAttrs attrs;
        string value;
        InLine inLine;
        Wrapper wrapper;

        Ad* get () {
            return this;
        }
    };
}

#endif //CVAST_AD_HPP
