
#ifndef CVAST_AD_HPP
#define CVAST_AD_HPP

#include "../../holder.hpp"
#include "inLine.hpp"
#include "wrapper.hpp"

namespace Cvast {
    namespace Vast4 {

        struct AdAttrs {
            string id;
            unsigned short sequence;
            bool conditionalAd;
        };

        struct Ad : VB<Ad> {
            AdAttrs attrs;
            vector<InLine> inLine;
            vector<Wrapper> wrapper;

            Ad () {
                {
                    NodeWrapper<InLine, vector<InLine>> wrapper("inLine", false, false, this->inLine);
                    this->childs.insert(make_pair("INLINE", wrapper));
                }

                {
                    NodeWrapper<Wrapper, vector<Wrapper>> wrapper("wrapper", false, false, this->wrapper);
                    this->childs.insert(make_pair("WRAPPER", wrapper));
                }

                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
                this->symbols.emplace_back("sequence", A_SHORT, false, &(this->attrs.sequence));
                this->symbols.emplace_back("conditionalAd", A_BOOL, false, &(this->attrs.conditionalAd));
            }
        };
    }
}

#endif //CVAST_AD_HPP
