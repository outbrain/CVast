
#ifndef CVAST_INTERACTIVECREATIVEFILE_HPP
#define CVAST_INTERACTIVECREATIVEFILE_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct InteractiveCreativeFileAttrs {
            MIMETYPE type;
            string apiFramework;
        };

        struct InteractiveCreativeFile : VB<InteractiveCreativeFile> {
            InteractiveCreativeFileAttrs attrs;
            URL value;

            InteractiveCreativeFile () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("type", A_MIMETYPE, false, &(this->attrs.type));
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
            }
        };
    }
}

#endif //CVAST_INTERACTIVECREATIVEFILE_HPP
