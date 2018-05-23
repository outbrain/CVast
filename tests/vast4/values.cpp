
#include "values.h"

using namespace std;
using namespace Cvast;
using namespace VideoTemplate;

Values::Values (const string& content, int idx) {
    Cvast::C_vast cvast(content, true);

    switch (idx) {
        case 1: this->test_1(cvast); break;
        case 2: this->test_2(cvast); break;
    }

    this->printErrors();
}

void Values::test_1 (Cvast::C_vast& cvast) {
    // Ad id attribute
    {
        string v = "415971838";
        this->path = "vast/ad0";
        Ad* ad = cvast.api<Ad>(path).get();
        this->equal(ad->attrs.id, v);
        this->equal(*(cvast.api<>(this->path).attr("id")), v);
    }

    // AdSystem value
    {
        string v = "DCM";
        this->path = "vast/ad0/inLine/adSystem";
        AdSystem* adsystem = cvast.api<AdSystem>(path).get();
        this->equal(adsystem->value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //AdTitle value
    {
        string v = "In-Stream Video";
        this->path = "vast/ad0/inLine/adTitle";
        AdTitle* adtitle = cvast.api<AdTitle>(path).get();
        this->equal(adtitle->value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Impression #2 value
    {
        string v = "https://ad.example.com/i/img;adv=11112202569417;ec=11112202581977;adv.a=4632604;c.a=20914176;s.a=3081330;p.a=217135556;a.a=415971838;cache=2396416198;?site_id=";
        this->path = "vast/ad0/inLine/impression1";
        Impression* impression = cvast.api<Impression>(path).get();
        this->equal(impression->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Creative sequence attribute
    {
        int v = 1;
        this->path = "vast/ad0/inLine/creatives/creative0";
        Creative* creative = cvast.api<Creative>(path).get();
        this->equal(creative->attrs.sequence, v);
        this->equal(*(cvast.api<>(this->path).attr("sequence")), to_string(v));
    }

    //Duration value
    {
        string v = "00:00:06";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/duration";
        Duration* duration = cvast.api<Duration>(path).get();
        this->equal(duration->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Tracking firstQuartile value
    {
        string v = "https://ade.example.com/test/activity/dc_oe=ChMI6avn9aDY2gIVSoZ3Ch3-pANrEAAYACDhqbUv;met=1;ecn1=1;etm1=0;eid1=960584;";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/trackingEvents/tracking1";
        Tracking* tracking = cvast.api<Tracking>(path).get();
        this->equal(tracking->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Tracking pause value
    {
        string v = "https://ade.example.com/test/activity/dc_oe=ChMI6avn9aDY2gIVSoZ3Ch3-pANrEAAYACDhqbUv;met=1;ecn1=1;etm1=0;eid1=15;";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/trackingEvents/tracking7";
        Tracking* tracking = cvast.api<Tracking>(path).get();
        this->equal(tracking->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //VideoClicks clickThrough value
    {
        string v = "https://adclick.t.example.net/pcs/click?xai=AKAOjsvxAl1oyFPGf6TuKyDJvrmf9m-EP9ZUkb2c6JwK8MIJPxgmrvkCvtqQJ6FkApLYp-4Oj1HyjSKx5B-3gLVbQbWsXYtSYhhssDhpM7bw_95m&sig=Cg0ArKJSzHTO14-79b0dEAE&urlfix=1&adurl=https://youtu.be/6bqKTRhZdbY";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/videoClicks/clickThrough";
        ClickThrough* click = cvast.api<ClickThrough>(path).get();
        this->equal(click->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //MediaFile #1 apiFramework attribute & value
    {
        string a = "VPAID";
        string v = "https://imasdk.example.com/js/vpaid_adapter.js";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile0";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.apiFramework, a);
        this->equal(*(cvast.api<>(this->path).attr("apiFramework")), a);
        this->equal(media->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //MediaFile #4 type attribute
    {
        string v = "video/mp4";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile3";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.type.value, v);
        this->equal(*(cvast.api<>(this->path).attr("type")), v);
    }

    //MediaFile #4 width attribute
    {
        int v = 640;
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile3";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.width, v);
        this->equal(*(cvast.api<>(this->path).attr("width")), to_string(v));
    }

    //MediaFile #4 value
    {
        string v = "https://www.example.net/videoplayback/id/a6902bfa8166c753/itag/18/source/doubleclick_dmm/ratebypass/yes/acao/yes/ip/0.0.0.0/ipbits/0/expire/3666059399/sparams/id,itag,source,ratebypass,acao,ip,ipbits,expire/signature/625E47DBE4ACDC5F09C6E25D6DBAD215EAE61B61.43A5088E5B68CCC0D253ACE29BE8D932C726C98B/key/ck2/file/file.mp4";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile3";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //MediaFile #6 type attribute
    {
        string v = "video/mp4";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile5";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.type.value, v);
        this->equal(*(cvast.api<>(this->path).attr("type")), v);
    }

    //MediaFile #6 width attribute
    {
        int v = 1920;
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile5";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.width, v);
        this->equal(*(cvast.api<>(this->path).attr("width")), to_string(v));
    }

    //MediaFile #6 value
    {
        string v = "https://www.example.net/videoplayback/id/a6902bfa8166c753/itag/37/source/doubleclick_dmm/ratebypass/yes/acao/yes/ip/0.0.0.0/ipbits/0/expire/3666059429/sparams/id,itag,source,ratebypass,acao,ip,ipbits,expire/signature/29768802ECA66371DF04D927D7362AA9624C8449.2E3547BED3B0759745BC7EFC8954B3C6769F8400/key/ck2/file/file.mp4";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile5";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Extension #1 value
    {
        string v = "<Country>US</Country><Bandwidth>4</Bandwidth><BandwidthKbps>18500</BandwidthKbps>";
        this->path = "vast/ad0/inLine/extensions/extension0";
        Extension* ext = cvast.api<Extension>(this->path).get();
        this->equal(ext->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }
}

void Values::test_2 (Cvast::C_vast& cvast) {
    // Ad id attribute
    {
        string v = "417006538";
        this->path = "vast/ad0";
        Ad* ad = cvast.api<Ad>(path).get();
        this->equal(ad->attrs.id, v);
        this->equal(*(cvast.api<>(this->path).attr("id")), v);
    }

    //AdTitle value
    {
        string v = "In-Stream Video";
        this->path = "vast/ad0/inLine/adTitle";
        AdTitle* adtitle = cvast.api<AdTitle>(path).get();
        this->equal(adtitle->value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    // Error value
    {
        string v = "https://ade.example.com/ddm/activity/dc_oe=ChMI2Yvgmpjn2gIVVQvgCh36ngiQEAAYACCK0dIv;met=1;ecn1=1;etm1=0;eid1=200015;";
        this->path = "vast/ad0/inLine/error0";
        Error* error = cvast.api<Error>(path).get();
        this->equal(error->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Impression #1 value
    {
        string v = "https://ads.e.example.net/pcs/view?xai=AKAOjsvqbpCqEZAiPv3q9AIWPpWLgWppQeE7tcp2uHArU1Sc_UXs7Iq_BJ94LTbJXtqZWtBEKv4mC0ExX4Ui30lMaNIzCJSTXNYxqiLj4cP9OXGL&sig=Cg0ArKJSzDHfWE1xUlyUEAE&urlfix=1&adurl=";
        this->path = "vast/ad0/inLine/impression0";
        Impression* impression = cvast.api<Impression>(path).get();
        this->equal(impression->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Creative id attribute
    {
        string v = "99920010";
        this->path = "vast/ad0/inLine/creatives/creative0";
        Creative* creative = cvast.api<Creative>(path).get();
        this->equal(creative->attrs.id, v);
        this->equal(*(cvast.api<>(this->path).attr("id")), v);
    }

    //Duration value
    {
        string v = "00:01:35";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/duration";
        Duration* duration = cvast.api<Duration>(path).get();
        this->equal(duration->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Tracking start value
    {
        string v = "https://ade.example.com/ddm/activity/dc_oe=ChMI2Yvgmpjn2gIVVQvgCh36ngiQEAAYACCK0dIv;met=1;ecn1=1;etm1=0;eid1=11;";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/trackingEvents/tracking0";
        Tracking* tracking = cvast.api<Tracking>(path).get();
        this->equal(tracking->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Tracking complete value
    {
        string v = "https://ade.example.com/ddm/activity/dc_oe=ChMI2Yvgmpjn2gIVVQvgCh36ngiQEAAYACCK0dIv;met=1;ecn1=1;etm1=0;eid1=13;";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/trackingEvents/tracking4";
        Tracking* tracking = cvast.api<Tracking>(path).get();
        this->equal(tracking->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //AdParameters value
    {
        string v = "&lt;?xml version=&quot;1.0&quot; encoding=&quot;UTF-8&quot;?&gt; &lt;VAST xmlns:xsi=&quot;http://www.w3.org/2001/XMLSchema-instance&quot; xsi:noNamespaceSchemaLocation=&quot;vast.xsd&quot; version=&quot;2.0&quot;&gt; &lt;/VAST&gt;";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/adParameters";
        AdParameters* params = cvast.api<AdParameters>(path).get();
        this->equal(params->value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //MediaFile #1 apiFramework attribute & value
    {
        string a = "VPAID";
        string v = "https://imasdk.example.com/js/vpaid_adapter.js";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile0";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.apiFramework, a);
        this->equal(*(cvast.api<>(this->path).attr("apiFramework")), a);
        this->equal(media->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //MediaFile #2 type attribute
    {
        string v = "video/mp4";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile1";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.type.value, v);
        this->equal(*(cvast.api<>(this->path).attr("type")), v);
    }

    //MediaFile #2 width attribute
    {
        int v = 854;
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile1";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.width, v);
        this->equal(*(cvast.api<>(this->path).attr("width")), to_string(v));
    }

    //MediaFile #2 value
    {
        string v = "https://www.example.net/videoplayback/id/872178520d29bba5/itag/59/source/doubleclick_dmm/ratebypass/yes/acao/yes/ip/0.0.0.0/ipbits/0/expire/3667352225/sparams/id,itag,source,ratebypass,acao,ip,ipbits,expire/signature/7989A24B458F1DD81F72311E5D36DBC28093541A.708489853472719D56B7CE83BB85AD72E79F6370/key/ck2/file/file.mp4";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile1";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //MediaFile #4 type attribute
    {
        string v = "application/x-mpeg";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile3";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.type.value, v);
        this->equal(*(cvast.api<>(this->path).attr("type")), v);
    }

    //MediaFile #4 width attribute
    {
        int v = 256;
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile3";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->attrs.width, v);
        this->equal(*(cvast.api<>(this->path).attr("width")), to_string(v));
    }

    //MediaFile #4 value
    {
        string v = "https://www.example.net/api/manifest/hls_variant/source/doubleclick_dmm/id/872178520d29bba5/itag/0/playlist_type/LIVE/ei/oqzFWqOAO8aSuwKC9Lm4DQ/susc/dcdmm/ip/0.0.0.0/ipbits/0/expire/3667352227/sparams/ip,ipbits,expire,source,id,itag,playlist_type,ei,susc/signature/A9BDBEACD8C8710AB099D26AEC4489DEBFDE64.0E788E0C06303177F2742C23DDB2AF73B04ABABC/key/ck2/file/index.m3u8";
        this->path = "vast/ad0/inLine/creatives/creative0/linear/mediaFiles/mediaFile3";
        MediaFile* media = cvast.api<MediaFile>(this->path).get();
        this->equal(media->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }

    //Extension #1 value
    {
        string v = "<Country>US</Country><Bandwidth>4</Bandwidth><BandwidthKbps>19480</BandwidthKbps>";
        this->path = "vast/ad0/inLine/extensions/extension0";
        Extension* ext = cvast.api<Extension>(this->path).get();
        this->equal(ext->value.value, v);
        this->equal(*(cvast.api<>(this->path).val()), v);
    }
}
