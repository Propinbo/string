#include "string.h"

int main() {
    String s("hello");
    String s1("World");
    std::cout << s;
    std::cout << s1;
    std::cout << s + s1;
    std::cout << (s == "hello") << "\n" << (s >= s1) << "\n";
    s += s1;
    std::cout << s;
    s += " world!";
    std::cout << ("123" + s);
    s[1] = 'd';
    std::cout << s;
    std::cout << s.left(4);
    std::cout << s.right(3);
    std::cout << s.has_symbol('u');
    std::cout << s.get_first_word(" .!");
    std::cout << s.get_last_word(" .!");
    return 0;
}
