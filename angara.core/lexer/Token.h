//
// Created by cv2 on 29.09.2024.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>

enum class TokenType {
    Identifier, Keyword, Number, String, Char, Operator, Symbol, EndOfFile, Error, Bool, BoolValue
};

struct Token {
    TokenType type = {};
    std::string value;

    void print() const {
        std::cout << "Token(Type: " << static_cast<int>(type) << ", Value: '" << value << "')\n";
    }
};

#endif //TOKEN_H
