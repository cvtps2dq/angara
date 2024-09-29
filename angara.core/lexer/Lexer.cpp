//
// Created by cv2 on 29.09.2024.
//

#include "Lexer.h"

Token Lexer::nextToken() {
    // Skip whitespace
    while (position < source.size() && isspace(source[position])) {
        position++;
    }

    // End of file
    if (position >= source.size()) {
        return {TokenType::EndOfFile, ""};
    }

    // Check for identifiers and keywords
    if (isalpha(source[position])) {
        std::string identifier;
        while (position < source.size() && (isalnum(source[position]) || source[position] == '_')) {
            identifier += source[position++];
        }
        if (keywords.contains(identifier)) {
            return {TokenType::Keyword, identifier};
        }
        return {TokenType::Identifier, identifier};
    }

    // Check for numbers
    if (isdigit(source[position])) {
        std::string number;
        while (position < source.size() && isdigit(source[position])) {
            number += source[position++];
        }
        return {TokenType::Number, number};
    }

    // Check for strings
    if (source[position] == '"') {
        position++; // skip the opening quote
        std::string str;
        while (position < source.size() && source[position] != '"') {
            str += source[position++];
        }
        position++; // skip the closing quote
        return {TokenType::String, str};
    }

    // Check for operators and symbols
    const std::string op(1, source[position++]);
    if (operators.contains(op)) {
        return {TokenType::Operator, op};
    }
    if (symbols.contains(op)) {
        return {TokenType::Symbol, op};
    }

    // If we reach here, we have an error
    return {TokenType::Error, std::string(1, source[position - 1])};
}