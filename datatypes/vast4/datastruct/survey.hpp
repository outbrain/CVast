//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_SURVEY_HPP
#define CVAST_SURVEY_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct SurveyAttrs {
        MIMETYPE type;
    };

    struct Survey : VB<Survey> {
    private:
        void setValue () {
            URL url(this->node->value());
            this->value = url;
        }

        void setAttributes() {
            if (this->attributes.find("type") != this->attributes.end()) {
                MIMETYPE mime(this->attributes["type"]);
                this->attrs.type = mime;
            }
        }

    public:
        SurveyAttrs attrs;
        URL value;

        Survey* get () {
            return this;
        }
    };
}

#endif //CVAST_SURVEY_HPP
