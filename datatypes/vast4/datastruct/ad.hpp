//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_AD_HPP
#define CVAST_AD_HPP

namespace Vast4 {
    struct adAttrs {
        std::string id;
        unsigned int sequence;
        bool conditionalAd;
    };

    struct ad {
        adAttrs attrs;
        std::string value;

        ad(rapidxml::xml_node<> *node, string adPath) {

        }

        void setAttributes() {

        }

        void createChildren() {

        }

        void registerNode() {

        }

        ~ad() {

        };
    };
}

#endif //CVAST_AD_HPP
