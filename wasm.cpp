
#include <iostream>
#include <emscripten.h>
#include <emscripten/bind.h>
#include "cvast/cvast.hpp"

using namespace std;
using namespace Cvast;
using namespace VideoTemplate;

class JSVast {
private:
    shared_ptr<C_vast> cvast;

public:
    JSVast (const string& vastXML, bool isPermissive) {
        try {
            this->cvast = make_shared<C_vast>(vastXML, isPermissive);
        } catch (const std::exception& e) {
            EM_ASM_({
                console.error(UTF8ToString($0));
            }, e.what());
        }
    }

    string getAttribute (const string& path, const string& attrName) {
        string res;
        try {
            res = *(this->cvast->api<>(path).attr(attrName));
        } catch (const std::invalid_argument& e) {
            EM_ASM_({
                console.error(UTF8ToString($0));
            }, e.what());
        }

        return res;
    }

    string getValue (const string& path) {
        string res;
        try {
            res = *(this->cvast->api<>(path).val());
        } catch (const std::invalid_argument& e) {
            printf("%s", e.what());
            EM_ASM_({
                console.error(UTF8ToString($0));
            }, e.what());
        }

        return res;
    }
};

EMSCRIPTEN_BINDINGS (components) {
    emscripten::class_<JSVast>("JSVast")
        .constructor<string, bool>()
        .function("getAttribute", &JSVast::getAttribute)
        .function("getValue", &JSVast::getValue);
}

int main () {
    EM_ASM(
        _onJSVastLoad();
    );

    return 0;
}
