//
// Created by cv2 on 29.09.2024.
//

#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "Token.h"


class Lexer {
public:
    explicit Lexer(std::string  source) : source(std::move(source)), position(0) {}
    Token nextToken();

private:
    std::string source;
    size_t position;

    const std::unordered_map<std::string, TokenType> keywords = {
        {"function", TokenType::Keyword},
        {"returns", TokenType::Keyword},
        {"throws", TokenType::Keyword},
        {"def", TokenType::Keyword},
        {"attach", TokenType::Keyword},
        {"if", TokenType::Keyword},
        {"else", TokenType::Keyword},
        {"switch", TokenType::Keyword},
        {"case", TokenType::Keyword},
        {"break", TokenType::Keyword},
        {"try", TokenType::Keyword},
        {"catch", TokenType::Keyword},
        {"finally", TokenType::Keyword}
    };

    const std::unordered_set<std::string> operators = {
        "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="
    };

    const std::unordered_set<std::string> symbols = {
        "{", "}", "(", ")", "[", "]", ";", ","
    };
};



#endif //LEXER_H
