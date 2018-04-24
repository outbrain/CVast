
#ifndef CVAST_HOLDER_HPP
#define CVAST_HOLDER_HPP

#include <string>
#include <map>
#include <memory>
#include "dataTypes.hpp"
#include "genericNode.hpp"

namespace Cvast {
    struct Holder {
        std::map<std::string, std::shared_ptr<Generic>> paths;
        std::map<std::string, NodeData> dataPaths;
        bool isPermissive = false;
    };
}

#endif //CVAST_HOLDER_HPP
