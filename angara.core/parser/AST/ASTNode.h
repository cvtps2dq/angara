//
// Created by cv2 on 29.09.2024.
//

#ifndef ASTNODE_H
#define ASTNODE_H

class ASTNode {
public:
    virtual ~ASTNode() = default;

    virtual void print() const = 0; // For printing the AST
};

#endif //ASTNODE_H
