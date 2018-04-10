//
// Created by Oreli Levi on 10/04/2018.
//

#ifndef CVAST_DURATION_HPP
#define CVAST_DURATION_HPP
extern struct Vast4::Holder holder;
namespace Vast4 {

    struct Duration: VB<Duration>{
    private:
        void setValue () {
            DATE date(this->node->value());
            this->value = date;
        }
    public:
        DATE value;
        Duration* get () {
            return this;
        }
    };
}
#endif //CVAST_DURATION_HPP
