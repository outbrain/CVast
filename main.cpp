
#include <iostream>
#include <chrono>

#include "cvast/cvast_v4.hpp"

int main() {
    std::string xml = "<VAST version=\"4.0\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns=\"http://www.iab.com/VAST\"><Tttt></Tttt> <Ad id=\"20001\" sequence=\"1\" conditionalAd=\"false\"> <InLine> <AdSystem version=\"4.0\">iabtechlab</AdSystem> <Error>http://example.com/error</Error> <Impression id=\"Impression-ID\">http://example.com/track/impression</Impression> <Pricing model=\"cpm\" currency=\"USD\"> <![CDATA[ 25.00 ]]> </Pricing> <AdTitle>Inline Simple Ad</AdTitle> <AdVerifications></AdVerifications> <Advertiser>IAB Sample Company</Advertiser> <Category authority=\"http://www.iabtechlab.com/categoryauthority\">AD CONTENT description category</Category> <Creatives> <creative id=\"5480\" sequence=\"1\" adId=\"2447226\"> <universalAdId idRegistry=\"Ad-ID\" idValue=\"8465\">8465</universalAdId> <Linear> <TrackingEvents> <Tracking event=\"start\" offset=\"09:15:23\">http://example.com/tracking/start</Tracking> <Tracking event=\"firstQuartile\">http://example.com/tracking/firstQuartile</Tracking> <Tracking event=\"midpoint\">http://example.com/tracking/midpoint</Tracking> <Tracking event=\"thirdQuartile\">http://example.com/tracking/thirdQuartile</Tracking> <Tracking event=\"complete\">http://example.com/tracking/complete</Tracking> </TrackingEvents> <Duration>00:00:16</Duration> <MediaFiles> <MediaFile id=\"5241\" delivery=\"progressive\" type=\"video/mp4\" bitrate=\"2000\" width=\"1280\" height=\"720\" minBitrate=\"1500\" maxBitrate=\"2500\" scalable=\"1\" maintainAspectRatio=\"1\" codec=\"0\"> <![CDATA[https://iabtechlab.com/wp-content/uploads/2016/07/VAST-4.0-Short-Intro.mp4]]> </MediaFile> <MediaFile id=\"5244\" delivery=\"progressive\" type=\"video/mp4\" bitrate=\"1000\" width=\"854\" height=\"480\" minBitrate=\"700\" maxBitrate=\"1500\" scalable=\"1\" maintainAspectRatio=\"1\" codec=\"0\"> <![CDATA[https://iabtechlab.com/wp-content/uploads/2017/12/VAST-4.0-Short-Intro-mid-resolution.mp4]]> </MediaFile> <MediaFile id=\"5246\" delivery=\"progressive\" type=\"video/mp4\" bitrate=\"600\" width=\"640\" height=\"360\" minBitrate=\"500\" maxBitrate=\"700\" scalable=\"1\" maintainAspectRatio=\"1\" codec=\"0\"> <![CDATA[https://iabtechlab.com/wp-content/uploads/2017/12/VAST-4.0-Short-Intro-low-resolution.mp4]]> </MediaFile> </MediaFiles> <VideoClicks> <ClickThrough id=\"blog\"> <![CDATA[https://iabtechlab.com]]> </ClickThrough> </VideoClicks> </Linear> </creative> </Creatives> </InLine> </Ad> </VAST>";
    std::string xml2 = "<VAST version=\"4.0\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns=\"http://www.iab.com/VAST\"><Tttt></Tttt> <Ad id=\"20002\" sequence=\"1\" conditionalAd=\"false\"> <InLine> <AdSystem version=\"4.0\">iabtechlab</AdSystem> <Error>http://example.com/error</Error> <Impression id=\"Impression-ID\">http://example.com/track/impression</Impression> <Pricing model=\"cpm\" currency=\"USD\"> <![CDATA[ 25.00 ]]> </Pricing> <AdTitle>Inline Simple Ad</AdTitle> <AdVerifications></AdVerifications> <Advertiser>IAB Sample Company</Advertiser> <Category authority=\"http://www.iabtechlab.com/categoryauthority\">AD CONTENT description category</Category> <Creatives> <creative id=\"5480\" sequence=\"1\" adId=\"2447226\"> <universalAdId idRegistry=\"Ad-ID\" idValue=\"8465\">8465</universalAdId> <Linear> <TrackingEvents> <Tracking event=\"start\" offset=\"09:15:23\">http://example.com/tracking/start</Tracking> <Tracking event=\"firstQuartile\">http://example.com/tracking/firstQuartile</Tracking> <Tracking event=\"midpoint\">http://example.com/tracking/midpoint</Tracking> <Tracking event=\"thirdQuartile\">http://example.com/tracking/thirdQuartile</Tracking> <Tracking event=\"complete\">http://example.com/tracking/complete</Tracking> </TrackingEvents> <Duration>00:00:16</Duration> <MediaFiles> <MediaFile id=\"5241\" delivery=\"progressive\" type=\"video/mp4\" bitrate=\"2000\" width=\"1280\" height=\"720\" minBitrate=\"1500\" maxBitrate=\"2500\" scalable=\"1\" maintainAspectRatio=\"1\" codec=\"0\"> <![CDATA[https://iabtechlab.com/wp-content/uploads/2016/07/VAST-4.0-Short-Intro.mp4]]> </MediaFile> <MediaFile id=\"5244\" delivery=\"progressive\" type=\"video/mp4\" bitrate=\"1000\" width=\"854\" height=\"480\" minBitrate=\"700\" maxBitrate=\"1500\" scalable=\"1\" maintainAspectRatio=\"1\" codec=\"0\"> <![CDATA[https://iabtechlab.com/wp-content/uploads/2017/12/VAST-4.0-Short-Intro-mid-resolution.mp4]]> </MediaFile> <MediaFile id=\"5246\" delivery=\"progressive\" type=\"video/mp4\" bitrate=\"600\" width=\"640\" height=\"360\" minBitrate=\"500\" maxBitrate=\"700\" scalable=\"1\" maintainAspectRatio=\"1\" codec=\"0\"> <![CDATA[https://iabtechlab.com/wp-content/uploads/2017/12/VAST-4.0-Short-Intro-low-resolution.mp4]]> </MediaFile> </MediaFiles> <VideoClicks> <ClickThrough id=\"blog\"> <![CDATA[https://iabtechlab.com]]> </ClickThrough> </VideoClicks> </Linear> </creative> </Creatives> </InLine> </Ad> </VAST>";

    auto start = std::chrono::system_clock::now();
    Cvast::Cvast_v4 cvast(xml, true);
    cvast.parse();

    Cvast::Cvast_v4 cvast2(xml2, true);
    cvast2.parse();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "elapsed: " << elapsed.count() << " sec.\n\n";

    Cvast::Vast4::Vast n = cvast.getVast();

//    shared_ptr<Cvast::GenericNode<Cvast::Vast4::Vast>> gen = dynamic_pointer_cast<Cvast::GenericNode<Cvast::Vast4::Vast>>(Cvast::holder.paths["vast"]);
//    Cvast::Vast4::Vast* vast = gen->self();

    Cvast::Vast4::Ad* ad = cvast.api<Cvast::Vast4::Ad>("vast/ads0").get();
    printf("%s\n", ad->attrs.id.c_str());

    Cvast::Vast4::Ad* ad2 = cvast2.api<Cvast::Vast4::Ad>("vast/ads0").get();
    printf("%s\n", ad2->attrs.id.c_str());

//    printf("Version from struct %f\n", n.attrs.version);
//    printf("Version from reflection %f\n", vast->attrs.version);
//    printf("Version from data %s\n", cvast.api<>("vast").attr("version")->c_str());
//
//    shared_ptr<Cvast::GenericNode<Cvast::Vast4::Ad>> gen2 = dynamic_pointer_cast<Cvast::GenericNode<Cvast::Vast4::Ad>>(Cvast::holder.paths["vast/ads0"]);
//    Cvast::Vast4::Ad* ad = gen2->self();
//
//    printf("Ad id from struct %s\n", n.ads[0].attrs.id.c_str());
//    printf("Ad id from reflection %s\n", ad->attrs.id.c_str());
//    printf("Ad id from data %s\n", Cvast::holder.dataPaths.at("vast/ads0").attrs["id"].c_str());
//
//    shared_ptr<Cvast::GenericNode<Cvast::Vast4::AdSystem>> gen3 = dynamic_pointer_cast<Cvast::GenericNode<Cvast::Vast4::AdSystem>>(Cvast::holder.paths["vast/ads0/inLine/adSystem"]);
//    Cvast::Vast4::AdSystem* adSystem = gen3->self();
//
//    printf("AdSystem version from struct %s\n", n.ads[0].inLine[0].adSystem[0].attrs.version.c_str());
//    printf("AdSystem version from reflection %s\n", adSystem->attrs.version.c_str());
//    printf("AdSystem version from data %s\n", cvast.api<>("vast/ads0/inLine/adSystem").val()->c_str());

    return 0;
}