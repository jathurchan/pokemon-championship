#include <memory>
#include "Type.hpp"

namespace model {
    Type::Type (Json::Value val) {
        Json::CharReaderBuilder builder;
        std::unique_ptr<Json::CharReader> reader = std::unique_ptr<Json::CharReader> (builder.newCharReader());
        std::string err {};
        this->factors = std::unordered_map<std::string, float>();
        this->factors.reserve(val.size());

        for (Json::ValueIterator factor = val.begin(); factor != val.end(); factor++){
            this->factors[factor.name()] = val[factor.name()].asFloat();
        }
    }
    
    std::string Type::GetName() {
        return this->name;
    }

    std::unordered_map<std::string, float> Type::GetFactors() {
        return this->factors;
    }
}
