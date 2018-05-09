
#ifndef CVAST_API_HPP
#define CVAST_API_HPP

#include "datatypes/holder.hpp"

namespace Cvast {

    template <class H = void>
    class API {
    private:
        const string& path;
        const size_t uid;
        Holder& holder;

        void pathErr () {
            throw invalid_argument("Path " + this->path + " does not exists");
        }

    public:
        H* get () {
            H* instance = nullptr;
            shared_ptr<GenericNode<H>> gen = dynamic_pointer_cast<GenericNode<H>>(this->holder.paths[this->path]);

            if (gen != NULL) instance = gen->self();
            else this->pathErr();

            return instance;
        }

        string* attr (const string& a) {
            string* val = nullptr;
            string attrName = VastUtils::toLower(a);
            if (this->holder.dataPaths.find(this->path) != this->holder.dataPaths.end())
                val =  &(this->holder.dataPaths.at(this->path).attrs[attrName]);
            else
                this->pathErr();

            return val;
        }

        string* val () {
            string* val = nullptr;
            if (this->holder.dataPaths.find(this->path) != this->holder.dataPaths.end())
                val = &(this->holder.dataPaths.at(this->path).value);
            else
                this->pathErr();

            return val;
        }

        API (const string& p, const size_t id, Holder& h) : path(p), uid(id), holder(h) {}
    };
}

#endif //CVAST_API_HPP
