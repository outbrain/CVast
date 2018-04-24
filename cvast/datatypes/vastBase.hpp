
#ifndef CVAST_VASTBASE_HPP
#define CVAST_VASTBASE_HPP

namespace Cvast {

    extern struct Holder holder;

    template <class N>
    struct VB {
    protected:
        string path;
        rapidxml::xml_node<> *node;
        NodeData nd;
        std::map<std::string, Wrap> childs;
        /* (value, type, required, memAddress) */
        std::tuple<std::string, int, bool, void*> data;
        /* (key, type, required, memAddress) */
        std::vector<std::tuple<std::string, int, bool, void*>> symbols;
        enum attrTypes {
            A_INT = 1,
            A_DOUBLE = 2,
            A_SHORT = 3,
            A_STRING = 4,
            A_BOOL = 5,
            A_URL = 6,
            A_DATE = 7,
            A_TIME = 8,
            A_PRICING_MODEL = 9,
            A_CURRENCY = 10,
            A_MIMETYPE = 11,
            A_XML = 12
        };

        N* get () {
            return dynamic_cast<N*>(this);
        }

        virtual void setValue () {
            if (std::get<1>(this->data) > 0) {
                rapidxml::xml_node<> *childNode = this->node->first_node();
                const rapidxml::node_type type = childNode->type();

                if (std::get<1>(this->data) == A_XML)
                    this->setData(std::get<1>(this->data), std::get<3>(this->data), childNode);
                else
                    this->setData(std::get<1>(this->data), std::get<3>(this->data), this->nd.value);
            }
        }

        virtual void setAttributes () {
            for(const std::tuple<std::string, int, bool, void*> &t : this->symbols) {
                string attrName = VastUtils::toLower(std::get<0>(t));

                if (this->isAttribute(attrName)) {
                    this->setData(std::get<1>(t), std::get<3>(t), this->nd.attrs[attrName]);
                } else {

                }
            }
        }

        virtual void createChildren () {
            if (this->childs.size()) {
                rapidxml::xml_node<> *sibling = this->node->first_node();

                while (sibling != NULL) {
                    string name = sibling->name();
                    VastUtils::toUpperCase(name);

                    if (this->isChild(name)) {
                        string path = this->path + "/" + this->childs[name].path;
                        this->childs[name].childFn(path, sibling);
                    } else {
                        this->nodeErr(sibling->name(), this->node->name());
                    }

                    sibling = sibling->next_sibling();
                }
            }
        }

        virtual void registerNode () {
            N* d = dynamic_cast<N*>(this);
            function<N*()> ptr = std::bind(&N::get, *d);
            GenericNode<N> gen(ptr);

            holder.paths.insert(make_pair(this->path, make_shared<GenericNode<N>>(gen)));
            holder.dataPaths.insert(make_pair(this->path, this->nd));
        };

        virtual void onCreation () {}

        void setData (int t, void* o, const string& v) {
            switch(t) {
                case A_INT: {
                    int *c = (int *) o;
                    *c = VastUtils::castStringToInt(v);
                    break;
                }
                case A_DOUBLE: {
                    double *c = (double *) o;
                    *c = VastUtils::castStringToDbl(v);
                    break;
                }
                case A_SHORT: {
                    unsigned short *c = (unsigned short *) o;
                    *c = VastUtils::castStringToShort(v);
                    break;
                }
                case A_STRING: {
                    std::string *c = (std::string *) o;
                    *c = v;
                    break;
                }
                case A_BOOL: {
                    bool *c = (bool *) o;
                    *c = !strcmp(v.c_str(), "true");
                    break;
                }
                case A_URL: {
                    URL *c = (URL *) o;
                    URL url(v);
                    *c = url;
                    break;
                }
                case A_DATE: {
                    DATE *c = (DATE *) o;
                    DATE date(v);
                    *c = date;
                    break;
                }
                case A_TIME: {
                    TIME *c = (TIME *) o;
                    TIME time(v);
                    *c = time;
                    break;
                }
                case A_PRICING_MODEL: {
                    PRICING_MODEL *c = (PRICING_MODEL *) o;
                    PRICING_MODEL pm(v);
                    *c = pm;
                    break;
                }
                case A_CURRENCY: {
                    CURRENCY *c = (CURRENCY *) o;
                    CURRENCY currency(v);
                    *c = currency;
                    break;
                }
                case A_MIMETYPE: {
                    MIMETYPE *c = (MIMETYPE *) o;
                    MIMETYPE mime(v);
                    *c = mime;
                    break;
                }
            }
        }

        void setData (int t, void* o, rapidxml::xml_node<> *v) {
            XML *c = (XML *) o;
            XML xml(v);
            *c = xml;
        }

        bool isChild (const string& name) {
            return this->childs.count(name) > 0;
        }

        bool isAttribute (const string& attr) {
            return this->nd.attrs.find(attr) != this->nd.attrs.end();
        }

        void nodeErr (string tagName, string nodeName) {
            string err = "Invalid tagName ";
            err += tagName;
            err += " in element ";
            err += nodeName;

            this->err(ErrorsHandler::INVALID_VAST, err);
        }

        void err (int errCode, string errWhat) {
            ErrorsHandler::err(errCode, errWhat, holder.isPermissive);
        }

    public:
        VB (string val = "", int type = 0, bool required = false, void* ptr = NULL) : data(val, type, required, ptr) {}

        virtual void init(rapidxml::xml_node<> *node, string path) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->path = path;
                this->node = node;

                string v = "";
                rapidxml::xml_node<> *childNode = node->first_node();

                if (childNode != NULL) {
                    v = (childNode->type() == rapidxml::node_cdata || childNode->type() == rapidxml::node_data)
                        ? childNode->value() : "";
                }

                this->nd.setValue(v);
                this->nd.setAttrs(VastUtils::getAttributesMap(this->node));

                this->setValue();
                this->setAttributes();
                this->createChildren();
                this->onCreation();
                this->registerNode();
            }
        }
    };
}

#endif //CVAST_VASTBASE_HPP
