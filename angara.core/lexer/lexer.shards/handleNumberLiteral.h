//
// Created by cv2 on 29.09.2024.
//

#ifndef HANDLENUMBERLITERAL_H
#define HANDLENUMBERLITERAL_H
#include <string>
#include "../Lexer.h"

namespace LexerShards {
    inline Token handleNumberLiteral(char currentChar, std::string& source, unsigned long& position) {
        std::string number;
        // Collect digits before the decimal point
        while (isdigit(currentChar)) {
            number += currentChar;

            currentChar = source[++position];
        }
        // Check for a decimal point
        if (currentChar == '.') {
            number += currentChar; // Add the decimal point
            currentChar = source[++position];
            // Collect digits after the decimal point
            while (isdigit(currentChar)) {
                number += currentChar;
                currentChar = source[++position];
            }
        }
        return { TokenType::Number, number };
    }
}

#endif //HANDLENUMBERLITERAL_H