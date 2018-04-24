
#ifndef CVAST_CVAST_V4_H
#define CVAST_CVAST_V4_H

#include "parser.hpp"
#include "datatypes/vast4/datastruct/vast.hpp"

namespace Cvast {

    Holder holder;

    using namespace Vast4;

    class Cvast_v4 : public Parser<Vast> {
    public:
        explicit Cvast_v4 (std::string& xml, bool isPermissive = false) : xml(xml), Parser(xml) {
            holder.isPermissive = isPermissive;
            this->isPermissive = &holder.isPermissive;
        }

        Vast getVast () {
            return this->vastNode;
        }

    private:
        string& xml;
    };
}

#endif //CVAST_CVAST_V4_H
