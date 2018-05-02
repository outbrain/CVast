
#ifndef CVAST_API_HPP
#define CVAST_API_HPP

#include "datatypes/holder.hpp"

namespace Cvast {

    extern HolderInstance holder;

    template <class H = void>
    class API {
    private:
        const string& path;
        const size_t uid;

    public:
        H* get () {
            shared_ptr<GenericNode<H>> gen = dynamic_pointer_cast<GenericNode<H>>(holder.holders[this->uid].paths[this->path]);
            return gen->self();
        }

        string* attr (const string& a) {
            return &(holder.holders[this->uid].dataPaths.at(this->path).attrs[a]);
        }

        string* val () {
            return &(holder.holders[this->uid].dataPaths.at(this->path).value);
        }

        API (const string& p, const size_t id) : path(p), uid(id) {}
    };
}

#endif //CVAST_API_HPP
