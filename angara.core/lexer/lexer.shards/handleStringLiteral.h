//
// Created by cv2 on 29.09.2024.
//

#ifndef HANDLESTRINGLITERAL_H
#define HANDLESTRINGLITERAL_H
#include <iostream>
#include <string>
#include "../Lexer.h"

namespace LexerShards {
    inline Token handleStringLiteral(char currentChar, std::string& source, unsigned long& position) {
        position++; // Skip the opening quote
        std::string stringLiteral;
        while (position < source.size() && source[position] != '"') {
            stringLiteral += source[position++];
        }
        if (position < source.size() && source[position] == '"') {
            position++; // Skip the closing quote
            return { TokenType::String, stringLiteral };
        }
        std::cerr << "Error: Unmatched quote for string literal\n";
        return { TokenType::Error, "" };
    }
}
#endif //HANDLESTRINGLITERAL_H
