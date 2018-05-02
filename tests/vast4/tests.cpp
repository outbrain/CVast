
#define CATCH_CONFIG_MAIN

#include <string>
#include <iostream>
#include "../catch.hpp"
#include "../../cvast/cvast_v4.hpp"
//#include "values.h"
//#include "requirements.h"

using namespace std;

struct Initializer {
private:
    string content = "";

public:
    Initializer (const string& path) {
        string line;
        ifstream f(path);

        if (f.is_open()) {

            while (getline(f, line))
                this->content += line;

            f.close();
        }
    }

    string getContent () {
        return this->content;
    }
};

//Initializer init("resources/vast_1.xml");
//Cvast::Cvast_v4 cvast(init.getContent(), true, true);

Initializer init2("resources/vast_2.xml");
Cvast::Cvast_v4 cvast2(init2.getContent(), true, true);

int test () {
    //Cvast::Vast4::Creative* vast = cvast.api<Cvast::Vast4::Creative>("vast/ads0/inLine/creatives/creative0").get();
    Cvast::Vast4::Creative* vast2 = cvast2.api<Cvast::Vast4::Creative>("vast/ads0/inLine/creatives/creative0").get();

    //printf("%s\n", vast->attrs.id.c_str());
    printf("%s\n", vast2->attrs.id.c_str());
    //printf("%s\n", vast->attrs.id.c_str());

    return 0;
}

int t = test();

//Values values;
//Requirements requirements;
