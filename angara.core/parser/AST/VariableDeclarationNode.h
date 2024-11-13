//
// Created by cv2 on 29.09.2024.
//

#ifndef VARIABLEDECLARATIONNODE_H
#define VARIABLEDECLARATIONNODE_H
#include <iostream>

#include "ASTNode.h"

class VariableDeclarationNode final : public ASTNode {
public:
    std::string name;
    std::string dataType; // Added data type
    std::string value; // In a real parser, this would be more structured.

    void print() const override {
        std::cout << "[angara-parser]:  variable declaration: " << name << " as " << dataType << " = " << value << ";\n";
    }
};

#endif //VARIABLEDECLARATIONNODE_H
