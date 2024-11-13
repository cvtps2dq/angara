//
// Created by cv2 on 24.10.2024.
//

#ifndef STATEMENTNODE_H
#define STATEMENTNODE_H
#include <iostream>
#include <string>

#include "ASTNode.h"

class StatementNode final : public ASTNode {
public:
    Variable* rhs;
    Variable* lhs;
    std::string op;

    void print() const override {
        std::cout << "[angara-parser]:  statement: " << "lhs - " << lhs->toString() << " operation: " << op << " rhs - " << rhs->toString()  << ";\n";
    }
};
#endif //STATEMENTNODE_H
