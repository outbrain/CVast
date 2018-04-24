
#ifndef CVAST_TRACKINGEVENTS_HPP
#define CVAST_TRACKINGEVENTS_HPP

#include "tracking.hpp"

namespace Cvast {
    namespace Vast4 {
        struct TrackingEvents: VB<TrackingEvents> {
            vector<Tracking> trackings;

            TrackingEvents () {
                {
                    NodeWrapper<Tracking, vector<Tracking>> wrapper("trackings", true, false, this->trackings);
                    this->childs.insert(make_pair("TRACKING", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_TRACKINGEVENTS_HPP
