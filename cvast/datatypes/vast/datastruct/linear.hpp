
#ifndef CVAST_LINEAR_HPP
#define CVAST_LINEAR_HPP

#include "duration.hpp"
#include "adParameters.hpp"
#include "mediaFiles.hpp"
#include "videoClicks.hpp"
#include "trackingEvents.hpp"
#include "icons.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct LinearAttrs {
            int skipoffset;
        };

        struct Linear: VB<Linear> {
            LinearAttrs attrs;
            vector<Duration> duration;
            vector<AdParameters> adParameters;
            vector<MediaFiles> mediaFiles;
            vector<TrackingEvents> trackingEvents;
            vector<VideoClicks> videoClicks;
            vector<Icons> icons;

            Linear () {
                {
                    NodeWrapper<Duration, vector<Duration>> wrapper("duration", false, true, this->duration);
                    this->childs.insert(make_pair("DURATION", wrapper));
                }

                {
                    NodeWrapper<AdParameters, vector<AdParameters>> wrapper("adParameters", false, false, this->adParameters);
                    this->childs.insert(make_pair("ADPARAMETERS", wrapper));
                }

                {
                    NodeWrapper<MediaFiles, vector<MediaFiles>> wrapper("mediaFiles", false, true, this->mediaFiles);
                    this->childs.insert(make_pair("MEDIAFILES", wrapper));
                }

                {
                    NodeWrapper<TrackingEvents, vector<TrackingEvents>> wrapper("trackingEvents", false, false, this->trackingEvents);
                    this->childs.insert(make_pair("TRACKINGEVENTS", wrapper));
                }

                {
                    NodeWrapper<VideoClicks, vector<VideoClicks>> wrapper("videoClicks", false, false, this->videoClicks);
                    this->childs.insert(make_pair("VIDEOCLICKS", wrapper));
                }

                {
                    NodeWrapper<Icons, vector<Icons>> wrapper("icons", false, false, this->icons);
                    this->childs.insert(make_pair("ICONS", wrapper));
                }

                this->symbols.emplace_back("skipoffset", A_INT, false, &(this->attrs.skipoffset));
            }
        };
    }
}

#endif //CVAST_LINEAR_HPP
