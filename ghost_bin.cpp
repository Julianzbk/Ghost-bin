#include <iostream>

bool fixed_width_encoding = true; // Setting false will render message more aesthetic but undecodable.

std::string num_to_bin(int num)
{
    std::string bin = "";
    int rem;
    do
    {
        rem = num % 2;
        if (rem == 0)
            bin.append("o");
        else
            bin.append("O");
        num = num / 2;
    } while (num > 0);
    
    if (fixed_width_encoding) {
        while (bin.size() < 6)
            bin.append("o");
    }

    char holder;
    size_t size = bin.size();
    for (size_t i = 0; i < size / 2; ++i)
    {
        holder = bin[i];
        bin[i] = bin[size - i - 1];
        bin[size - i - 1] = holder;
    }
    return bin;
}

bool is_symbol(char c)
{
    return c == 10 || (c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126) && c != ' ';
}

std::string encode(std::istream& input)
{
    std::string line = "";
    char c;
    while (input.get(c))
    {
        //std::cout << "c = " << c << " peek = " << input.peek() << std::endl;
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            int c_num = c;
            if (c >= 'a' && c <= 'z')
                c_num = c - 38;
            else if (c >= 'A' && c <= 'Z')
                c_num = c - 96;

            line.append(num_to_bin(c_num));
            char p = input.peek();
            if (p == 39 && c != ' ') {}
            else if (is_symbol(p))
            {
                line.append("h");
            }
        }
        else
        {
            line.append(std::string(1, c));
        }
    }
    return line;
}


int main()
{
    /*
    for (char c = 60; c < 'z'; ++c)
    {
        std::cout << c << " " << char_to_bin(c) << std::endl;
    }
    */
    std::cout << "Enter string. End input with Ctrl-Z." << std::endl;
    std::cout << encode(std::cin);
    return 0;
}
