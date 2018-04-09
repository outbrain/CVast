//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_VAST_HPP
#define CVAST_VAST_HPP

#include "../holder.hpp"
#include "../vastBase.hpp"
#include "ad.hpp"
#include "error.hpp"

extern struct Vast4::Holder holder;

namespace Vast4 {

    struct VastAttrs {
        double version;
    };

    struct Vast : VB<Vast> {
    private:
        int childs[2] = { holder.nodeTypes.nodeTags["AD"], holder.nodeTypes.nodeTags["ERROR"] };

        void setAttributes() {
            if (this->attributes.find("version") != this->attributes.end())
                this->attrs.version = VastUtils::castStringToDbl(this->attributes["version"]);
        }

        void createChildren() {
            rapidxml::xml_node<> *sibling = this->node->first_node();

            while(sibling != NULL){
                string name = sibling->name();
                VastUtils::toUpperCase(name);
                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);

                if (isChild != end(this->childs)) {
                    string path;
                    size_t counter;

                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::AD: {
                            counter = this->ads.size();
                            path = this->path + "/ads" + to_string(counter);

                            Ad current;
                            current.init(sibling, path);

                            this->ads.push_back(current);
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
        VastAttrs attrs;
        string value;
        vector<Vast4::Error> errors;
        vector<Vast4::Ad> ads;

        Vast* get () {
            return this;
        }
    };
}

#endif //CVAST_VAST_HPP
