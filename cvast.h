//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_CVAST_H
#define CVAST_CVAST_H

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <functional>
#include <tuple>
#include <memory>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <sstream>
#include "rapidxml/rapidxml.hpp"
#include "utils/vastUtils.hpp"
#include "datatypes/vast4/datastruct/vast.hpp"

using namespace std;

class CVast {

public:
    explicit CVast(std::string& xml);
    void parse();
    //Vast4::vast getVastNode();

private:
    string& xml;
    vector<char> writableXML;
    rapidxml::xml_document<> doc;
    Vast4::Vast vastNode;
};


//void Vast4::VastAdapter::setFnMap () {
//    this->fnMap.insert(std::pair<int, std::function<void()>>(Vast4Types::VAST, std::bind(&Vast4::VastAdapter::setVast, this)));
//};


#endif //CVAST_CVAST_H
