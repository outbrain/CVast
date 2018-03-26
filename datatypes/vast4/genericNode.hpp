//
// Created by Jonathan Sellam on 23/03/2018.
//


#ifndef CVAST_GENERICNODE_HPP
#define CVAST_GENERICNODE_HPP

namespace Vast4 {
    struct Generic {};
    template <typename T>
    struct GenericNode : Generic {
        GenericNode (shared_ptr<T> node, string& val, map<string, string>& attrs) : elm(node), value(val), attributes(attrs) {}
        shared_ptr<T> elm;
        string& value;
        map<string, string>& attributes;

    };
}

#endif //CVAST_GENERICNODE_HPP
