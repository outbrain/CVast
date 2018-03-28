//
// Created by Jonathan Sellam on 26/03/2018.
//

#ifndef CVAST_HOLDER_HPP
#define CVAST_HOLDER_HPP

#include <string>
#include <map>
#include <memory>
#include "nodeTypes.hpp"
#include "genericNode.hpp"

namespace Vast4 {
    struct Holder {
        std::map<std::string, std::shared_ptr<Generic>> paths;
        std::map<std::string, NodeData> dataPaths;
        V4T nodeTypes = V4T();
    };
}

#endif //CVAST_HOLDER_HPP
