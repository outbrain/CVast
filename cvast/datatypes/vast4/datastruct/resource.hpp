
#ifndef CVAST_RESOURCE_HPP
#define CVAST_RESOURCE_HPP

namespace Cvast {
    namespace Vast4 {
        struct HTMLResource : VB<HTMLResource> {
            URL value;

            HTMLResource () : VB("", A_URL, true, &(this->value)) {}
        };

        struct IFrameResource : VB<IFrameResource> {
            URL value;

            IFrameResource () : VB("", A_URL, true, &(this->value)) {}
        };

        struct StaticResourceAttrs {
            MIMETYPE creativeType;
        };

        struct StaticResource : VB<StaticResource> {
            StaticResourceAttrs attrs;
            URL value;

            StaticResource () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("creativeType", A_MIMETYPE, false, &(this->attrs.creativeType));
            }
        };

        struct FlashResourceAttrs {
            string apiFramework;
        };

        struct FlashResource : VB<FlashResource> {
            FlashResourceAttrs attrs;
            URL value;

            FlashResource () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
            }
        };

        struct JavascriptResourceAttrs {
            string apiFramework;
        };

        struct JavascriptResource : VB<JavascriptResource> {
            JavascriptResourceAttrs attrs;
            URL value;

            JavascriptResource () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
            }
        };
    }
}

#endif //CVAST_RESOURCE_HPP
