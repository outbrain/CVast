
#ifndef CVAST_SURVEY_HPP
#define CVAST_SURVEY_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct SurveyAttrs {
            MIMETYPE type;
        };

        struct Survey : VB<Survey> {
            SurveyAttrs attrs;
            URL value;

            Survey () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("type", A_MIMETYPE, false, &(this->attrs.type));
            }
        };
    }
}

#endif //CVAST_SURVEY_HPP
