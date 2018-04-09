//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_VASTBASE_HPP
#define CVAST_VASTBASE_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    template <class N>
    struct VB {
    protected:
        string path;
        rapidxml::xml_node<> *node;
        map<string, string> attributes;
        NodeData nd;

        virtual void setValue () {}

        virtual void setAttributes () {}

        virtual void createChildren () {}

        virtual void registerNode () {
            N* d = dynamic_cast<N*>(this);
            function<N*()> ptr = std::bind(&N::get, *d);
            GenericNode<N> gen(ptr);

            holder.paths.insert(make_pair(this->path, make_shared<GenericNode<N>>(gen)));
            holder.dataPaths.insert(make_pair(this->path, this->nd));
        };

        virtual N* get () = 0;

    public:
        virtual void init(rapidxml::xml_node<> *node, string path) {
            const rapidxml::node_type t = node->type();

            if (rapidxml::node_element == t) {
                this->path = path;
                this->node = node;

                this->nd.setValue(this->node->value());
                this->attributes = VastUtils::getAttributesMap(this->node);
                this->nd.setAttrs(this->attributes);

                this->setValue();
                this->setAttributes();
                this->createChildren();
                this->registerNode();
            }
        }
    };
}

#endif //CVAST_VASTBASE_HPP
