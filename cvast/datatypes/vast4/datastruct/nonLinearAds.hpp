
#ifndef CVAST_NONLINEARADS_HPP
#define CVAST_NONLINEARADS_HPP

#include "nonLinear.hpp"
#include "trackingEvents.hpp"

namespace Cvast {
    namespace Vast4 {
        struct NonLinearAds : VB<NonLinearAds> {
            vector<NonLinear> nonLinears;
            vector<TrackingEvents> trackingEvents;

            NonLinearAds () {
                {
                    NodeWrapper<NonLinear, vector<NonLinear>> wrapper("nonLinears", true, true, this->nonLinears);
                    this->childs.insert(make_pair("NONLINEAR", wrapper));
                }

                {
                    NodeWrapper<TrackingEvents, vector<TrackingEvents>> wrapper("trackingEvents", true, true, this->trackingEvents);
                    this->childs.insert(make_pair("TRACKINGEVENTS", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_NONLINEARADS_HPP