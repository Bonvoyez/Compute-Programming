#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

char getMoreFrequentLetter(char letter1, int letter1Num, char letter2, int letter2Num)
{
    if (letter1Num < letter2Num)
    {
        return letter2;
    }
    else if (letter1Num == letter2Num)
    {
        if ((int)letter1 > (int)letter2)
        {
            return letter2;
        }
    }

    return letter1;
}

int getMoreFrequentLetterNum(int letter1Num, int letter2Num)
{
    if (letter1Num <= letter2Num)
    {
        return letter2Num;
    }

    return letter1Num;
}

char getMostVowel(std::vector<char> vowels)
{
    char theVowel = 'a', temp;
    int theVowelNum = 0, tempNum;

    for (int i = 0; i < vowels.size(); i ++)
    {
        temp = vowels.at(i);
        tempNum = std::count(begin(vowels), end(vowels), vowels.at(i));

        theVowel = getMoreFrequentLetter(theVowel, theVowelNum, temp, tempNum);
        theVowelNum = getMoreFrequentLetterNum(theVowelNum, tempNum);

    }

    return theVowel;
}

char getMostConsonant(std::vector<char> consonants)
{
    char theConsonant = 'b', temp;
    int theConsonantNum = 0, tempNum;

    for (int i = 0; i < consonants.size(); i ++)
    {
        temp = consonants.at(i);
        tempNum = std::count(begin(consonants), end(consonants), consonants.at(i));

        theConsonant = getMoreFrequentLetter(theConsonant, theConsonantNum, temp, tempNum);
        theConsonantNum = getMoreFrequentLetterNum(theConsonantNum, tempNum);
    }

    return theConsonant;
}

std::vector<char> setUpVowels(std::string inputs)
{
    std::vector<char> vowels;
    char temp;
    for (int i = 0; i < inputs.size(); i++) 
    {
        temp = inputs.at(i);
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
        {
            vowels.push_back(temp);
        }
    }

    return vowels;
}

std::vector<char> setUpConsonants(std::string inputs)
{
    std::vector<char> consonants;
    char temp;
    for (int i = 0; i < inputs.size(); i++) 
    {
        temp = inputs.at(i);
        if (std::isalpha(temp) && temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u')
        {
            consonants.push_back(temp);
        }
    }

    return consonants;
}

void printResult(char theVowel, int theVowelNum, char theConsonant, int theConsonantNum)
{
    std::cout << "Most frequent vowel: " << theVowel << " (" << theVowelNum << " times)" << std::endl;
    std::cout << "Most frequent consonant: " << theConsonant << " (" << theConsonantNum << " times)" << std::endl;
    std::cout << "Most frequent letter, overall: " 
    << getMoreFrequentLetter(theVowel, theVowelNum, theConsonant, theConsonantNum) << " (" << getMoreFrequentLetterNum(theVowelNum, theConsonantNum) << " times)" << std::endl;
}

void processInput(std::istream& file) 
{
    char input, theVowel, theConsonant, theAlphabet;
    int theVowelNum, theConsonantNum, theAlphabetNum;
    std::string inputs = "";
    std::vector<char> vowels, consonants;

    while (file.get(input)) 
    {
        inputs = inputs + char(std::tolower(input));
    }

    vowels = setUpVowels(inputs);
    consonants = setUpConsonants(inputs);
    theVowel = getMostVowel(vowels);
    theConsonant = getMostConsonant(consonants);
    theVowelNum = std::count(vowels.begin(), vowels.end(), theVowel);
    theConsonantNum = std::count(consonants.begin(), consonants.end(), theConsonant);

    printResult(theVowel, theVowelNum, theConsonant, theConsonantNum);
}

void openFile(int argc, char **argv)
{
    std::filebuf fb;

    if (argc == 2 && fb.open(argv[1], std::ios::in))
    {
        std::istream file(&fb);
        processInput(file);
    }
    else if (argc != 2)
    {
        throw std::runtime_error("cannot handle parameter list");
    }
    else 
    {
        std::string warning = "cannot open input file ";
        warning = warning.append(argv[1]);
        throw std::runtime_error(warning);
    }
}

void processInput()
{
    char input, theVowel, theConsonant, theAlphabet;
    int theVowelNum, theConsonantNum, theAlphabetNum;
    std::string inputs = "";
    std::vector<char> vowels, consonants;

    while (std::cin >> input)
    {
        inputs = inputs + char(std::tolower(input));
    }

    vowels = setUpVowels(inputs);
    consonants = setUpConsonants(inputs);
    theVowel = getMostVowel(vowels);
    theConsonant = getMostConsonant(consonants);
    theVowelNum = std::count(vowels.begin(), vowels.end(), theVowel);
    theConsonantNum = std::count(consonants.begin(), consonants.end(), theConsonant);

    printResult(theVowel, theVowelNum, theConsonant, theConsonantNum);
}

int main (int argc, char **argv)
{
    if (argc == 1) 
    {
        processInput();
    }
    else
    {
        try
        {
            openFile(argc, argv);
        }
        catch(std::runtime_error& err)
        {
            std::cerr << err.what();
        }
    }

    return 0;
}