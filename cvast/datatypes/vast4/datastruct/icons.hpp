
#ifndef CVAST_ICONS_HPP
#define CVAST_ICONS_HPP

#include "icon.hpp"

namespace Cvast {
    namespace Vast4 {
        struct Icons : VB<Icons> {
            vector<Icon> icons;

            Icons () {
                {
                    NodeWrapper<Icon, vector<Icon>> wrapper("icons", true, true, this->icons);
                    this->childs.insert(make_pair("ICON", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_ICONS_HPP
