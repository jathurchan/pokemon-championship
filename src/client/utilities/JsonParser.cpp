#include "JsonParser.hpp"
#include <memory>
#include <fstream>
#include <iostream>

namespace utilities {

    const char* JsonParser::configFile = "res/config.json";

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

    void JsonParser::writeJsonFile() {

        Json::StreamWriterBuilder builder;
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

        std::fstream file;
        file.open("res/test.json", std::fstream::out);
        file << Json::writeString(builder, getConfigInfo()) << std::endl;
        file.close();
    }

    Json::Value* JsonParser::getConfigInfo() {
        static Json::Value configInfo = readJsonString(configFile);
        return &configInfo;
    }
}