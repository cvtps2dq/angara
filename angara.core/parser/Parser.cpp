//
// Created by cv2 on 29.09.2024.
//

#include "Parser.h"

#include "AST/StatementNode.h"
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

Variable* Parser::findVariableByName(const std::string& name) {
    const auto it = std::ranges::find_if(this->variables,
    [&name](const Variable& var) {
     return var.name == name;
    });

    if (it != this->variables.end()) {
        return &*it; // Return a pointer to the found Variable
    }
    return nullptr; // Return nullptr if not found
}

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

    if (currentToken.type == TokenType::Identifier) {
        return parseExpressionInner();
    }

    std::cerr << "Error: Unrecognized statement.\n";
    return nullptr;
}
