
#ifndef CVAST_EXTENSIONS_HPP
#define CVAST_EXTENSIONS_HPP

namespace Cvast {
    namespace Vast4 {
        struct ExtensionAttrs {
            MIMETYPE type;
        };

        struct Extension : VB<Extension> {
            ExtensionAttrs attrs;
            XML value;

            Extension () : VB("", A_XML, true, &(this->value)) {
                this->symbols.emplace_back("type", A_MIMETYPE, false, &(this->attrs.type));
            }
        };

        struct Extensions : VB<Extensions> {
            vector<Extension> extension;

            Extensions () {
                {
                    NodeWrapper<Extension, vector<Extension>> wrapper("extension", true, false, this->extension);
                    this->childs.insert(make_pair("EXTENSION", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_EXTENSIONS_HPP
