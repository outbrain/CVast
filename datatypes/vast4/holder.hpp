//
// Created by Jonathan Sellam on 26/03/2018.
//

#ifndef CVAST_HOLDER_HPP
#define CVAST_HOLDER_HPP

namespace Vast4 {
    extern struct Holder {
        map<string, std::shared_ptr<Generic>> paths;
        V4T nodeTypes = V4T();
    } holder;
}

#endif //CVAST_HOLDER_HPP
