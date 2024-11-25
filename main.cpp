#include <string>
#include <vector>
#include "angara.core/lexer/Lexer.h"
#include "angara.core/parser/Parser.h"

int main() {
    const std::string sourceCode = R"(
        def x as string = "nothing";
        def y as float = 3.14;
        def c as char = 'a';
        def c1 as string = "Hello World, Angara!";
        def b as bool = true;
        def b1 as bool = false;
        x = c1;
    )";

    Lexer lexer(sourceCode);
    Parser parser(lexer);
    const auto program = parser.parse();
    program->print();

    return 0;
}
