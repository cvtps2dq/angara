//
// Created by cv2 on 29.09.2024.
//

#ifndef PARSER_H
#define PARSER_H
#include <iostream>

#include "Variable.h"
#include "../lexer/Lexer.h"
#include "AST/ASTNode.h"
#include "AST/ProgramNode.h"


class Parser {
public:
    explicit Parser(Lexer& lexer) : lexer(lexer) {
        currentToken = lexer.nextToken();
    }

    Variable *findVariableByName(const std::string &name);

    std::unique_ptr<ProgramNode> parse();

private:
    Lexer& lexer;
    Token currentToken;
    std::vector<Variable> variables;
    void consume(TokenType type);
    std::unique_ptr<ASTNode> parseStatement();

    std::unique_ptr<ASTNode> parseExpression();

    std::unique_ptr<ASTNode> parseExpressionInner();

    std::unique_ptr<ASTNode> parseStatementDecl();

    std::unique_ptr<ASTNode> parseVariableDeclaration();
};
#endif //PARSER_H
