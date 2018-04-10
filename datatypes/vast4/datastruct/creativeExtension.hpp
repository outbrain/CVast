//
// Created by Oreli Levi on 10/04/2018.
//

#ifndef CVAST_CREATIVEEXTENSION_HPP
#define CVAST_CREATIVEEXTENSION_HPP
extern struct Vast4::Holder holder;
namespace Vast4 {

    struct CreativeExtensionAttrs {
        string type;
    };

    struct CreativeExtension : VB<CreativeExtension>{
    private:
        void setAttributes () {
            if (this->attributes.find("type") != this->attributes.end()) {
                this->attrs.type = this->attributes["type"];
            }
        }
    public:
        CreativeExtensionAttrs attrs;
    };
}
#endif //CVAST_CREATIVEEXTENSION_HPP
