//
// Created by cv2 on 29.09.2024.
//

// Handle identifiers and keywords
#pragma once

#include <string>

#include "../Token.h"
namespace LexerShards {
    inline Token handleKeywords(char currentChar, const std::string &source, unsigned long &position) {
        std::string identifier;
        while (isalnum(currentChar) || currentChar == '_') {
            identifier += currentChar;
            currentChar = source[++position];
        }
        // Check if it's a keyword (e.g., "def")
        if (identifier == "def" || identifier == "as" ||
            identifier == "int8" || identifier == "int16" ||
            identifier == "int32" || identifier == "int64" ||
            identifier == "float" || identifier == "double" ||
            identifier == "char" || identifier == "string"
            || identifier == "bool") {
            return { TokenType::Keyword, identifier };
            }
        if (identifier == "true") {
            return { TokenType::Bool, "true" };
        }
        if (identifier == "false") {
            return { TokenType::Bool, "false" };
        }
        return { TokenType::Identifier, identifier };
    }
}