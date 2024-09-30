//
// Created by cv2 on 29.09.2024.
//

#include "Parser.h"
#include "AST/VariableDeclarationNode.h"

// Angara::Parser
// How it works?

// Parser takes output from Lexer (tokens)
// Parser creates program - program = [statements]
// Each statement has it's own type
// For now, only the Variable Declaration statement is implemented

// Parser pushes statements into it's list, saving it into the program.
// List is built using the parseStatement() function

// For example: if the first token is the keyword 'def' - it means that we fall into
// Variable Declaration statement parse function

// we consume tokens, in the right order.
// if the order is broken - Angara Parser throws an error, stopping the execution.

// if the order is right - Parser makes a Variable Declaration Node
// Parser sets the parts of statements, gathered when consuming tokens.
// Last step - Parser saves the correct statement, and pushes it back into a program.


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
    return varDeclNode;
}