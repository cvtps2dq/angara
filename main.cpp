#include <string>
#include <vector>
#include "angara.core/lexer/Lexer.h"

int main() {
    const std::string sourceCode = R"(
        def x as int32 = 10;
        function add(a as int32, b as int32) returns int32 {
             return a + b;
        }
    )";

    Lexer lexer(sourceCode);
    Token token;
    do {
        token = lexer.nextToken();
        token.print();
    } while (token.type != TokenType::EndOfFile);

    return 0;
}
