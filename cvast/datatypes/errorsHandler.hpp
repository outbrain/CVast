
#ifndef CVAST_ERRORSHANDLER_HPP
#define CVAST_ERRORSHANDLER_HPP

#include <array>

namespace Cvast {
    class ErrorsHandler {
    private:
        static std::map<int, std::string> errorCodes () {
            std::map<int, std::string> codesTable;

            codesTable.insert(std::make_pair(PARSING_ERR, "XML parsing error."));
            codesTable.insert(std::make_pair(INVALID_VAST, "VAST schema validation error."));
            codesTable.insert(std::make_pair(VAST_VER_NOT_SUPPORTED, "VAST version of response not supported."));
            codesTable.insert(std::make_pair(TRAFFIC_ERR, "Trafficking error. Video player received an Ad type that it was not expecting and/or cannot display."));
            codesTable.insert(std::make_pair(LINEAR_ERR, "Video player expecting different linearity."));
            codesTable.insert(std::make_pair(DURATION_ERR, "Video player expecting different duration."));
            codesTable.insert(std::make_pair(SIZE_ERR, "Video player expecting different size."));
            codesTable.insert(std::make_pair(AD_CATEGORY_REQUIRED, "Ad category was required but not provided."));
            codesTable.insert(std::make_pair(WRAPPER_ERR, "General Wrapper error."));
            codesTable.insert(std::make_pair(URI_TIMEOUT, "Timeout of VAST URI provided in Wrapper element, or of VAST URI provided in a subsequent Wrapper element."));
            codesTable.insert(std::make_pair(WRAPPER_LIMIT_ERR, "Wrapper limit reached, as defined by the video player. Too many Wrapper responses have been received with no InLine response."));
            codesTable.insert(std::make_pair(VAST_WRAPPER_ERR, "No VAST response after one or more Wrappers."));
            codesTable.insert(std::make_pair(INLINE_AD_UNIT_ERR, "InLine response returned ad unit that failed to result in ad display within defined time limit."));
            codesTable.insert(std::make_pair(LINEAR_AD_ERR, "General Linear error. Video player is unable to display the Linear Ad."));
            codesTable.insert(std::make_pair(URI_FILE_NOT_FOUND, "File not found. Unable to find Linear/MediaFile from URI."));
            codesTable.insert(std::make_pair(MEDIA_URI_TIMEOUT, "Timeout of MediaFile URI."));
            codesTable.insert(std::make_pair(MEDIA_NOT_SUPPORTED, "Couldn’t find MediaFile that is supported by this video player, based on the attributes of the MediaFile element."));
            codesTable.insert(std::make_pair(MEDIA_DISPLAY_ERR, "Problem displaying MediaFile. Video player found a MediaFile with supported type but couldn’t display it."));
            codesTable.insert(std::make_pair(MEZZANINE_REQUIRED, "Mezzanine was required but not provided. Ad not served."));
            codesTable.insert(std::make_pair(MEZZANINE_DOWN, "Mezzanine is in the process of being downloaded for the first time."));
            codesTable.insert(std::make_pair(COND_AD_REJECT, "Conditional ad rejected."));
            codesTable.insert(std::make_pair(INTERACTIVE_UNIT_ERR, "Interactive unit in the InteractiveCreativeFile node was not executed."));
            codesTable.insert(std::make_pair(VERIF_UNIT_ERR, "Verification unit in the Verification node was not executed."));
            codesTable.insert(std::make_pair(MEZZANINE_FILE_ERR, "Mezzanine was provided as required, but file did not meet required specification. Ad not served."));
            codesTable.insert(std::make_pair(NON_LINEAR_ADS_ERR, "General NonLinearAds error."));
            codesTable.insert(std::make_pair(CREATIVE_DIM_ERR, "Unable to display NonLinear Ad because creative dimensions do not align with creative display area"));
            codesTable.insert(std::make_pair(NON_LINEAR_FETCH_ERR, "Unable to fetch NonLinearAds/NonLinear resource."));
            codesTable.insert(std::make_pair(NON_LINEAR_TYPE_ERR, "Couldn’t find NonLinear resource with supported type."));
            codesTable.insert(std::make_pair(COMPANION_ERR, "General CompanionAds error."));
            codesTable.insert(std::make_pair(COMPANION_DIM_ERR, "Unable to display Companion because creative dimensions do not fit within Companion display area"));
            codesTable.insert(std::make_pair(COMPANION_DISPLAY_ERR, "Unable to display required Companion."));
            codesTable.insert(std::make_pair(COMPANION_FETCH_ERR, "Unable to fetch CompanionAds/Companion resource."));
            codesTable.insert(std::make_pair(COMPANION_TYPE_ERR, "Couldn’t find Companion resource with supported type."));
            codesTable.insert(std::make_pair(UNDEFINED_ERR, "Undefined Error."));
            codesTable.insert(std::make_pair(VPAID_ERR, "General VPAID error."));

            return codesTable;
        }

    public:
        enum EC {
            PARSING_ERR = 100,
            INVALID_VAST = 101,
            VAST_VER_NOT_SUPPORTED = 102,
            TRAFFIC_ERR = 200,
            LINEAR_ERR = 201,
            DURATION_ERR = 202,
            SIZE_ERR = 203,
            AD_CATEGORY_REQUIRED = 204,
            WRAPPER_ERR = 300,
            URI_TIMEOUT = 301,
            WRAPPER_LIMIT_ERR = 302,
            VAST_WRAPPER_ERR = 303,
            INLINE_AD_UNIT_ERR = 304,
            LINEAR_AD_ERR = 400,
            URI_FILE_NOT_FOUND = 401,
            MEDIA_URI_TIMEOUT = 402,
            MEDIA_NOT_SUPPORTED = 403,
            MEDIA_DISPLAY_ERR = 405,
            MEZZANINE_REQUIRED = 406,
            MEZZANINE_DOWN = 407,
            COND_AD_REJECT = 408,
            INTERACTIVE_UNIT_ERR = 409,
            VERIF_UNIT_ERR = 410,
            MEZZANINE_FILE_ERR = 411,
            NON_LINEAR_ADS_ERR = 500,
            CREATIVE_DIM_ERR = 501,
            NON_LINEAR_FETCH_ERR = 502,
            NON_LINEAR_TYPE_ERR = 503,
            COMPANION_ERR = 600,
            COMPANION_DIM_ERR = 601,
            COMPANION_DISPLAY_ERR = 602,
            COMPANION_FETCH_ERR = 603,
            COMPANION_TYPE_ERR = 604,
            UNDEFINED_ERR = 900,
            VPAID_ERR = 901
        };

        static std::array<int, 15> invalids () {
            std::array<int, 15> invalid_args = {
                    INVALID_VAST,
                    VAST_VER_NOT_SUPPORTED,
                    TRAFFIC_ERR,
                    LINEAR_ERR,
                    DURATION_ERR,
                    SIZE_ERR,
                    AD_CATEGORY_REQUIRED,
                    WRAPPER_LIMIT_ERR,
                    MEDIA_NOT_SUPPORTED,
                    MEZZANINE_REQUIRED,
                    MEZZANINE_FILE_ERR,
                    CREATIVE_DIM_ERR,
                    NON_LINEAR_TYPE_ERR,
                    COMPANION_DIM_ERR,
                    COMPANION_TYPE_ERR
            };

            return invalid_args;
        };

        static std::array<int, 20> runtimes () {
            std::array<int, 20> runtime_args = {
                    PARSING_ERR,
                    WRAPPER_ERR,
                    URI_TIMEOUT,
                    INLINE_AD_UNIT_ERR,
                    VAST_WRAPPER_ERR,
                    LINEAR_AD_ERR,
                    URI_FILE_NOT_FOUND,
                    MEDIA_URI_TIMEOUT,
                    MEDIA_DISPLAY_ERR,
                    MEZZANINE_DOWN,
                    COND_AD_REJECT,
                    INTERACTIVE_UNIT_ERR,
                    VERIF_UNIT_ERR,
                    NON_LINEAR_ADS_ERR,
                    NON_LINEAR_FETCH_ERR,
                    COMPANION_ERR,
                    COMPANION_DISPLAY_ERR,
                    COMPANION_FETCH_ERR,
                    UNDEFINED_ERR,
                    VPAID_ERR
            };

            return runtime_args;
        };

        static void err (int errCode, const std::string& errWhat, bool isPermissive = false) {
            if (!isPermissive) {
                const std::map<int, std::string> codesTable = ErrorsHandler::errorCodes();
                std::array<int, 15> invalid_args = ErrorsHandler::invalids();
                int *isInvalidChild = std::find(std::begin(invalid_args), std::end(invalid_args), errCode);
                std::string err = codesTable.at(errCode);
                err += " ";
                err += errWhat;

                if (isInvalidChild != std::end(invalid_args)) {
                    throw std::invalid_argument(err);
                } else {
                    throw std::runtime_error(err);
                }
            }
        }
    };
}

#endif //CVAST_ERRORSHANDLER_HPP
