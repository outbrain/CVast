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


        void setAttributes(){
            map<string, string> attributes = VastUtils::getAttributesMap(this->node);

            if (attributes.find("version") != attributes.end()) {
                this->attrs.version = VastUtils::castStringToFloat(attributes["version"]);
            }
        }

        void createChildren() {
            rapidxml::xml_node<> *children =  this->node->first_node();
            rapidxml::xml_node<> *sibling = children;
            while(sibling != NULL){
                //handle current sibling
                size_t counter = ads.size();
                string adPath = this->path + "/ad" + to_string(counter);

                this->ads.push_back(ad(sibling, adPath));
                sibling = children->next_sibling();
            }
        }

        void registerNode() {

        }

    public:
        vastAttrs attrs;
        std::vector<Vast4::error> error;
        std::vector<Vast4::ad> ads;

        vast(rapidxml::xml_node<> *node){
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->node = node;
                this->setAttributes();
                this->createChildren();
                this->registerNode();
            }
        }

        ~vast(){
            this->node = nullptr;
        }
    };

}

#endif //CVAST_VAST_HPP
