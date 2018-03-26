//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_VAST_HPP
#define CVAST_VAST_HPP

#include "ad.hpp"
#include "error.hpp"

namespace Vast4 {
    struct vastAttrs {
        double version;
    };

    struct vast {
    private:
        string path = "vast";
        rapidxml::xml_node<> *node;
        map<string, string> attributes;
        int childs[2] = { holder.nodeTypes.nodeTags["AD"], holder.nodeTypes.nodeTags["ERROR"] };

        void setAttributes() {
            this->attributes = VastUtils::getAttributesMap(this->node);

            if (this->attributes.find("version") != this->attributes.end()) {
                this->attrs.version = VastUtils::castStringToDbl(this->attributes["version"]);
            }
        }

        void createChildren() {
            rapidxml::xml_node<> *sibling = this->node->first_node();

            while(sibling != NULL){
                string name = sibling->name();
                VastUtils::toUpperCase(name);
                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);

                if (isChild != end(this->childs)) {
                    size_t counter = ads.size();

                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::AD: {
                            string adPath = this->path + "/ad" + to_string(counter);

                            ad current;
                            current.init(sibling, adPath);

                            this->ads.push_back(current);
                        }
                        case V4T::ERROR: {
                            string errorPath = this->path + "/error" + to_string(counter);

                            error current;
                            current.init(sibling, errorPath);

                            this->errors.push_back(current);
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

        void registerNode() {
            // std::enable_shared_from_this<vast>
//            shared_ptr<Vast4::vast> ptr = make_shared<Vast4::vast>(this);
//            GenericNode<Vast4::vast> gen(ptr, this->value, this->attributes);
//
//            holder.paths.insert(make_pair(this->path, make_shared<GenericNode<vast>>(gen)));
        }

    public:
        vastAttrs attrs;
        vector<Vast4::error> errors;
        vector<Vast4::ad> ads;
        string value;

        void init(rapidxml::xml_node<> *node) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->node = node;
                this->setAttributes();
                this->createChildren();
                this->registerNode();
            }
        }
    };

}

#endif //CVAST_VAST_HPP
