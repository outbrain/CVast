//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_IMPRESSION_HPP
#define CVAST_IMPRESSION_HPP

namespace Vast4 {
    struct ImpressionAttrs {
        std::string id;
    };

    struct Impression : VB<Impression> {
    private:
        void setValue () {
            URL url(this->node->value());
            this->value = url;
        }

        void setAttributes() {
            if (this->attributes.find("id") != this->attributes.end())
                this->attrs.id = this->attributes["id"];
        }

    public:
        ImpressionAttrs attrs;
        URL value;

        Impression* get () {
            return this;
        }
    };
}

#endif //CVAST_IMPRESSION_HPP
