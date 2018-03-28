//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_AD_HPP
#define CVAST_AD_HPP

#include "../holder.hpp"

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

        }

        void registerNode() {
            function<Ad*()> ptr = std::bind(&Ad::get, this);
            GenericNode<Ad> gen(ptr);

            holder.paths.insert(make_pair(this->path, make_shared<GenericNode<Ad>>(gen)));
        }

        Ad* get () {
            return this;
        }

    public:
        AdAttrs attrs;
        string value;

        void init(rapidxml::xml_node<> *node, string adPath) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->path = adPath;

                this->node = node;
                this->setAttributes();
                this->createChildren();
                this->registerNode();
            }
        }
    };
}

#endif //CVAST_AD_HPP
