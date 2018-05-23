//
// Created by Jonathan Sellam on 15/04/2018.
//

#ifndef CVAST_ICONVIEWTRACKING_HPP
#define CVAST_ICONVIEWTRACKING_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct IconViewTracking : VB<IconViewTracking> {
            URL value;

            IconViewTracking () : VB("", A_URL, true, &(this->value)) {}
        };
    }
}

#endif //CVAST_ICONVIEWTRACKING_HPP
