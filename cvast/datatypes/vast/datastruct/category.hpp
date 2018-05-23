
#ifndef CVAST_CATEGORY_HPP
#define CVAST_CATEGORY_HPP

namespace Cvast {
    namespace VideoTemplate {
        struct CategoryAttrs  {
            string authority;
        };

        struct Category : VB<Category> {
            CategoryAttrs attrs;
            std::string value;

            Category () : VB("", A_STRING, true, &(this->value)) {
                this->symbols.emplace_back("authority", A_STRING, true, &(this->attrs.authority));
            }
        };
    }
}

#endif //CVAST_CATEGORY_HPP
