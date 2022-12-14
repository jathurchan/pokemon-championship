#include <iostream>
#include <string>
#include <optional>

#ifndef POKEMON_CHAMPIONSHIP_LINKCODE_H
#define POKEMON_CHAMPIONSHIP_LINKCODE_H

/**
 * LinkCode object is used to store a link code (4 digits).
 * Check if the given string is valid using Valid() before calling GetContent()
 */
class LinkCode {
public:
    explicit LinkCode(const std::string& content);
    bool Valid();
    std::string GetContent();
private:
    const size_t codeLength = 4;
    std::optional<std::string> content;
};


#endif //POKEMON_CHAMPIONSHIP_LINKCODE_H
