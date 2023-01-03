#include <memory>
#include "Type.hpp"

namespace model {
    Type::Type (char* name, Json::Value val) {
        Json::CharReaderBuilder builder;
        std::unique_ptr<Json::CharReader> reader = std::unique_ptr<Json::CharReader> (builder.newCharReader());
        std::string err {};
        this->name = name;
        this->factors = std::unordered_map<std::string, float>();
        this->factors.reserve(val.size());

        for (Json::ValueIterator factor = val.begin(); factor != val.end(); factor++){
            this->factors[factor.name()] = val[factor.name()].asFloat();
        }
    }
    
    Type::Type () {
        this->name = "Normal";
    }

    std::string Type::GetName() {
        return this->name;
    }

    float Type::GetFactor(std::string targetType) {
        if(this->factors.count(targetType)) {
            return this->factors[targetType];
        } else {
            return 1.f;
        }
    }
}
