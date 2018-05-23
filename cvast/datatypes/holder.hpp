
#ifndef CVAST_HOLDER_HPP
#define CVAST_HOLDER_HPP

#include <string>
#include <map>
#include <memory>
#include "genericNode.hpp"

namespace Cvast {
    struct Holder {
        std::map<std::string, std::shared_ptr<Generic>> paths;
        std::map<std::string, NodeData> dataPaths;
        bool isPermissive = false;
        double vastVersion;
    };

    struct HolderInstance {
        std::vector<Holder> holders;
    };
}

#endif //CVAST_HOLDER_HPP
