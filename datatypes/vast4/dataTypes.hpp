//
// Created by Jonathan Sellam on 04/04/2018.
//

#ifndef CVAST_DATATYPES_HPP
#define CVAST_DATATYPES_HPP

#include <regex>

namespace Vast4 {
    struct URL {
        std::string value;

        URL () {}

        URL (std::string url) {
            std::regex r("^((http[s]?|ftp):\\/)?\\/?([^:\\/\\s]+)((\\/\\w+)*\\/)([\\w\\-\\.]+[^#?\\s]+)(.*)?(#[\\w\\-]+)?$");

            if (!std::regex_match(url, r)) {
                std::string err = "Invalid URL " + url;
                throw std::invalid_argument(err);
            } else {
                this->value = url;
            }
        }
    };

    struct DATE {
        std::string value;

        DATE () {}

        DATE (std::string date) {
            std::regex r("^\\d{4}(-\\d\\d(-\\d\\d(T\\d\\d:\\d\\d(:\\d\\d)?(\\.\\d+)?(([+-]\\d\\d:\\d\\d)|Z)?)?)?)?$");

            if (!std::regex_match(date, r)) {
                std::string err = "Invalid DATE format " + date;
                throw std::invalid_argument(err);
            } else {
                this->value = date;
            }
        }
    };
}

#endif //CVAST_DATATYPES_HPP
