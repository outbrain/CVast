
#ifndef CVAST_ICON_HPP
#define CVAST_ICON_HPP

#include "resource.hpp"
#include "iconViewTracking.hpp"
#include "iconClicks.hpp"

namespace Cvast {
    namespace Vast4 {
        struct IconAttrs {
            string program;
            int width;
            int height;
            string xPosition;
            string yPosition;
            TIME duration;
            TIME offset;
            string apiFramework;
            string pxRatio;
        };

        struct Icon : VB<Icon> {
            IconAttrs attrs;
            vector<StaticResource> staticResources;
            vector<IFrameResource> iFrameResources;
            vector<HTMLResource> htmlResources;
            vector<IconViewTracking> iconViewTrackings;
            vector<IconClicks> iconClicks;

            Icon () {
                {
                    NodeWrapper<StaticResource, vector<StaticResource>> wrapper("staticResources", true, false, this->staticResources);
                    this->childs.insert(make_pair("STATICRESOURCE", wrapper));
                }

                {
                    NodeWrapper<IFrameResource, vector<IFrameResource>> wrapper("iFrameResources", true, false, this->iFrameResources);
                    this->childs.insert(make_pair("IFRAMERESOURCE", wrapper));
                }

                {
                    NodeWrapper<HTMLResource, vector<HTMLResource>> wrapper("htmlResources", true, false, this->htmlResources);
                    this->childs.insert(make_pair("HTMLRESOURCE", wrapper));
                }

                {
                    NodeWrapper<IconViewTracking, vector<IconViewTracking>> wrapper("iconViewTrackings", true, false, this->iconViewTrackings);
                    this->childs.insert(make_pair("ICONVIEWTRACKING", wrapper));
                }

                {
                    NodeWrapper<IconClicks, vector<IconClicks>> wrapper("iconClicks", false, false, this->iconClicks);
                    this->childs.insert(make_pair("ICONCLICKS", wrapper));
                }

                this->symbols.emplace_back("program", A_STRING, false, &(this->attrs.program));
                this->symbols.emplace_back("width", A_INT, false, &(this->attrs.width));
                this->symbols.emplace_back("height", A_INT, false, &(this->attrs.height));
                this->symbols.emplace_back("xPosition", A_STRING, false, &(this->attrs.xPosition));
                this->symbols.emplace_back("yPosition", A_STRING, false, &(this->attrs.yPosition));
                this->symbols.emplace_back("duration", A_TIME, false, &(this->attrs.duration));
                this->symbols.emplace_back("offset", A_TIME, false, &(this->attrs.offset));
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
                this->symbols.emplace_back("pxRatio", A_STRING, false, &(this->attrs.pxRatio));
            }
        };
    }
}

#endif //CVAST_ICON_HPP
