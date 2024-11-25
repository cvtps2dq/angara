//
// Created by cv2 on 29.09.2024.
//

#include "Lexer.h"

#include "lexer.shards/handleCharLiteral.h"
#include "lexer.shards/handleKeywords.h"
#include "lexer.shards/handleNumberLiteral.h"
#include "lexer.shards/handleStringLiteral.h"

Token Lexer::nextToken() {
        while (position < source.size()) {
            const char currentChar = source[position];

            // Skip whitespace
            if (isspace(currentChar)) {
                position++;
                continue;
            }

            if (isalpha(currentChar)) {
                return LexerShards::handleKeywords(currentChar, source, position);
            }

            if (currentChar == '\'') {
                return LexerShards::handleCharLiteral(currentChar, source, position);
            }

            if (currentChar == '"') {
                return LexerShards::handleStringLiteral(currentChar, source, position);
            }

            if (isdigit(currentChar)) {
                return LexerShards::handleNumberLiteral(currentChar, source, position);
            }

            // Handle symbols
            if (currentChar == '=') {
                position++;
                return { TokenType::Operator, "=" };
            }

            if (currentChar == '+') {
                position++;
                return { TokenType::Operator, "+" };
            }

            if (currentChar == '-') {
                position++;
                return { TokenType::Operator, "-" };
            }

            if (currentChar == '/') {
                position++;
                return { TokenType::Operator, "/" };
            }

            // Handle other symbols like ';'
            if (currentChar == ';') {
                position++;
                return { TokenType::Symbol, ";" };
            }

            // Handle errors
            std::cerr << "Unexpected character: " << currentChar << "\n";
            exit(EXIT_FAILURE);
        }

        return { TokenType::EndOfFile, "" };
    }
