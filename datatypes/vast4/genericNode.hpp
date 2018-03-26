//
// Created by Jonathan Sellam on 23/03/2018.
//


#ifndef CVAST_GENERICNODE_HPP
#define CVAST_GENERICNODE_HPP

namespace Vast4 {
    template <typename T>
    struct genericNode {
        genericNode (T node) : elm(node) {}
        T elm;
        string value;
        vector<map<string, string>> attrs;

    };
}

#endif //CVAST_GENERICNODE_HPP
