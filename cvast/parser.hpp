
#ifndef CVAST_PARSER_HPP
#define CVAST_PARSER_HPP

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <functional>
#include <tuple>
#include <memory>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <sstream>
#include "rapidxml/rapidxml.hpp"
#include "utils/vastUtils.hpp"
#include "datatypes/errorsHandler.hpp"

namespace Cvast {

    using namespace std;

    template <class V>
    class Parser {
    public:
        Parser () {}

        Parser (const string& xml) {
                std::vector<char> writable(xml.begin(), xml.end());
                writable.push_back('\0');

                this->writableXML = writable;
        }

        virtual V getVast () = 0;

        void parse () {
            rapidxml::xml_document<>& d = this->doc;

            try {
                d.parse<rapidxml::parse_trim_whitespace>(&this->writableXML[0]);
            } catch (const rapidxml::parse_error& e) {
                ErrorsHandler::err(ErrorsHandler::PARSING_ERR, e.what(), *this->isPermissive);
            }

            rapidxml::xml_node<> *node = d.first_node();

            this->vastNode.init(node, "vast");
        }

        /* API
         * ...
         */

    protected:
        vector<char> writableXML;
        rapidxml::xml_document<> doc;
        V vastNode;
        bool* isPermissive;
    };
}

#endif //CVAST_PARSER_HPP
