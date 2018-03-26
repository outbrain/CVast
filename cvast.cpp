//
// Created by Jonathan Sellam on 23/03/2018.
//

#include "cvast.h"

CVast::CVast (char* xml) : xml(xml) {}

void CVast::parse () {
    // character type defaults to char
    this->doc.parse<0>(this->xml);
    rapidxml::xml_node<> *node = doc.first_node();

    this->vastNode.init(node);
}

//void CVast::walk(const rapidxml::xml_node<>* node, int indent = 0) {
//    const auto ind = std::string(indent * 4, ' ');
//    printf("%s", ind.c_str());
//
//    const rapidxml::node_type t = node->type();
//    switch(t) {
//        case rapidxml::node_element:
//        {
//            printf("<%.*s", node->name_size(), node->name());
//            for(const rapidxml::xml_attribute<>* a = node->first_attribute()
//                    ; a
//                    ; a = a->next_attribute()
//                    ) {
//                printf(" %.*s", a->name_size(), a->name());
//                printf("='%.*s'", a->value_size(), a->value());
//            }
//            printf(">\n");
//
//            for(const rapidxml::xml_node<>* n = node->first_node()
//                    ; n
//                    ; n = n->next_sibling()
//                    ) {
//                walk(n, indent+1);
//            }
//            printf("%s</%.*s>\n", ind.c_str(), node->name_size(), node->name());
//        }
//            break;
//
//        case rapidxml::node_data:
//            printf("DATA:[%.*s]\n", node->value_size(), node->value());
//            break;
//
//        default:
//            printf("NODE-TYPE:%d\n", t);
//            break;
//    }
//}

