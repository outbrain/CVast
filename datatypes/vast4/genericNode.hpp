//
// Created by Jonathan Sellam on 23/03/2018.
//


#ifndef CVAST_GENERICNODE_HPP
#define CVAST_GENERICNODE_HPP

using namespace std;

namespace Vast4 {
    struct Generic {
        virtual ~Generic() = default;
    };
    template <typename T>
    struct GenericNode : Generic {
        GenericNode () {}
        GenericNode (std::function<T*()> node) : elm(node) {}
        std::function<T*()> elm;
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
