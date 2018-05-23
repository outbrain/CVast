
#ifndef CVAST_TRACKING_HPP
#define CVAST_TRACKING_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct TrackingAttrs {
            EVENT event;
            string offset;
        };

        struct Tracking: VB<Tracking> {
            TrackingAttrs attrs;
            URL value;

            Tracking () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("event", A_EVENT, true, &(this->attrs.event));
                this->symbols.emplace_back("offset", A_STRING, false, &(this->attrs.offset));
            }
        };
    }
}

#endif //CVAST_TRACKING_HPP
