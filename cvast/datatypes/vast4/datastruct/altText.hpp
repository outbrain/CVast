//
// Created by Jonathan Sellam on 15/04/2018.
//

#ifndef CVAST_ALTTEXT_HPP
#define CVAST_ALTTEXT_HPP

namespace Cvast {
    namespace Vast4 {
        struct AltText: VB<AltText> {
            string value;

            AltText () : VB("", A_STRING, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_ALTTEXT_HPP
