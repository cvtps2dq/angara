//
// Created by cv2 on 29.09.2024.
//

#ifndef HANDLECHARLITERAL_H
#define HANDLECHARLITERAL_H
#include <iostream>
#include <string>
#include "../Token.h"

namespace LexerShards {
    inline Token handleCharLiteral(char currentChar, std::string& source, unsigned long& position) {
        position++; // Skip the opening quote
        std::string charLiteral;
        if (position < source.size() && source[position] != '\'') {
            charLiteral += source[position++]; // Add character
        }
        if (position < source.size() && source[position] == '\'') {
            position++; // Skip the closing quote
            return { TokenType::Char, charLiteral };
        }
        std::cerr << "Error: Unmatched quote for character literal\n";
        return { TokenType::Error, "" };
    }
}

#endif //HANDLECHARLITERAL_H
