//
// Created by Oreli Levi on 10/04/2018.
//

#ifndef CVAST_LINEAR_HPP
#define CVAST_LINEAR_HPP

#include "duration.hpp"

extern struct Vast4::Holder holder;
namespace Vast4 {
    struct LinearAttr{
        int skipoffset;
    };

    struct Linear: VB<Linear>{
    private:
        int childs[6] = { holder.nodeTypes.nodeTags["DURATION"], holder.nodeTypes.nodeTags["MEDIAFILES"], holder.nodeTypes.nodeTags["ADPARAMETERS"], holder.nodeTypes.nodeTags["TRACKINGEVENTS"], holder.nodeTypes.nodeTags["VIDEOCLICKS"], holder.nodeTypes.nodeTags["ICONS"] };

        void setAttributes () {
            if (this->attributes.find("skipoffset") != this->attributes.end()) {
                this->attrs.skipoffset = VastUtils::castStringToInt(this->attributes["skipoffset"]);
            }
        }
    public:
        LinearAttr attrs;
        Duration duration;
        Linear* get () {
            return this;
        }
    };
}
#endif //CVAST_LINEAR_HPP
