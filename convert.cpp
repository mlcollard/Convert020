/*
    convert.cpp

    Convert text with various conversions. E.g.,
        convert --upper "abcdefg"
*/

#include <iostream>
#include <string>
#include <string_view>
#include <cctype>

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concerns
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // convert the string according to the option
    // @concerns
    // @concerns
    // @concerns
    // @concerns
    std::string text(argv[2]);
    if (std::string_view(argv[1]) == "--upper") {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::toupper(*pc);

    } else if (std::string_view(argv[1]) == "--lower") {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::tolower(*pc);

    } else {

        std::cerr << "Invalid conversion option: " << argv[1] << '\n';
        return 1;
    }

    // output converted text
    // @concerns
    for (auto pc = text.cbegin(); pc != text.cend(); ++pc)
        std::cout << *pc;
    std::cout << '\n';

    return 0;
}
