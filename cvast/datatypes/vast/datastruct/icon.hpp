
#ifndef CVAST_ICON_HPP
#define CVAST_ICON_HPP

#include "resource.hpp"
#include "iconViewTracking.hpp"
#include "iconClicks.hpp"

namespace Cvast {
    namespace VideoTemplate {
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
            vector<StaticResource> staticResource;
            vector<IFrameResource> iFrameResource;
            vector<HTMLResource> htmlResource;
            vector<IconViewTracking> iconViewTracking;
            vector<IconClicks> iconClicks;

            Icon () {
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
                    NodeWrapper<IconViewTracking, vector<IconViewTracking>> wrapper("iconViewTracking", true, false, this->iconViewTracking);
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
