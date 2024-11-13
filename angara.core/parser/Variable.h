//
// Created by cv2 on 06.11.2024.
//

#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include <utility>

class Variable {
public:
    std::string name;
    std::string value;
    std::string type;
    Variable(std::string name, std::string value, std::string type) : name(std::move(name)), value(std::move(value)), type(std::move(type)) {}
    Variable() {
        name = "";
        value = "";
        type = "";
    }
    [[nodiscard]] std::string toString() const {
        return
        "name: " + this->name + ", " +
            "value: " + this->value + ", " +
                "type: " + this->type;
    }
};
#endif //VARIABLE_H
