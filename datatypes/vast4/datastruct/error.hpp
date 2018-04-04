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
            URL url(this->node->value());
            this->value = url;
        }

        void registerNode() {
            function<Error*()> ptr = std::bind(&Error::get, this);
            GenericNode<Error> gen(ptr);

            NodeData nd(this->value.value, this->attributes);

            holder.paths.insert(make_pair(this->path, make_shared<GenericNode<Error>>(gen)));
            holder.dataPaths.insert(make_pair(this->path, nd));
        }

        Error* get () {
            return this;
        }

    public:
        URL value;

        void init (rapidxml::xml_node<> *node, string errorPath) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->path = errorPath;
                this->node = node;
                this->setValue();
                this->registerNode();
            }
        }
    };
}

#endif //CVAST_ERROR_HPP
