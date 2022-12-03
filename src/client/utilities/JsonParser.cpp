#include "JsonParser.hpp"
#include <memory>
#include <fstream>

namespace utilities {

    Json::Value JsonParser::readJsonString(const std::string& file) {

        std::string jsonContent = loadJsonFile(file);

        Json::CharReaderBuilder builder;
        std::unique_ptr<Json::CharReader> reader = std::unique_ptr<Json::CharReader> (builder.newCharReader());
        Json::Value val {};
        std::string err {};

        reader->parse(jsonContent.c_str(), jsonContent.c_str() + jsonContent.length(), &val, &err);

        return val;
    }

    std::string JsonParser::loadJsonFile(const std::string& file) {

        std::ifstream jsonStream(file);
        std::stringstream jsonBuffer;
        jsonBuffer << jsonStream.rdbuf();
        std::string jsonContent = jsonBuffer.str();

        return jsonContent;
    }
}