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

    struct Ad {
    private:
        string path;
        rapidxml::xml_node<> *node;
        map<string, string> attributes;
        int childs[2] = { holder.nodeTypes.nodeTags["INLINE"], holder.nodeTypes.nodeTags["WRAPPER"] };

        void setAttributes() {
            this->attributes = VastUtils::getAttributesMap(this->node);

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

        void createChildren() {
            rapidxml::xml_node<> *sibling = this->node->first_node();

            while(sibling != NULL){
                string name = sibling->name();
                VastUtils::toUpperCase(name);
                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);

                if (isChild != end(this->childs)) {
                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::INLINE: {
                            string inlinePath = this->path + "/inLine";
                            this->inLine.init(sibling, inlinePath);
                            break;
                        }
                        case V4T::WRAPPER: {
                            string wrapperPath = this->path + "/wrapper";
                            this->wrapper.init(sibling, wrapperPath);
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

        void registerNode() {
            function<Ad*()> ptr = std::bind(&Ad::get, *this);
            GenericNode<Ad> gen(ptr);

            NodeData nd(this->value, this->attributes);

            holder.paths.insert(make_pair(this->path, make_shared<GenericNode<Ad>>(gen)));
            holder.dataPaths.insert(make_pair(this->path, nd));
        }

        Ad* get () {
            return this;
        }

    public:
        AdAttrs attrs;
        string value;
        InLine inLine;
        Wrapper wrapper;

        void init(rapidxml::xml_node<> *node, string adPath) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->path = adPath;
                this->node = node;
                this->setAttributes();
                this->createChildren();
                this->registerNode();

                shared_ptr<GenericNode<Ad>> gen2 = dynamic_pointer_cast<GenericNode<Ad>>(holder.paths["vast/ads0"]);
                Vast4::Ad* ad = gen2->elm();
            }
        }

        ~Ad () {
            printf("destroy");
        }
    };
}

#endif //CVAST_AD_HPP
