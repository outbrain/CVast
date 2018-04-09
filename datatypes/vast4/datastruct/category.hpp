//
// Created by Jonathan Sellam on 09/04/2018.
//

#ifndef CVAST_CATEGORY_HPP
#define CVAST_CATEGORY_HPP

extern struct Vast4::Holder holder;

namespace Vast4 {
    struct CategoryAttrs  {
        std::string authority;
    };

    struct Category : VB<Category> {
    private:
        void setValue () {
            this->value = this->node->value();
        }

        void setAttributes() {
            if (this->attributes.find("authority") != this->attributes.end())
                this->attrs.authority = this->attributes["authority"];
        }

    public:
        CategoryAttrs attrs;
        std::string value;

        Category* get () {
            return this;
        }
    };
}

#endif //CVAST_CATEGORY_HPP
