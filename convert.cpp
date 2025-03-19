/*
    convert.cpp

    Convert text with various conversions. E.g.,
        convert --upper "abcdefg"
*/

#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>

typedef void(*Convert)(char& c);

// convert to upper case
// @concerns std::toupper(), toUpper[out]
void toUpper(char& c) {
    c = std::toupper(c);
}

// convert to lower case
// @concerns std::tolower(), toLower[out]
void toLower(char& c) {
    c = std::tolower(c);
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concerns input format, argc, argv, error handling, std::cerr
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // chosen option
    // @concerns input format, argv, std::string_view, option[out]
    std::string_view option(argv[1]);

    // text to convert
    // @concerns input format, argv, std::string, text[out]
    std::string text(argv[2]);

    // convert the string according to the option
    // @concerns "--upper", "--lower"
    // @concerns toUpper(), toLower(), std::for_each
    // @concerns error handling, std::cerr
    if (option == "--upper") {

        std::for_each(text.begin(), text.end(), toUpper);

    } else if (option == "--lower") {

        std::for_each(text.begin(), text.end(), toLower);

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // output converted text
    // @concerns output format, text, std::string, iteration, std::cout
    for (auto pc = text.cbegin(); pc != text.cend(); ++pc)
        std::cout << *pc;
    std::cout << '\n';

    return 0;
}
