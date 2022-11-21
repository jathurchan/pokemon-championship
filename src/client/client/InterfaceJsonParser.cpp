#include "InterfaceJsonParser.hpp"
#include "json/json.h"
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace client {

    Json::Value InterfaceJsonParser::readJsonString(std::string state) {

        std::string jsonContent = loadJsonFile("res/interfaceConfig.json");

        Json::CharReaderBuilder builder;
        std::unique_ptr<Json::CharReader> reader = std::unique_ptr<Json::CharReader> (builder.newCharReader());
        Json::Value val {};
        std::string err {};

        reader->parse(jsonContent.c_str(), jsonContent.c_str() + jsonContent.length(), &val, &err);

        return val;
    }

    std::string InterfaceJsonParser::loadJsonFile(std::string file) {

        std::ifstream jsonStream(file);
        std::stringstream jsonBuffer;
        jsonBuffer << jsonStream.rdbuf();
        std::string jsonContent = jsonBuffer.str();

        return jsonContent;
    }
}