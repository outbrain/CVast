
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
#include "datatypes/holder.hpp"
#include "datatypes/errorsHandler.hpp"

namespace Cvast {

    using namespace std;

    template <class V>
    class Parser {
    public:
        HolderInstance holder;

        Parser () {}

        Parser (const string& xml) {
                std::vector<char> writable(xml.begin(), xml.end());
                writable.push_back('\0');

                this->writableXML = writable;
        }

        virtual V getVast () = 0;

        void parse () {
            if (!this->parsed) {
                rapidxml::xml_document<>& d = this->doc;

                try {
                    d.parse<rapidxml::parse_trim_whitespace>(&this->writableXML[0]);
                } catch (const rapidxml::parse_error& e) {
                    ErrorsHandler::err(ErrorsHandler::PARSING_ERR, e.what(), *this->isPermissive);
                }

                rapidxml::xml_node<> *node = d.first_node();
                double version = this->getVastVersion(node);

                if (version > 0) {
                    this->holder.holders[this->uid].vastVersion = version;
                    this->vastNode.init(node, "vast", this->holder.holders[this->uid]);
                    this->parsed = true;
                } else {
                    ErrorsHandler::err(ErrorsHandler::VAST_VER_NOT_SUPPORTED, "", false);
                }
            }
        }

        double getVastVersion (rapidxml::xml_node<> *node) {
            for(const rapidxml::xml_attribute<>* a = node->first_attribute(); a; a = a->next_attribute()) {
                string name = a->name();
                string value = a->value();

                if (!strcmp(name.c_str(), "version"))
                    return VastUtils::castStringToDbl(value);
            }

            return 0.0;
        }

    protected:
        vector<char> writableXML;
        rapidxml::xml_document<> doc;
        V vastNode;
        bool* isPermissive;
        size_t uid;

    private:
        bool parsed = false;
    };
}

#endif //CVAST_PARSER_HPP
