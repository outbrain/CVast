//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_IMPRESSION_HPP
#define CVAST_IMPRESSION_HPP

namespace Vast4 {
    struct impressionAttrs {
        std::string id;
    };

    struct impression {
        impressionAttrs attrs;
        std::string value;
    };
}

#endif //CVAST_IMPRESSION_HPP
