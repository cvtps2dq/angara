//
// Created by cv2 on 29.09.2024.
//

#ifndef PROGRAMNODE_H
#define PROGRAMNODE_H
#include <iostream>

#include "ASTNode.h"

class ProgramNode final : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;

    void print() const override {
        std::cout << "Program:\n";
        for (const auto& stmt : statements) {
            stmt->print();
        }
    }
};

#endif //PROGRAMNODE_H
