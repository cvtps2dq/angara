#include <string>
#include <vector>
#include "angara.core/lexer/Lexer.h"
#include "angara.core/parser/Parser.h"

int main() {
    std::string sourceCode = R"(
        def x as int32 = 42;
        def y as float = 3.14;
        def c as char = 'a';
        def c as string = "Hello World, Angara!";
        def b as bool = true;
        def b1 as bool = false;
    )";

    Lexer lexer(sourceCode);
    Parser parser(lexer);
    const auto program = parser.parse();
    program->print();

    return 0;
}
