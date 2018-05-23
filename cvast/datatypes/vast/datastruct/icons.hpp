
#ifndef CVAST_ICONS_HPP
#define CVAST_ICONS_HPP

#include "icon.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct Icons : VB<Icons> {
            vector<Icon> icon;

            Icons () {
                {
                    NodeWrapper<Icon, vector<Icon>> wrapper("icon", true, true, this->icon);
                    this->childs.insert(make_pair("ICON", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_ICONS_HPP
