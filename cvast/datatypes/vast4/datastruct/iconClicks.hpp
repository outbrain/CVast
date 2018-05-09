
#ifndef CVAST_ICONCLICKS_HPP
#define CVAST_ICONCLICKS_HPP

namespace Cvast {
    namespace Vast4 {
        struct IconClickTrackingAttrs {
            string id;
        };

        struct IconClickTracking: VB<IconClickTracking> {
            IconClickTrackingAttrs attrs;
            URL value;

            IconClickTracking () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };

        struct IconClickThrough: VB<IconClickThrough> {
            URL value;

            IconClickThrough () : VB("", A_URL, true, &(this->value)) {}
        };

        struct IconClicks : VB<IconClicks> {
            vector<IconClickThrough> iconClickThrough;
            vector<IconClickTracking> iconClickTracking;

            IconClicks () {
                {
                    NodeWrapper<IconClickThrough, vector<IconClickThrough>> wrapper("iconClickThrough", false, false, this->iconClickThrough);
                    this->childs.insert(make_pair("ICONCLICKTHROUGH", wrapper));
                }

                {
                    NodeWrapper<IconClickTracking, vector<IconClickTracking>> wrapper("iconClickTracking", true, false, this->iconClickTracking);
                    this->childs.insert(make_pair("ICONCLICKTRACKING", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_ICONCLICKS_HPP
