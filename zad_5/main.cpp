#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

const std::string alfabet{"abcdefghijklmnopqrstuvwxyz"};

int charToNum(char c)
{
    if (isdigit(c))
    {
        int converted = c - '0';
        return converted;
    }

    int i;
    for (i = 0; i < alfabet.size() - 1; i++)
    {
        if (std::tolower(c) == alfabet[i]) return (i + 10);
    }

    return -1;
}

char numToStr(int num)
{
    if (num < 10)
    {
        return (num + '0');
    }

    int index = num - 10;

    return toupper(alfabet[index]);
}

int baseToDec(int base, std::string num)
{
    int dec = 0;
    int n = num.size();

    for (int i = n; i > 0; i--)
    {
        int cnum = charToNum(num[n - i]);
        dec += cnum * pow(base, i - 1);
    }

    return dec;
}

std::string reversedString(std::string str)
{
    std::string result;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        result += str[i];
    }

    return result;
}

std::string toLower(std::string str)
{
    std::string result;

    for (char &c : str)
    {
        result += std::tolower(c);
    }

    return result;
}


std::string decToBase(int base, int dec_num)
{
    std::string result;

    int a = dec_num;
    int i = 0;
    int r;

    while (a > 0)
    {
        r = a % base;
        result += numToStr(r);

        a /= base;
        ++i;
    }

    return reversedString(result);
}


std::string baseConversion(std::string num, int sourceBase, int targetBase)
{
    int dec = baseToDec(sourceBase, num);
    return decToBase(targetBase, dec);
}


void clearCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


bool getValidBaseInput(int& input)
{
    if (std::cin >> input)
    {
        clearCin();
        return true;
    }

    std::cout << "Niewlasciwe dane" << std::endl;
    clearCin();
    return false;
}


bool getValidNumInput(std::string& input, int base)
{
    bool valid = false;
    if (std::cin >> input)
    {
        valid = true;
        for (char c : input)
        {
            if (charToNum(c) >= base)
            {
                valid = false;
                break;
            }
        }
    }

    clearCin();

    if (valid)
        return true;

    std::cout << "Niewlasciwe dane" << std::endl;
    return false;
}


int main()
{
    std::cout << baseConversion("123", 8, 10) << std::endl;
    int sourceBase, targetBase;
    std::string num, prompt;


    while (toLower(prompt) != "stop")
    {
        std::cout << "\nPodaj system liczbowy:";
        if (!getValidBaseInput(sourceBase)) continue;

        std::cout << "\nPodaj liczbe zapisana w tym systemie:";
        if (!getValidNumInput(num, sourceBase)) continue;

        std::cout << "\nPodaj docelowy system liczbowy:";
        if (!getValidBaseInput(targetBase)) continue;

        std::cout << num << "(" << sourceBase << ") = " << baseConversion(num, sourceBase, targetBase) << "(" << targetBase << ")" << std::endl;

        std::cout << "\nEnter -> dalej | 'stop' -> koniec programu" << std::endl;
        std::getline(std::cin, prompt);
    }

    return 0;
}