
#ifndef CVAST_NONLINEAR_HPP
#define CVAST_NONLINEAR_HPP

#include "resource.hpp"
#include "adParameters.hpp"

namespace Cvast {
    namespace VideoTemplate {
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
            vector<StaticResource> staticResource;
            vector<IFrameResource> iFrameResource;
            vector<HTMLResource> htmlResource;
            vector<AdParameters> adParameters;
            vector<NonLinearClickThrough> nonLinearClickThrough;
            vector<NonLinearClickTracking> nonLinearClickTracking;

            NonLinear () {
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
                    NodeWrapper<NonLinearClickThrough, vector<NonLinearClickThrough>> wrapper("nonLinearClickThrough", false, false, this->nonLinearClickThrough);
                    this->childs.insert(make_pair("NONLINEARCLICKTHROUGH", wrapper));
                }

                {
                    NodeWrapper<NonLinearClickTracking, vector<NonLinearClickTracking>> wrapper("nonLinearClickTracking", true, false, this->nonLinearClickTracking);
                    this->childs.insert(make_pair("NONLINEARCLICKTRACKING", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_NONLINEAR_HPP
