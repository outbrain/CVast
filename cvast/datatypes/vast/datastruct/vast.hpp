
#ifndef CVAST_VAST_HPP
#define CVAST_VAST_HPP

#include "../../vastBase.hpp"
#include "ad.hpp"
#include "error.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct VastAttrs {
            double version;
        };

        struct Vast : VB<Vast> {
            VastAttrs attrs;
            vector<Error> error;
            vector<Ad> ad;

            Vast () {
                {
                    NodeWrapper<Ad, vector<Ad>> wrapper("ad", true, false, this->ad);
                    this->childs.insert(make_pair("AD", wrapper));
                }

                {
                    NodeWrapper<Error, vector<Error>> wrapper("error", true, false, this->error);
                    this->childs.insert(make_pair("ERROR", wrapper));
                }


                this->symbols.emplace_back("version", A_DOUBLE, false, &(this->attrs.version));
            }

            void onCreation () {
                if (!this->childs["AD"].exists && !this->childs["ERROR"].exists)
                    ErrorsHandler::err(ErrorsHandler::INVALID_VAST, "An Ad or Error tag must be provided in Vast tag");
            }
        };
    }
}

#endif //CVAST_VAST_HPP
