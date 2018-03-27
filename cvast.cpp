//
// Created by Jonathan Sellam on 23/03/2018.
//
#include "datatypes/vast4/holder.hpp"

Vast4::Holder holder;

#include "cvast.h"

CVast::CVast (std::string& xml) : xml(xml) {
    std::vector<char> writable(this->xml.begin(), this->xml.end());
    writable.push_back('\0');

    this->writableXML = writable;
}

void CVast::parse () {
    // character type defaults to char
    this->doc.parse<rapidxml::parse_trim_whitespace>(&this->writableXML[0]);
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

