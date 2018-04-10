//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_CREATIVES_HPP
#define CVAST_CREATIVES_HPP
#include "creative.hpp"

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct Creatives : VB<Creatives> {
    private:
        int childs[1] = {holder.nodeTypes.nodeTags["CREATIVE"]};
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
                        case V4T::CREATIVE: {
                            counter = this->creatives.size();
                            path = this->path + "/creatives" + to_string(counter);

                            Creative current;
                            current.init(sibling, path);

                            this->creatives.push_back(current);
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
        vector<Vast4::Creative> creatives;

        Creatives* get () {
            return this;
        }
    };
}

#endif //CVAST_CREATIVES_HPP
