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
#include <unordered_map>

typedef void(*Convert)(char& c);

// map from option to the conversion function
// @concerns "--upper", "--lower"
// @concerns toUpper(), toLower(), optionToConversion[out]
const std::unordered_map<std::string_view, Convert> optionToConversion{
    { "--upper", [](char& c) { c = std::toupper(c); } },
    { "--lower", [](char& c) { c = std::tolower(c); } },
};

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

    // figure out, according to the option, which conversion to use
    // @concerns optionToConversion, error handling, std::cerr
    const auto converter = optionToConversion.find(option);
    if (converter == optionToConversion.end()) {
        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }
    Convert conversion = converter->second;

    // convert using the current conversion
    // @concerns std::for_each, conversion
    std::for_each(text.begin(), text.end(), conversion);

    // output converted text
    // @concerns output format, text, std::string, iteration, std::cout
    for (auto pc = text.cbegin(); pc != text.cend(); ++pc)
        std::cout << *pc;
    std::cout << '\n';

    return 0;
}
