cmake_minimum_required(VERSION 3.9)
project(Cvast)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cvast
        rapidxml/rapidxml.hpp
        datatypes/vast4/holder.hpp
        datatypes/vast4/datastruct/impression.hpp
        datatypes/vast4/datastruct/adTitle.hpp
        datatypes/vast4/datastruct/adSystem.hpp
        datatypes/vast4/datastruct/inLine.hpp
        datatypes/vast4/datastruct/ad.hpp
        datatypes/vast4/datastruct/error.hpp
        datatypes/vast4/datastruct/vast.hpp
        datatypes/vast4/nodeTypes.hpp
        datatypes/vast4/genericNode.hpp
        utils/vastUtils.hpp
        cvast.cpp
        cvast.h
        main.cpp)