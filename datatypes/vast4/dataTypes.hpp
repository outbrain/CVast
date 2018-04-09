//
// Created by Jonathan Sellam on 04/04/2018.
//

#ifndef CVAST_DATATYPES_HPP
#define CVAST_DATATYPES_HPP

#include <regex>
#include "../../utils/vastUtils.hpp"

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

    struct PRICING_MODEL {
        std::string value;

        PRICING_MODEL () {}

        PRICING_MODEL (std::string model) {
            std::string models[4] = { "CPM", "CPC", "CPE", "CPV" };
            VastUtils::toUpperCase(model);

            std::string *isModel = find(begin(models), end(models), model);
            if (isModel != end(models)) {
                this->value = std::move(model);
            } else {
                throw std::invalid_argument("Invalid pricing model " + model);
            }
        }
    };

    struct CURRENCY {
        std::string value;

        CURRENCY () {}

        CURRENCY (std::string currency) {
            std::string iso[163] = {
                    "AED", "AFN", "ALL", "AMD", "ANG", "AOA", "ARS", "AUD", "AWG", "AZN", "BAM", "BBD", "BDT", "BGN", "BHD", "BIF", "BMD", "BND", "BOB", "BRL", "BSD", "BTN", "BWP", "BYN",
                    "BZD", "CAD", "CDF", "CHF", "CLP", "CNY", "COP", "CRC", "CUC", "CUP", "CVE", "CZK", "DJF", "DKK", "DOP", "DZD", "EGP", "ERN", "ETB", "EUR", "FJD", "FKP", "GBP", "GEL",
                    "GGP", "GHS", "GIP", "GMD", "GNF", "GTQ", "GYD", "HKD", "HNL", "HRK", "HTG", "HUF", "IDR", "ILS", "IMP", "INR", "IQD", "IRR", "ISK", "JEP", "JMD", "JOD", "JPY", "KES",
                    "KGS", "KHR", "KMF", "KPW", "KRW", "KWD", "KYD", "KZT", "LAK", "LBP", "LKR", "LRD", "LSL", "LYD", "MAD", "MDL", "MGA", "MKD", "MMK", "MNT", "MOP", "MRU", "MUR", "MVR",
                    "MWK", "MXN", "MYR", "MZN", "NAD", "NGN", "NIO", "NOK", "NPR", "NZD", "OMR", "PAB", "PEN", "PGK", "PHP", "PKR", "PLN", "PYG", "QAR", "RON", "RSD", "RUB", "RWF", "SAR",
                    "SBD", "SCR", "SDG", "SEK", "SGD", "SHP", "SLL", "SOS", "SPL", "SRD", "STN", "SVC", "SYP", "SZL", "THB", "TJS", "TMT", "TND", "TOP", "TRY", "TTD", "TVD", "TWD", "TZS",
                    "UAH", "UGX", "USD", "UYU", "UZS", "VEF", "VND", "VUV", "WST", "XAF", "BEAC", "XCD", "XDR", "XOF", "XPF", "YER", "ZAR", "ZMW", "ZWD"
            };

            VastUtils::toUpperCase(currency);

            std::string *isCurrency = find(begin(iso), end(iso), currency);
            if (isCurrency != end(iso)) {
                this->value = std::move(currency);
            } else {
                throw std::invalid_argument("Invalid pricing currency " + currency);
            }
        }
    };

    struct MIMETYPE {
        std::string value;

        MIMETYPE () {}

        MIMETYPE (std::string mimeType) {
            std::string mime[] = {
                    "text/javascript", "application/javascript", "application/json", "text/plain", "text/html", "text/css",
                    "image/png", "application/zip"
            };
        }
    };
}

#endif //CVAST_DATATYPES_HPP
