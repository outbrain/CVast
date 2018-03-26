//
// Created by Oreli Levi on 26/03/2018.
//

#ifndef CVAST_VASTUTILS_HPP
#define CVAST_VASTUTILS_HPP
using namespace std;

class VastUtils{
public:
    static map<string, string> getAttributesMap(rapidxml::xml_node<> *node){
        map<string, string> attributes;

        for(const rapidxml::xml_attribute<>* a = node->first_attribute(); a; a = a->next_attribute()) {
            string name = a->name();
            string value = a->value();
            VastUtils::toLowerCase(name);
            attributes.insert(name, value);
        }

        return attributes;
    }

    static double castStringToFloat(string toCast){
        char *pEnd;
        return strtod(toCast.c_str(), &pEnd);
    }

    static void toLowerCase (string& str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    static void toUpperCase (string& str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    }
};

#endif //CVAST_VASTUTILS_HPP
