
#ifndef CVAST_CVAST_V4_H
#define CVAST_CVAST_V4_H

#include "parser.hpp"
#include "api.hpp"
#include "datatypes/vast4/datastruct/vast.hpp"

namespace Cvast {

    HolderInstance holder;

    using namespace Vast4;

    class Cvast_v4 : public Parser<Vast> {
    public:

        explicit Cvast_v4 (const string& xml, bool isPermissive = false, bool parse = false) : xml(xml), Parser(xml) {
            Holder h;
            holder.holders.push_back(h);

            this->uid = holder.holders.size() - 1;
            holder.holders[this->uid].isPermissive = isPermissive;
            this->isPermissive = &(holder.holders[this->uid].isPermissive);

            if (parse)
                this->parse();
        }

        Vast getVast () {
            return this->vastNode;
        }

        template <typename H = void>
        API<H> api (const string& path) {
            API<H> a(path, this->uid);

            return a;
        }

    private:
        const string& xml;
    };
}

#endif //CVAST_CVAST_V4_H
