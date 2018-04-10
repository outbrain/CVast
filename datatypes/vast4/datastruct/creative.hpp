//
// Created by Oreli Levi on 10/04/2018.
//

#ifndef CVAST_CREATIVE_HPP
#define CVAST_CREATIVE_HPP
#include "universalAdId.hpp"
#include "creativeExtensions.hpp"

extern struct Vast4::Holder holder;
namespace Vast4 {

    struct CreativeAttrs {
        string id;
        string adId;
        unsigned short sequence;
        string apiFramework;
    };

    struct Creative : VB<Creative> {
    private:
        void setAttributes () {
            if (this->attributes.find("id") != this->attributes.end()) {
                this->attrs.id = this->attributes["id"];
            }
            if (this->attributes.find("adId") != this->attributes.end()) {
                this->attrs.adId = this->attributes["adId"];
            }
            if (this->attributes.find("sequence") != this->attributes.end()) {
                this->attrs.sequence = VastUtils::castStringToShort(this->attributes["sequence"]);
            }
            if (this->attributes.find("apiFramework") != this->attributes.end()) {
                this->attrs.apiFramework = this->attributes["apiFramework"];
            }
        }
        void createChildren () {
//            rapidxml::xml_node<> *sibling = this->node->first_node();
//
//            while (sibling != NULL) {
//                string name = sibling->name();
//                VastUtils::toUpperCase(name);
//                int *isChild = find(begin(this->childs), end(this->childs), holder.nodeTypes.nodeTags[name]);
//
//                if (isChild != end(this->childs)) {
//                    string path;
//
//                    switch (holder.nodeTypes.nodeTags[name]) {
//                        case V4T::INLINE: {
//                            path = this->path + "/inLine";
//                            this->inLine.init(sibling, path);
//                            break;
//                        }
//                        case V4T::WRAPPER: {
//                            path = this->path + "/wrapper";
//                            this->wrapper.init(sibling, path);
//                            break;
//                        }
//                    }
//
//                    sibling = sibling->next_sibling();
//                } else {
//                    stringstream err;
//
//                    err << "Invalid tagName " << sibling->name() << " in element " << this->node->name();
//                    throw invalid_argument(err.str());
//                }
//            }
        }
    public:
        CreativeAttrs attrs;
        UniversalAdId universalAdId;
        CreativeExtensions creativeExtensions;
        Creative* get () {
            return this;
        }

    };
}
#endif //CVAST_CREATIVE_HPP
