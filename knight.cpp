#include<iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> getNextMove(std::vector<std::vector<std::string> > board, std::vector<int> startSquare, int i)
{
    std::vector<int> theMove;

    const int START_SQR_ALPHABET = startSquare.at(0);
    const int START_SQR_NUM = startSquare.at(1);
    const int BOARD_SIZE = board.size();

    if (i == 0)
    {
        if (START_SQR_ALPHABET - 1 >= 0 && START_SQR_NUM - 2 >= 0 && board.at(START_SQR_ALPHABET - 1).at(START_SQR_NUM - 2) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET - 1);
            theMove.push_back(START_SQR_NUM - 2);
        }
    }
    else if (i == 1)
    {
        if (START_SQR_ALPHABET + 2 < BOARD_SIZE && START_SQR_NUM + 1 < BOARD_SIZE && board.at(START_SQR_ALPHABET + 2).at(START_SQR_NUM + 1) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET + 2);
            theMove.push_back(START_SQR_NUM + 1);
        }
    }
    else if (i == 2)
    {
        if (START_SQR_ALPHABET - 2 >= 0 && START_SQR_NUM + 1 < BOARD_SIZE && board.at(START_SQR_ALPHABET - 2).at(START_SQR_NUM + 1) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET - 2);
            theMove.push_back(START_SQR_NUM + 1);
        }
    }
    else if (i == 3)
    {
        if (START_SQR_ALPHABET + 2 < BOARD_SIZE && START_SQR_NUM - 1 >= 0 && board.at(START_SQR_ALPHABET + 2).at(START_SQR_NUM - 1) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET + 2);
            theMove.push_back(START_SQR_NUM - 1);
        }
    }
    else if (i == 4)
    {
        if (START_SQR_ALPHABET + 1 < BOARD_SIZE && START_SQR_NUM + 2 < BOARD_SIZE&& board.at(START_SQR_ALPHABET + 1).at(START_SQR_NUM + 2) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET + 1);
            theMove.push_back(START_SQR_NUM + 2);
        }
    }
    else if (i == 5)
    {
        if (START_SQR_ALPHABET - 2 >= 0 && START_SQR_NUM - 1 >= 0 && board.at(START_SQR_ALPHABET - 2).at(START_SQR_NUM - 1) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET - 2);
            theMove.push_back(START_SQR_NUM - 1);
        }
    }
    else if (i == 6)
    {
        if (START_SQR_ALPHABET - 1 >= 0 && START_SQR_NUM + 2 < BOARD_SIZE && board.at(START_SQR_ALPHABET - 1).at(START_SQR_NUM + 2) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET - 1);
            theMove.push_back(START_SQR_NUM + 2);
        }
    }
    else if (i == 7)
    {
        if (START_SQR_ALPHABET + 1 < BOARD_SIZE && START_SQR_NUM - 2 >= 0 && board.at(START_SQR_ALPHABET + 1).at(START_SQR_NUM - 2) != "V")
        {
            theMove.push_back(START_SQR_ALPHABET + 1);
            theMove.push_back(START_SQR_NUM - 2);
        }
    }
    
    return theMove;
}

bool findKnightsTour(std::vector<std::vector<std::string> >& board, std::vector<int> startSquare, std::vector<int>& endSquare)
{
    bool success;

    if (!(startSquare.at(0) == endSquare.at(0) && startSquare.at(1) == endSquare.at(1))) 
    {
        for (int i = 0; i < 8; i++)
        {
            const std::vector<int> NEXT_MOVE = getNextMove(board, startSquare, i);

             if (NEXT_MOVE.size() == 2)
                {
                    const int NEXT_MOVE_ALPHABET = NEXT_MOVE.at(0);
                    const int NEXT_MOVE_NUM = NEXT_MOVE.at(1);

                    board.at(NEXT_MOVE_ALPHABET).at(NEXT_MOVE_NUM) = "V";

                    success = findKnightsTour(board, NEXT_MOVE, endSquare);

                    if (success == true)
                    {
                        endSquare.push_back(NEXT_MOVE_ALPHABET);
                        endSquare.push_back(NEXT_MOVE_NUM);

                        return true;
                    }

                    board.at(NEXT_MOVE_ALPHABET).at(NEXT_MOVE_NUM).clear();
                }
        }
        return false;
    }
    else
    {
        return true;
    }
}

void print(std::vector<int> endSquare, std::vector<int> startSquare)
{
    std::cout << char(startSquare.at(0) + 97) << startSquare.at(1) + 1 << " ";

    for (int i = endSquare.size() - 2; i >= 2; i--)
    {
        if (i % 2 == 0)
        {
            std::cout << char(endSquare.at(i) + 97);

            i = i + 2;
        }
        else
        {
            std::cout << endSquare.at(i) + 1 << " ";

            i = i - 2;
        }
    }
}

void processComdLine(int argc, char **argv)
{
    if (argc == 4)
    {
        std::vector<int> startSquare, endSquare;
        int tempNum1, tempNum2, tempSize;
        char tempAlphabet1, tempALphabet2;

        const int BOARD_SIZE = atoi(argv[1]);
        std::vector<std::vector<std::string> > board(BOARD_SIZE, std::vector<std::string>(BOARD_SIZE));

        std::istringstream iss2(argv[2]);
        iss2 >> tempAlphabet1 >> tempNum1;
        const int START_SQR_ALPHABET = int(tempAlphabet1) - 97;
        const int START_SQR_NUM = tempNum1 - 1;
        startSquare.push_back(START_SQR_ALPHABET);
        startSquare.push_back(START_SQR_NUM);

        std::istringstream iss3(argv[3]);
        iss3 >> tempALphabet2 >> tempNum2;
        const int END_SQR_ALPHABET = int(tempALphabet2) - 97;
        const int END_SQR_NUM = tempNum2 - 1;
        endSquare.push_back(END_SQR_ALPHABET);
        endSquare.push_back(END_SQR_NUM);

        if (BOARD_SIZE >= 1 && BOARD_SIZE <= 26 && BOARD_SIZE > START_SQR_NUM && BOARD_SIZE > END_SQR_NUM && BOARD_SIZE > START_SQR_ALPHABET && BOARD_SIZE > END_SQR_ALPHABET)
        {
            if (BOARD_SIZE >= 3)
            {
                board.at(START_SQR_ALPHABET).at(START_SQR_NUM) = "V";

                if(findKnightsTour(board, startSquare, endSquare))
                {
                    print(endSquare, startSquare);
                }
                else
                {
                    throw std::runtime_error("could not find a knight's tour");
                }
            }
            else
            {
                throw std::runtime_error("could not find a knight's tour");
            }
        }
        else
        {
            throw std::runtime_error("invalid parameter list");
        }
    }
    else
    {
        throw std::runtime_error("invalid parameter list");
    }
}

int main(int argc, char **argv) 
{
    try
    {
        processComdLine(argc, argv);
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what();
    }

    return 0;
}