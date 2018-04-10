//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_VIEWABLEIMPRESSION_HPP
#define CVAST_VIEWABLEIMPRESSION_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct ViewUndetermined : VB {
    private:
        void setValue() {
            this->value = this->node->value();
        }

    public:
        std::string value;

        ViewUndetermined *get() {
            return this;
        }
    };

    struct NotViewable : VB {
    private:
        void setValue() {
            this->value = this->node->value();
        }

    public:
        std::string value;

        NotViewable *get() {
            return this;
        }
    };

    struct Viewable : VB {
    private:
        void setValue() {
            this->value = this->node->value();
        }

    public:
        std::string value;

        Viewable *get() {
            return this;
        }
    };

    struct ViewableImpressionAttrs {
        string id;
    };

    struct ViewableImpression : VB {
    private:
        int childs[3] = { holder.nodeTypes.nodeTags["VIEWABLE"], holder.nodeTypes.nodeTags["NOTVIEWABLE"],  holder.nodeTypes.nodeTags["VIEWUNDETERMINED"]};

        void setAttributes () {
            if (this->attributes.find("id") != this->attributes.end()) {
                this->attrs.id = this->attributes["id"];
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
                        case V4T::VIEWABLE: {
                            path = this->path + "/viewable";
                            this->viewable.init(sibling, path);
                            break;
                        }
                        case V4T::NOTVIEWABLE: {
                            path = this->path + "/notViewable";
                            this->notViewable.init(sibling, path);
                            break;
                        }
                        case V4T::VIEWUNDETERMINED: {
                            path = this->path + "/viewUndetermined";
                            this->viewUndetermined.init(sibling, path);
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
        ViewableImpressionAttrs attrs;
        NotViewable notViewable;
        Viewable viewable;
        ViewUndetermined viewUndetermined;

        ViewableImpression* get () {
            return this;
        }
    };


}

#endif //CVAST_VIEWABLEIMPRESSION_HPP
