//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_ADSYSTEM_HPP
#define CVAST_ADSYSTEM_HPP

namespace Vast4 {
    struct AdSystemAttrs {
        std::string version;
    };

    struct AdSystem : VB<AdSystem> {
    private:
        void setValue () {
            this->value = this->node->value();
        }

        void setAttributes() {
            if (this->attributes.find("version") != this->attributes.end())
                this->attrs.version = this->attributes["version"];
        }

    public:
        AdSystemAttrs attrs;
        std::string value;

        AdSystem* get () {
            return this;
        }
    };
}

#endif //CVAST_ADSYSTEM_HPP
