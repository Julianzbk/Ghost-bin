#include <iostream>

extern bool FIXED_WIDTH_ENCODING;

std::string num_to_bin(int num);

bool is_symbol(char c);

std::string encode(std::istream& input);
