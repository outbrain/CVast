//
// Created by Oreli Levi on 10/04/2018.
//

#ifndef CVAST_UNIVERSALADID_HPP
#define CVAST_UNIVERSALADID_HPP
extern struct Vast4::Holder holder;
namespace Vast4 {
    struct UniversalAdIdAttrs {
        string idRegistry;
        string idValue;
    };

    struct UniversalAdId : VB<UniversalAdId>{
    private:
        void setAttributes () {
            if (this->attributes.find("idRegistry") != this->attributes.end()) {
                this->attrs.idRegistry = this->attributes["idRegistry"];
            }
            if (this->attributes.find("idValue") != this->attributes.end()) {
                this->attrs.idValue = this->attributes["idValue"];
            }
        }

    public:
        UniversalAdIdAttrs attrs;
        string value;
        UniversalAdId* get () {
            return this;
        }
    };
}

#endif //CVAST_UNIVERSALADID_HPP
