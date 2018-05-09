
#include <iostream>
#include "cvast/cvast_v4.hpp"

using namespace std;
using namespace Cvast;
using namespace Vast4;

int main() {
    string xml = "<VAST version=\"4.0\"> <Ad id=\"1gl2d3\"> <InLine> <AdSystem version=\"1.2.3\">Example Ads</AdSystem> <AdTitle> <![CDATA[ Branded Avengers ]]> </AdTitle> <Impression> <![CDATA[ about:blank ]]> </Impression> <Creatives> <Creative> <UniversalAdId>abcdef</UniversalAdId> <Linear> <Duration>00:02:18</Duration> <MediaFiles> <MediaFile delivery=\"progressive\" width=\"320\" height=\"133\" type=\"application/javascript\" apiFramework=\"VPAID\"> <![CDATA[ https://cdn.example.com ]]> </MediaFile> </MediaFiles> </Linear> </Creative> </Creatives> </InLine> </Ad> </VAST>";

    Cvast_v4 cvast(xml, true);
    Vast vast = cvast.getVast();

    printf("%f\n", vast.attrs.version);

    {
        string path = "vast/ad0";
        Ad* ad = cvast.api<Ad>(path).get();
        printf("%s\n", ad->attrs.id.c_str());
        printf("%s\n", cvast.api<>(path).attr("id")->c_str());
    }

    {
        string path = "vast/ad0/inLine/adSystem";
        AdSystem* adSystem = cvast.api<AdSystem>(path).get();
        printf("%s\n", adSystem->attrs.version.c_str());
        printf("%s\n", vast.ad[0].inLine[0].adSystem[0].attrs.version.c_str());
        printf("%s\n", cvast.api<>(path).attr("version")->c_str());
    }

    return 0;
}