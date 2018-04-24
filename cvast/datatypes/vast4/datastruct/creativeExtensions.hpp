
#ifndef CVAST_CREATIVEEXTENSIONS_HPP
#define CVAST_CREATIVEEXTENSIONS_HPP

namespace Cvast {
    namespace Vast4 {
        struct CreativeExtensionAttrs {
            MIMETYPE type;
        };

        struct CreativeExtension : VB<CreativeExtension> {
            CreativeExtensionAttrs attrs;
            XML value;

            CreativeExtension () : VB("", A_XML, true, &(this->value)) {
                this->symbols.emplace_back("id", A_MIMETYPE, false, &(this->attrs.type));
            }
        };

        struct CreativeExtensions : VB<CreativeExtensions> {
            vector<CreativeExtension> creativeExtensions;

            CreativeExtensions () {
                {
                    NodeWrapper<CreativeExtension, vector<CreativeExtension>> wrapper("creativeExtensions", true, false, this->creativeExtensions);
                    this->childs.insert(make_pair("CREATIVEEXTENSION", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_CREATIVEEXTENSIONS_HPP
