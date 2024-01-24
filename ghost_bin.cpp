#include <iostream>
#include <string>

struct BinaryString
{
    char* first;
    size_t len;
};

BinaryString encode(std::istream& input)
{
    std::string word;
    while (input >> word)
    {
        for (size_t i = 0; word[i] != '\0'; ++i)
        {
            std::string bin_char = to_char(word[i]);

        }
    }
}

std::string to_bin(int num)
{
    std::string bin = "";
    int rem;
    while (num % 2 != 0)
    {
        rem = num % 2;
        bin.append(std::to_string(rem));
    }

    //reverse bin
    return bin;
}

std::string to_char(char c)
{
    int c_num;
    if (c >= 65 && c <= 90)
    {
        c_num = c - 38;
    }
    if (c >= 97 && c <= 122)
    {
        c_num = c - 96;
    }
    return to_bin(c_num)
}


int main()
{
    encode(std::cin);
    return 0;
}