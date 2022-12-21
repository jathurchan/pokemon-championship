#include "Type.hpp"

namespace state {

    Type::Type() = default;

    Type::Type (model::Type modelType)
    {
        this->name = modelType.GetName();   
        this->factors = modelType.GetFactors();     
    }

    Type::~Type ()
    {

    }

    float Type::GetRatio (std::string otherTypeName)
    {
        return factors[otherTypeName];
    }

}

