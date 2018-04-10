//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_EXTENSIONS_HPP
#define CVAST_EXTENSIONS_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct ExtensionAttrs {
        MIMETYPE type;
    };

    struct Extension : VB<Extension> {
        ExtensionAttrs attrs;
        XML value;
    };

    struct Extensions : VB<Extensions> {
    private:
        void createChildren() {
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
        Extensions* get () {
            return this;
        }
    };
}

#endif //CVAST_EXTENSIONS_HPP
