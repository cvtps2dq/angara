//
// Created by cv2 on 29.09.2024.
//

#include "Parser.h"

#include "AST/VariableDeclarationNode.h"

std::unique_ptr<ProgramNode> Parser::parse() {
    auto program = std::make_unique<ProgramNode>();

    while (currentToken.type != TokenType::EndOfFile) {
        //std::cout << parseStatement() << std::endl;
        program->statements.push_back(parseStatement());
    }

    return program;
}

void Parser::consume(const TokenType type) {
    if (currentToken.type == type) {
        //std::cout << "consumed token: " << static_cast<int>( currentToken.type) << std::endl;
        currentToken = lexer.nextToken();
    } else {
        std::cerr << "Error: Unexpected token " << currentToken.value << "\n";
        exit(EXIT_FAILURE);
    }
}

std::unique_ptr<ASTNode> Parser::parseStatement() {
    if (currentToken.type == TokenType::Keyword && currentToken.value == "def") {
        //std::cout <<"definition: " << currentToken.value << "\n";
        return parseVariableDeclaration();
    }

    std::cerr << "Error: Unrecognized statement.\n";
    return nullptr;
}

std::unique_ptr<ASTNode> Parser::parseVariableDeclaration() {
    consume(TokenType::Keyword); // consume "def"

    std::string name = currentToken.value;
    consume(TokenType::Identifier);

    consume(TokenType::Keyword); // Expect "as"
    std::string dataType = currentToken.value; // Get the data type
    consume(TokenType::Keyword); // Consume the data type

    consume(TokenType::Operator); // consume '='
    std::string value = currentToken.value;
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
    return varDeclNode;
}