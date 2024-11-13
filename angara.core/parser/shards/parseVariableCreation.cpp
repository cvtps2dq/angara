//
// Created by cv2 on 06.11.2024.
//
#include "../Parser.h"
#include "../AST/VariableDeclarationNode.h"

std::unique_ptr<ASTNode> Parser::parseVariableDeclaration() {
    consume(TokenType::Keyword); // consume "def"

    const std::string name = currentToken.value;
    consume(TokenType::Identifier);

    consume(TokenType::Keyword); // Expect "as"
    const std::string dataType = currentToken.value; // Get the data type
    consume(TokenType::Keyword); // Consume the data type

    consume(TokenType::Operator); // consume '='
    const std::string value = currentToken.value;
    if (dataType == "char") {
        consume(TokenType::Char); // Consume the char literal
    } else if (dataType == "string") {
        consume(TokenType::String);
    } else if (dataType == "bool") {
        consume(TokenType::Bool);
    }
    else {
        consume(TokenType::Number); // Consume the number
    }
    consume(TokenType::Symbol); // consume ';'

    auto varDeclNode = std::make_unique<VariableDeclarationNode>();
    varDeclNode->name = name; // Set variable name
    varDeclNode->dataType = dataType; // Set data type
    varDeclNode->value = value; // Set value
    Variable variable;
    variable.name = name;
    variable.value = value;
    variable.type = dataType;
    this->variables.push_back(variable);
    return varDeclNode;
}