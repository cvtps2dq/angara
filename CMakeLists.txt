cmake_minimum_required(VERSION 3.29)
project(angara)

set(CMAKE_CXX_STANDARD 20)

add_executable(angara main.cpp
        angara.core/lexer/token.h
        angara.core/lexer/Lexer.cpp
        angara.core/lexer/Lexer.h
        angara.core/parser/AST/ASTNode.h
        angara.core/parser/Parser.cpp
        angara.core/parser/Parser.h
        angara.core/parser/AST/VariableDeclarationNode.h
        angara.core/parser/AST/ProgramNode.h
        angara.core/lexer/lexer.shards/handleKeywords.h
        angara.core/lexer/lexer.shards/handleCharLiteral.h
        angara.core/lexer/lexer.shards/handleStringLiteral.h
        angara.core/lexer/lexer.shards/handleNumberLiteral.h
)
