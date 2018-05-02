
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

        static string getUID () {
            const std::string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            std::string uuid = std::string(36,' ');
            int rnd = 0;
            int r = 0;

            uuid[8] = '-';
            uuid[13] = '-';
            uuid[18] = '-';
            uuid[23] = '-';

            uuid[14] = '4';

            for(int i=0; i<36; i++) {
                if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
                    if (rnd <= 0x02) {
                        rnd = 0x2000000 + (std::rand() * 0x1000000) | 0;
                    }
                    rnd >>= 4;
                    uuid[i] = CHARS[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
                }
            }

            return uuid;
        }
    };
}

#endif //CVAST_VASTUTILS_HPP
