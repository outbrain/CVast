//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_ERROR_HPP
#define CVAST_ERROR_HPP

namespace Vast4 {
    struct Error {
    private:
        string path;
        rapidxml::xml_node<> *node;
        map<string, string> attributes;

        void setValue () {
            this->value = this->node->value();
        }

        void registerNode() {
//            shared_ptr<error> ptr = make_shared<error>(this);
//            GenericNode<error> gen(ptr, this->value, this->attributes);
//
//            nodePaths.paths.insert(make_pair(this->path, make_shared<GenericNode<error>>(gen)));
        }

    public:
        std::string value;

        void init (rapidxml::xml_node<> *node, string errorPath) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->node = node;
                this->setValue();
                this->registerNode();
            }
        }
    };
}

#endif //CVAST_ERROR_HPP
