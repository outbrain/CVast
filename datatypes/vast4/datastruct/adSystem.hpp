//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_ADSYSTEM_HPP
#define CVAST_ADSYSTEM_HPP

namespace Vast4 {
    struct adSystemAttrs {
        std::string version;
    };

    struct adSystem {
        adSystemAttrs attrs;
        std::string value;
    };
}

#endif //CVAST_ADSYSTEM_HPP
