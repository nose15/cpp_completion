#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

// Alfabet służący do wyrażania cyfr w systemach liczbowych większych niz 10
const std::string alfabet{"abcdefghijklmnopqrstuvwxyz"};

// funkcja przekształcająca char z reprezentacji liczby na int w systemie 10
int charToNum(char c)
{
    if (isdigit(c))
    {
        int converted = c - '0';
        return converted;
    }

    // jeśli char nie jest cyfrą, to przystępujemy do jego konwersji z litery alfabetu na liczbę dziesiętną
    int i;
    for (i = 0; i < alfabet.size() - 1; i++)
    {
        if (std::tolower(c) == alfabet[i]) return (i + 10);
    }

    return -1;
}

// funkcja przekształcająca int na char
char numToStr(int num)
{
    // jeśli liczba może być wyrażona przez 1 cyfrę w systemie 10 to po prostu w ten sposob ją wyrażamy
    if (num < 10)
    {
        return (num + '0');
    }

    // jeśli nie da się wyrazić tej liczby jedną cyfrą w sys. dziesiętnym to używamy do tego liter alfabetu
    int index = num - 10;

    return toupper(alfabet[index]);
}

// funkcja przekształcająca z danego systemu liczbowego na system dziesiętny
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

// funkcja odwracająca string, użyteczna do zwracania zapisu liczby w przeliczonym systemie liczbowym
std::string reversedString(std::string str)
{
    std::string result;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        result += str[i];
    }

    return result;
}

// funkcja przekształcająca wszystkie litery w stringu na małe, użyteczna w czytaniu poleceń użytkownika
std::string toLower(std::string str)
{
    std::string result;

    for (char &c : str)
    {
        result += std::tolower(c);
    }

    return result;
}


// funkcja przekształcająca liczbę dziesiętną na dany system liczbowy
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

// funkcja łącząca pozostałe funkcje, jej rolą jest zmiana z systemu początkowego na dziesiętny, a później z dziesiętnego na docelowy
std::string baseConversion(std::string num, int sourceBase, int targetBase)
{
    int dec = baseToDec(sourceBase, num);
    return decToBase(targetBase, dec);
}

// funkcja czyszcząca strumień wejścia, użyteczna przy pobieraniu wejścia od użytkownika kilkukrotnie
void clearCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// funkcja pobierająca dane od użytkownika oraz
// sprawdzająca czy dane podane przez użytkownika są poprawne
bool getValidBaseInput(int& input)
{
    // sprawdzamy czy strumien wejscia jest w stanie przypisac podaną zmienną do zmiennej typu int
    // a tym samym czy użytkownik podał zmienną dobrego typu
    if (std::cin >> input)
    {
        clearCin();
        return true;
    }

    std::cout << "Niewlasciwe dane" << std::endl;
    clearCin();
    return false;
}


// funkcja pobierająca od użytkownika liczbę zapisaną w danym systemie oraz
// sprawdzająca czy jest ona poprawna dla tego systemu
bool getValidNumInput(std::string& input, int base)
{
    bool valid = false;
    if (std::cin >> input)
    {
        valid = true;
        for (char c : input)
        {
            // sprawdzamy czy podana cyfra znajduje się w dozwolonych cyfrach dla danego systemu liczbowego
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
    // Krótka demonstracja działania programu
    // Po każdej instrukcji cout następuje wywołanie funkcji, która przyjmuje od użytkownika dane i od razu
    // sprawdza czy są poprawne, jeśli nie są, to przechodzimy do nowej iteracji pozwalając użytkownikowi
    // na podanie danych jeszcze raz

    int sourceBase, targetBase;
    std::string num, prompt;

    // Pętla aby użytkownik mógł przeliczać systemy liczbowe wielokrotnie
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