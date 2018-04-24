
#ifndef CVAST_TRACKING_HPP
#define CVAST_TRACKING_HPP

namespace Cvast {
    namespace Vast4 {
        struct TrackingAttrs {
            string event;
            string offset;
        };

        struct Tracking: VB<Tracking> {
            TrackingAttrs attrs;
            URL value;

            Tracking () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("event", A_STRING, false, &(this->attrs.event));
                this->symbols.emplace_back("offset", A_STRING, false, &(this->attrs.offset));
            }
        };
    }
}

#endif //CVAST_TRACKING_HPP
