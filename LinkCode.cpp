

#include "LinkCode.h"

LinkCode::LinkCode(const std::string &content) {
    if (content.length() == codeLength) {
        auto it = content.begin();
        while (it != content.end() && std::isdigit(*it)) ++it;
        if (it == content.end()) {  // content is a number
            this->content = content;
        }
    }
}

bool LinkCode::Valid() {
    return content.has_value();
}

std::string LinkCode::GetContent() {
    return content.value();
}