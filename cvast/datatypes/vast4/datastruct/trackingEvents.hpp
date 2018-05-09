
#ifndef CVAST_TRACKINGEVENTS_HPP
#define CVAST_TRACKINGEVENTS_HPP

#include "tracking.hpp"

namespace Cvast {
    namespace Vast4 {
        struct TrackingEvents: VB<TrackingEvents> {
            vector<Tracking> tracking;

            TrackingEvents () {
                {
                    NodeWrapper<Tracking, vector<Tracking>> wrapper("tracking", true, false, this->tracking);
                    this->childs.insert(make_pair("TRACKING", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_TRACKINGEVENTS_HPP
