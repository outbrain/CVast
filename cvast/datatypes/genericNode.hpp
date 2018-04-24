
#ifndef CVAST_GENERICNODE_HPP
#define CVAST_GENERICNODE_HPP

using namespace std;

namespace Cvast {
    struct Generic {
        virtual ~Generic() = default;
    };

    template <typename T>
    struct GenericNode : Generic {
        GenericNode () {}
        GenericNode (std::function<T*()> node) : self(node) {}
        std::function<T*()> self;
    };

    struct Wrap {
        function<void(const std::string& name, rapidxml::xml_node<> *sibling)> childFn;

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

            this->childFn = std::bind(&NodeWrapper::init, *this, placeholders::_1, placeholders::_2);
        }

        void init (const std::string& path, rapidxml::xml_node<> *sibling) {
            S current;
            string p = path;

            if (this->isArray)
                p += to_string(this->node.size());

            current.init(sibling, p);

            this->node.push_back(current);
        }
    };

    struct NodeData {
        std::string value;
        std::map<std::string, std::string> attrs;

        void setValue (const std::string& v) {
            value = v;
        }

        void setAttrs (const std::map<std::string, std::string>& m) {
            attrs = m;
        }
    };
}

#endif //CVAST_GENERICNODE_HPP
