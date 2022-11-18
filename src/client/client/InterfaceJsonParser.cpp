#include "InterfaceJsonParser.hpp"
#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>
#include <memory>

namespace client {

    void InterfaceJsonParser::readInterfaceJson(std::string state) {

        /*Json::CharReaderBuilder rbuilder;
        cfg >> rbuilder.settings_;
        reader->parse(start, stop, &value1, &errs);
// ...
        reader->parse(start, stop, &value2, &errs);


        Json::CharReaderBuilder builder;
        std::unique_ptr <Json::CharReader> const reader (builder.newCharReader());



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