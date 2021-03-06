
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
