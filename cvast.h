//
// Created by Jonathan Sellam on 23/03/2018.
//

#ifndef CVAST_CVAST_H
#define CVAST_CVAST_H

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <tuple>
#include <memory>
#include <algorithm>
#include "rapidxml/rapidxml.hpp"
#include "utils/vastUtils.hpp"
#include "datatypes/vast4/datastruct/vast.hpp"
#include "datatypes/vast4/genericNode.hpp"

using namespace std;

class CVast {

public:
    explicit CVast(char* xml);
    void parse();
    Vast4::vast getVastNode();

private:
    char* xml;
    rapidxml::xml_document<> doc;
    Vast4::vast vastNode;
};


//void Vast4::VastAdapter::setFnMap () {
//    this->fnMap.insert(std::pair<int, std::function<void()>>(Vast4Types::VAST, std::bind(&Vast4::VastAdapter::setVast, this)));
//};


#endif //CVAST_CVAST_H
