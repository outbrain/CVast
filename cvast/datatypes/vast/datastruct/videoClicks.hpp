
#ifndef CVAST_VIDEOCLICKS_HPP
#define CVAST_VIDEOCLICKS_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct CustomClickAttrs {
            string id;
        };

        struct CustomClick : VB<CustomClick> {
            CustomClickAttrs attrs;
            URL value;

            CustomClick () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };

        struct ClickTrackingAttrs {
            string id;
        };

        struct ClickTracking : VB<ClickTracking> {
            ClickTrackingAttrs attrs;
            URL value;

            ClickTracking () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };

        struct ClickThroughAttrs {
            string id;
        };

        struct ClickThrough : VB<ClickThrough> {
            ClickThroughAttrs attrs;
            URL value;

            ClickThrough () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };

        struct VideoClicks : VB<VideoClicks> {
            vector<ClickThrough> clickThrough;
            vector<ClickTracking> clickTracking;
            vector<CustomClick> customClicks;

            VideoClicks () {
                {
                    NodeWrapper<ClickThrough, vector<ClickThrough>> wrapper("clickThrough", false, true, this->clickThrough);
                    this->childs.insert(make_pair("CLICKTHROUGH", wrapper));
                }

                {
                    NodeWrapper<ClickTracking, vector<ClickTracking>> wrapper("clickTracking", true, false, this->clickTracking);
                    this->childs.insert(make_pair("CLICKTRACKING", wrapper));
                }

                {
                    NodeWrapper<CustomClick, vector<CustomClick>> wrapper("customClicks", true, false, this->customClicks);
                    this->childs.insert(make_pair("CUSTOMCLICK", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_VIDEOCLICKS_HPP
