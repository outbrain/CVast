
#ifndef CVAST_NONLINEAR_HPP
#define CVAST_NONLINEAR_HPP

#include "resource.hpp"
#include "adParameters.hpp"

namespace Cvast {
    namespace Vast4 {
        struct NonLinearClickTrackingAttrs {
            string id;
        };

        struct NonLinearClickTracking: VB<NonLinearClickTracking> {
            NonLinearClickTrackingAttrs attrs;
            URL value;

            NonLinearClickTracking () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
            }
        };

        struct NonLinearClickThrough: VB<NonLinearClickThrough> {
            URL value;

            NonLinearClickThrough () : VB("", A_URL, true, &(this->value)) {}
        };

        struct NonLinear: VB<NonLinear> {
            vector<StaticResource> staticResources;
            vector<IFrameResource> iFrameResources;
            vector<HTMLResource> htmlResources;
            vector<AdParameters> adParameters;
            vector<NonLinearClickThrough> nonLinearClickThrough;
            vector<NonLinearClickTracking> nonLinearClickTrackings;

            NonLinear () {
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
                    NodeWrapper<AdParameters, vector<AdParameters>> wrapper("adParameters", false, false, this->adParameters);
                    this->childs.insert(make_pair("ADPARAMETERS", wrapper));
                }

                {
                    NodeWrapper<NonLinearClickThrough, vector<NonLinearClickThrough>> wrapper("nonLinearClickThrough", false, false, this->nonLinearClickThrough);
                    this->childs.insert(make_pair("NONLINEARCLICKTHROUGH", wrapper));
                }

                {
                    NodeWrapper<NonLinearClickTracking, vector<NonLinearClickTracking>> wrapper("nonLinearClickTrackings", true, false, this->nonLinearClickTrackings);
                    this->childs.insert(make_pair("NONLINEARCLICKTRACKING", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_NONLINEAR_HPP
