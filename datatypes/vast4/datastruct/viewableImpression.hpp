//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_VIEWABLEIMPRESSION_HPP
#define CVAST_VIEWABLEIMPRESSION_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct ViewUndetermined : VB<ViewUndetermined> {
    private:
        void setValue() {
            URL url(this->node->value());
            this->value = url;
        }

    public:
        URL value;

        ViewUndetermined *get() {
            return this;
        }
    };

    struct NotViewable : VB<NotViewable> {
    private:
        void setValue() {
            URL url(this->node->value());
            this->value = url;
        }

    public:
        URL value;

        NotViewable *get() {
            return this;
        }
    };

    struct Viewable : VB<Viewable> {
    private:
        void setValue() {
            URL url(this->node->value());
            this->value = url;
        }

    public:
        URL value;

        Viewable *get() {
            return this;
        }
    };

    struct ViewableImpressionAttrs {
        string id;
    };

    struct ViewableImpression : VB<ViewableImpression> {
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
                    size_t counter;

                    switch (holder.nodeTypes.nodeTags[name]) {
                        case V4T::VIEWABLE: {
                            counter = this->viewable.size();
                            path = this->path + "/viewable" + to_string(counter);

                            Viewable viewable;
                            viewable.init(sibling, path);

                            this->viewable.push_back(viewable);
                            break;
                        }
                        case V4T::NOTVIEWABLE: {
                            counter = this->notViewable.size();
                            path = this->path + "/notViewable" + to_string(counter);

                            NotViewable notViewable;
                            notViewable.init(sibling, path);

                            this->notViewable.push_back(notViewable);
                            break;
                        }
                        case V4T::VIEWUNDETERMINED: {
                            counter = this->viewUndetermined.size();
                            path = this->path + "/viewUndetermined" + to_string(counter);

                            ViewUndetermined viewUndetermined;
                            viewUndetermined.init(sibling, path);

                            this->viewUndetermined.push_back(viewUndetermined);
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
        vector<NotViewable> notViewable;
        vector<Viewable> viewable;
        vector<ViewUndetermined> viewUndetermined;

        ViewableImpression* get () {
            return this;
        }
    };


}

#endif //CVAST_VIEWABLEIMPRESSION_HPP
