
#ifndef CVAST_COMPANION_HPP
#define CVAST_COMPANION_HPP

#include "resource.hpp"
#include "adParameters.hpp"
#include "trackingEvents.hpp"
#include "altText.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct CompanionClickTrackingAttrs {
            string id;
        };

        struct CompanionClickTracking: VB <CompanionClickTracking> {
            CompanionClickTrackingAttrs attrs;
            URL value;

            CompanionClickTracking () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };

        struct CompanionClickThrough: VB<CompanionClickThrough> {
            URL value;

            CompanionClickThrough () : VB("", A_URL, true, &(this->value)) {}
        };

        struct CompanionAttrs {
            int width;
            int height;
            string id;
            unsigned short assetWidth;
            unsigned short assetHeight;
            unsigned short expandedWidth;
            unsigned short expandedHeight;
            string apiFramework;
            string adslotID;
            string pxRatio;
        };

        struct Companion: VB<Companion> {
            CompanionAttrs attrs;
            vector<StaticResource> staticResource;
            vector<IFrameResource> iFrameResource;
            vector<HTMLResource> htmlResource;
            vector<AdParameters> adParameters;
            vector<TrackingEvents> trackingEvents;
            vector<AltText> altText;
            vector<CompanionClickThrough> companionClickThrough;
            vector<CompanionClickTracking> companionClickTracking;

            Companion () {
                {
                    NodeWrapper<StaticResource, vector<StaticResource>> wrapper("staticResource", true, false, this->staticResource);
                    this->childs.insert(make_pair("STATICRESOURCE", wrapper));
                }

                {
                    NodeWrapper<IFrameResource, vector<IFrameResource>> wrapper("iFrameResource", true, false, this->iFrameResource);
                    this->childs.insert(make_pair("IFRAMERESOURCE", wrapper));
                }

                {
                    NodeWrapper<HTMLResource, vector<HTMLResource>> wrapper("htmlResource", true, false, this->htmlResource);
                    this->childs.insert(make_pair("HTMLRESOURCE", wrapper));
                }

                {
                    NodeWrapper<AdParameters, vector<AdParameters>> wrapper("adParameters", false, false, this->adParameters);
                    this->childs.insert(make_pair("ADPARAMETERS", wrapper));
                }

                {
                    NodeWrapper<TrackingEvents, vector<TrackingEvents>> wrapper("trackingEvents", false, false, this->trackingEvents);
                    this->childs.insert(make_pair("TRACKINGEVENTS", wrapper));
                }

                {
                    NodeWrapper<AltText, vector<AltText>> wrapper("altText", false, false, this->altText);
                    this->childs.insert(make_pair("ALTTEXT", wrapper));
                }

                {
                    NodeWrapper<CompanionClickThrough, vector<CompanionClickThrough>> wrapper("companionClickThrough", false, false, this->companionClickThrough);
                    this->childs.insert(make_pair("COMPANIONCLICKTHROUGH", wrapper));
                }

                {
                    NodeWrapper<CompanionClickTracking, vector<CompanionClickTracking>> wrapper("companionClickTracking", true, false, this->companionClickTracking);
                    this->childs.insert(make_pair("COMPANIONCLICKTRACKING", wrapper));
                }

                this->symbols.emplace_back("width", A_INT, true, &(this->attrs.width));
                this->symbols.emplace_back("height", A_INT, true, &(this->attrs.height));
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
                this->symbols.emplace_back("assetWidth", A_SHORT, false, &(this->attrs.assetWidth));
                this->symbols.emplace_back("assetHeight", A_SHORT, false, &(this->attrs.assetHeight));
                this->symbols.emplace_back("expandedWidth", A_SHORT, false, &(this->attrs.expandedWidth));
                this->symbols.emplace_back("expandedHeight", A_SHORT, false, &(this->attrs.expandedHeight));
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
                this->symbols.emplace_back("adslotID", A_STRING, false, &(this->attrs.adslotID));
                this->symbols.emplace_back("pxRatio", A_STRING, false, &(this->attrs.pxRatio));
            }
        };
    }
}

#endif //CVAST_COMPANION_HPP
