
#ifndef CVAST_CVAST_V4_H
#define CVAST_CVAST_V4_H

#include "parser.hpp"
#include "api.hpp"
#include "datatypes/holder.hpp"
#include "datatypes/vast4/datastruct/vast.hpp"

namespace Cvast {

    using namespace Vast4;

    class Cvast_v4 : public Parser<Vast> {
    public:
        explicit Cvast_v4 (const string& xml, bool isPermissive = false, bool parse = true) : xml(xml), Parser(xml) {
            Holder h;
            this->holder.holders.push_back(h);

            this->uid = this->holder.holders.size() - 1;
            this->holder.holders[this->uid].isPermissive = isPermissive;
            this->isPermissive = &(this->holder.holders[this->uid].isPermissive);

            if (parse)
                this->parse();
        }

        Vast getVast () {
            return this->vastNode;
        }

        template <typename H = void>
        API<H> api (const string& path) {
            API<H> a(path, this->uid, this->holder.holders[this->uid]);

            return a;
        }

        ~Cvast_v4 () {
            Holder h;
            this->holder.holders[this->uid] = h;
        }

    private:
        const string& xml;
    };
}

#endif //CVAST_CVAST_V4_H
