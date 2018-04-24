
#ifndef CVAST_DATATYPES_HPP
#define CVAST_DATATYPES_HPP

#include <regex>
#include "../rapidxml/rapidxml_print.hpp"
#include "../utils/vastUtils.hpp"

namespace Cvast {
    struct URL {
        std::string value;

        URL () {}

        URL (std::string url) {
            std::regex r("(http|ftp|https)://([\\w+?\\.\\w+])+([a-zA-Z0-9\\~\\!\\@\\#\\$\\%\\^\\&\\*\\(\\)_\\-\\=\\+\\\\\\/\\?\\.\\:\\;\\'\\,]*)?");

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

    struct TIME {
        std::string value;

        TIME () {}

        TIME (std::string time) {
            std::regex r("^(?:(?:([01]?\\d|2[0-3]):)([0-5]?\\d):)([0-5]?\\d)([.]\\d{3})?$");

            if (!std::regex_match(time, r)) {
                std::string err = "Invalid TIME format " + time;
                throw std::invalid_argument(err);
            } else {
                this->value = time;
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
            std::string mime[66] = {
                    "application/octet-stream", "application/http", "application/javascript", "application/json", "application/mp4", "application/node", "application/ogg",
                    "application/passport", "application/pdf", "application/postscript", "application/rdf+xml", "application/rtf", "application/soap+xml", "application/sql",
                    "application/xhtml+xml", "application/xml", "application/zip", "application/zlib", "audio/3gpp", "audio/3gpp2", "audio/aac", "audio/mp4", "audio/mpeg", "audio/webm",
                    "audio/ogg", "audio/vorbis", "audio/vorbis-config", "font/otf", "font/ttf", "font/woff", "font/woff2", "image/bmp", "image/png", "image/tiff", "image/jpg",
                    "image/gif", "message/http", "model/x3d-vrml", "model/x3d+xml", "multipart/form-data", "multipart/encrypted", "multipart/report", "multipart/signed", "text/plain",
                    "text/css", "text/csv", "text/dns", "text/ecmascript", "text/html", "text/javascript", "text/markdown", "text/rtf", "text/xml", "text/xml-external-parsed-entity",
                    "video/3gpp", "video/3gpp2", "video/h261", "video/h263", "video/h264", "video/jpeg", "video/mp4", "video/ogg", "video/quicktime", "video/webm", "video/mpeg", "video/x-ms-wmv"
            };

            VastUtils::toLowerCase(mimeType);

            std::string *isMime = find(begin(mime), end(mime), mimeType);
            if (isMime != end(mime)) {
                this->value = std::move(mimeType);
            } else {
                throw std::invalid_argument("Invalid mime-type " + mimeType);
            }
        }
    };

    struct XML {
        std::string value;

        XML () {}

        XML (rapidxml::xml_node<> *node) {
            if (rapidxml::node_element == node->first_node()->type()) {
                rapidxml::print(std::back_inserter(this->value), *node->first_node(), rapidxml::print_no_indenting);
            } else {
                throw invalid_argument("Invalid XML element");
            }
        }
    };
}

#endif //CVAST_DATATYPES_HPP
