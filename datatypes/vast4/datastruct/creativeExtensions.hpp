//
// Created by Oreli Levi on 10/04/2018.
//

#ifndef CVAST_CREATIVEEXTENSIONS_HPP
#define CVAST_CREATIVEEXTENSIONS_HPP

#include "creativeExtension.hpp"
extern struct Vast4::Holder holder;
namespace Vast4 {

    struct CreativeExtensions : VB<CreativeExtensions>{
    private:
        int childs[1] = { holder.nodeTypes.nodeTags["CREATIVEEXTENSION"]};
        void createChildren () {
            rapidxml::xml_node<> *sibling = this->node->first_node();

            while (sibling != NULL) {
                string name = sibling->name();
                VastUtils::toUpperCase(name);
                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);

                if (isChild != end(this->childs)) {
                    string path;

                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::CREATIVEEXTENSION: {
                            path = this->path + "/creativeExtension";
                            this->creativeExtension.init(sibling, path);
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
        CreativeExtension creativeExtension;
        CreativeExtensions* get () {
            return this;
        }
    };
}
#endif //CVAST_CREATIVEEXTENSIONS_HPP
