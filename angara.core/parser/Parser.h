//
// Created by cv2 on 29.09.2024.
//

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include "../lexer/Lexer.h"
#include "AST/ASTNode.h"
#include "AST/ProgramNode.h"


class Parser {
public:
    explicit Parser(Lexer& lexer) : lexer(lexer) {
        currentToken = lexer.nextToken();
    }
    std::unique_ptr<ProgramNode> parse();

private:
    Lexer& lexer;
    Token currentToken;
    void consume(TokenType type);
    std::unique_ptr<ASTNode> parseStatement();
    std::unique_ptr<ASTNode> parseVariableDeclaration();
};
#endif //PARSER_H
