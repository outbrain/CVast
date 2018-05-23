
#ifndef CVAST_MEDIAFILES_HPP
#define CVAST_MEDIAFILES_HPP

#include "mezzanine.hpp"
#include "interactiveCreativeFile.hpp"

namespace Cvast {
    namespace VideoTemplate {
        struct MediaFileAttrs {
            string delivery;
            MIMETYPE type;
            int width;
            int height;
            string codec;
            string id;
            int bitrate;
            int minBitrate;
            int maxBitrate;
            bool scalable;
            bool maintainAspectRatio;
            string apiFramework;
        };

        struct MediaFile : VB<MediaFile> {
            MediaFileAttrs attrs;
            URL value;

            MediaFile () : VB("", A_URL, true, &(this->value)) {
                this->symbols.emplace_back("delivery", A_STRING, true, &(this->attrs.delivery));
                this->symbols.emplace_back("type", A_MIMETYPE, true, &(this->attrs.type));
                this->symbols.emplace_back("width", A_INT, true, &(this->attrs.width));
                this->symbols.emplace_back("height", A_INT, true, &(this->attrs.height));
                this->symbols.emplace_back("codec", A_STRING, false, &(this->attrs.codec));
                this->symbols.emplace_back("id", A_STRING, false, &(this->attrs.id));
                this->symbols.emplace_back("bitrate", A_INT, false, &(this->attrs.bitrate));
                this->symbols.emplace_back("minBitrate", A_INT, false, &(this->attrs.minBitrate));
                this->symbols.emplace_back("maxBitrate", A_INT, false, &(this->attrs.maxBitrate));
                this->symbols.emplace_back("scalable", A_BOOL, false, &(this->attrs.scalable));
                this->symbols.emplace_back("maintainAspectRatio", A_BOOL, false, &(this->attrs.maintainAspectRatio));
                this->symbols.emplace_back("apiFramework", A_STRING, false, &(this->attrs.apiFramework));
            }
        };

        struct MediaFiles : VB<MediaFiles> {
            vector<MediaFile> mediaFile;
            vector<Mezzanine> mezzanine;
            vector<InteractiveCreativeFile> interactiveCreativeFile;

            MediaFiles () {
                {
                    NodeWrapper<MediaFile, vector<MediaFile>> wrapper("mediaFile", true, true, this->mediaFile);
                    this->childs.insert(make_pair("MEDIAFILE", wrapper));
                }

                {
                    NodeWrapper<Mezzanine, vector<Mezzanine>> wrapper("mezzanine", false, false, this->mezzanine);
                    this->childs.insert(make_pair("MEZZANINE", wrapper));
                }

                {
                    NodeWrapper<InteractiveCreativeFile, vector<InteractiveCreativeFile>> wrapper("interactiveCreativeFile", true, false, this->interactiveCreativeFile);
                    this->childs.insert(make_pair("INTERACTIVECREATIVEFILE", wrapper));
                }
            }
        };
    }
}

#endif //CVAST_MEDIAFILES_HPP
