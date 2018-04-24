
#ifndef CVAST_VASTUTILS_HPP
#define CVAST_VASTUTILS_HPP

#include "../rapidxml/rapidxml.hpp"

namespace Cvast {

    using namespace std;

    class VastUtils {
    public:
        static map<string, string> getAttributesMap(rapidxml::xml_node<> *node){
            map<string, string> attributes;

            for(const rapidxml::xml_attribute<>* a = node->first_attribute(); a; a = a->next_attribute()) {
                string name = a->name();
                string value = a->value();
                VastUtils::toLowerCase(name);
                attributes.insert(make_pair(name, value));
            }

            return attributes;
        }

        static double castStringToDbl(string toCast){
            char *pEnd;
            return strtod(toCast.c_str(), &pEnd);
        }

        static int castStringToInt(string toCast){
            int converted = atoi(toCast.c_str());
            return converted;
        }

        static unsigned short castStringToShort(string toCast) {
            int i = stoi(toCast.c_str());

            if (i >= numeric_limits<short>::min() && i <= numeric_limits<short>::max()) {
                return i;
            }
            else {
                throw range_error("Invalid integer " + to_string(i) + " for short conversion");
            }
        }

        static void toLowerCase (string& str) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
        }

        static void toUpperCase (string& str) {
            transform(str.begin(), str.end(), str.begin(), ::toupper);
        }

        static string toLower (const string& str) {
            string s = str;
            VastUtils::toLowerCase(s);

            return s;
        }

        static string toUpper (const string& str) {
            string s = str;
            VastUtils::toUpperCase(s);

            return s;
        }
    };
}

#endif //CVAST_VASTUTILS_HPP
