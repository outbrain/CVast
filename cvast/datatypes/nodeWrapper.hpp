
#ifndef CVAST_NODEWRAPPER_HPP
#define CVAST_NODEWRAPPER_HPP

#include "../rapidxml/rapidxml.hpp"
#include "holder.hpp"

namespace Cvast {
    struct Wrap {
        function<void(const std::string& name, rapidxml::xml_node<> *sibling, Holder& holder)> childFn;

        bool isArray;
        string path;
        bool required;
        bool exists;

        virtual ~Wrap () = default;
    };

    template <class S, class D>
    struct NodeWrapper : Wrap {
        D& node;

        /**
         *
         * @param p (path)
         * @param isArr (is array)
         * @param r (required)
         * @param child (child memory address)
         */
        NodeWrapper (string p, bool isArr, bool r, D& child) : node(child) {
            this->isArray = isArr;
            this->path = p;
            this->required = r;
            this->exists = false;

            this->childFn = std::bind(&NodeWrapper::init, *this, placeholders::_1, placeholders::_2, placeholders::_3);
        }

        void init (const std::string& path, rapidxml::xml_node<> *sibling, Holder& holder) {
            S current;
            string p = path;

            if (this->isArray)
                p += to_string(this->node.size());

            current.init(sibling, p, holder);

            this->node.push_back(current);
            this->exists = true;
        }
    };
}

#endif //CVAST_NODEWRAPPER_HPP
