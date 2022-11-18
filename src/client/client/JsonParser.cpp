#include "JsonParser.hpp"
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include <memory>

namespace client {

    void JsonParser::readInterfaceJson(std::string state) {
        /*unique_ptr <Json::CharReader> reader = unique_ptr<Json::CharReader>(builder.newCharReader());
        Json::Value val{};
        string err{};
        this->effects = unordered_map<string, Effect>();

        reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
        this->effects.reserve(val.size());

        for (Json::ValueIterator effect = val.begin(); effect != val.end(); effect++) {
            this->effects[effect.name()] = Effect(val[effect.name()]);
        }*/
    }
}