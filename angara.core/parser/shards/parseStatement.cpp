//
// Created by cv2 on 06.11.2024.
//

#include <iostream>
#include "../AST/ASTNode.h"
#include "../Parser.h"
#include "../AST/StatementNode.h"

std::unique_ptr<ASTNode> Parser::parseExpressionInner() {
    auto* var = new Variable{"", "", ""};
    Variable* lhs = findVariableByName(currentToken.value);
    if (lhs == nullptr) {
        std::cerr << "Unexpected token: " + currentToken.value + "\n";
        exit(EXIT_FAILURE);
    }
    consume(TokenType::Identifier);

    const std::string op = currentToken.value;
    consume(TokenType::Operator);

    Variable* rhs = findVariableByName(currentToken.value);
    std::cout << lhs->name << std::endl;
    if (rhs == nullptr) {
        if (lhs->type == "int32") {
            var = new Variable{"newNumberLiteral", currentToken.value, "int32"};
            consume(TokenType::Number);
        }
        else if(lhs->type == "float32") {
            var = new Variable{"newNumberLiteral", currentToken.value, "float32"};
            consume(TokenType::Number);
        } else if (lhs->type == "string") {
            var = new Variable{"newStringLiteral", currentToken.value, "string"};
            consume(TokenType::Char);
        } else if (lhs->type == "bool") {
            var = new Variable{"newBoolean", currentToken.value, "bool"};
            consume(TokenType::Bool);
        } else {
            if (rhs->type == lhs->type) {
                consume(TokenType::DataType);
            } else {
                std::cerr << "Error: Can't use operator " << op << " on data types of " << rhs->type << " and " << lhs->type << "\n";
                exit(EXIT_FAILURE);
            }
        }
    }

    consume(TokenType::Symbol); // consume ';'

    // Create a StatementNode and upcast to ASTNode
    auto expr = std::make_unique<StatementNode>();
    if(rhs == nullptr) {
        expr->rhs = var; // Set rhs to a placeholder variable
    } else {
        expr->rhs = rhs;
    }
    expr->lhs = lhs;
    expr->op = op;

    // Upcast StatementNode to ASTNode by returning as unique_ptr<ASTNode>
    return expr;
}
