#include <iostream>
#include <vector>
#include <exception>
#include <time.h>

class Cells
{
    public:
        Cells() {}

        void print()
        {
            for (int i = 0; i < columnWallNum; i++)
            {
                for (int j = 0; j< rowWallNum; j++)
                {
                    std::cout << contents.at(i).at(j);
                }
                std::cout << std::endl;
            }
        }

        void markPath(int columnPos, int rowPos)
        {
            contents.at((columnPos * 2) + 1).at((rowPos * 2) + 1) = " . ";
        }

        bool isBlocked(std::vector<int> from, std::vector<int> to)
        {
            int wallColumnPos = (from.at(0) * 2) + 1 + (to.at(0) - from.at(0));
            int wallRowPos = (from.at(1) * 2) + 1 + (to.at(1) - from.at(1));

            if (contents.at(wallColumnPos).at(wallRowPos) == " " || contents.at(wallColumnPos).at(wallRowPos) == "   ")
            {
                return false;
            }
            return true;
        }

        void removeWall(std::vector<int> from, std::vector<int> to);

        void setCells(int columnNum, int rowNum);
        
    private:
        std::vector<std::vector<std::string> > contents;
        int columnWallNum, rowWallNum;
};

void Cells::removeWall(std::vector<int> from, std::vector<int> to)
{
    int wallColumnPos = (from.at(0) * 2) + 1 + (to.at(0) - from.at(0));
    int wallRowPos = (from.at(1) * 2) + 1 + (to.at(1) - from.at(1));
            
    if (contents.at(wallColumnPos).at(wallRowPos) == "---")
    {
        contents.at(wallColumnPos).at(wallRowPos) = "   ";
    }
    else if (contents.at(wallColumnPos).at(wallRowPos) == "|")
    {
        contents.at(wallColumnPos).at(wallRowPos) = " ";
    }
}

void Cells::setCells(int columnNum, int rowNum)
{
    columnWallNum = (2 * columnNum) + 1;
    rowWallNum = (2 * rowNum) + 1;

    contents.resize(columnWallNum, std::vector<std::string>(rowWallNum));

    for (int i = 0; i < columnWallNum; i++)
    {
        for (int j = 0; j < rowWallNum; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                contents.at(i).at(j) = "+";
            }
            else if (i % 2 != 0 && j % 2 == 0)
            {
                contents.at(i).at(j) = "|";
            }
            else if (i % 2 == 0 && j % 2 != 0)
            {
                contents.at(i).at(j) = "---";
            }
            else 
            {
                contents.at(i).at(j) = "   ";
            }
        }
    }
}

class Maze 
{
    public:
        Maze(int numOfColumn, int numOfRow)
        {
            columnNum = numOfColumn;
            rowNum = numOfRow;
            visitedCells = 0;

            theMaze.resize(columnNum, std::vector<bool>(rowNum, false));
            cells.setCells(columnNum, rowNum);
        }

        void printCells()
        {
            cells.print();
        }

        bool isValidMove(std::vector<std::vector<int> > moves, int moveIndex)
        {
            if (moves.at(moveIndex).at(0) < columnNum && moves.at(moveIndex).at(0) >= 0 && moves.at(moveIndex).at(1) < rowNum && moves.at(moveIndex).at(1) >= 0)
            {
                return true;
            }
            return false;
        }

        bool findPath(std::vector<int> from, std::vector<int> &to);

        void clearVisited()
        {
            for (int i = 0; i < columnNum; i++)
            {
                for (int j = 0; j < rowNum; j++)
                {
                    theMaze.at(i).at(j) = false;
                }
            }
        }
        
        void generateMaze(std::vector<int> start)
        {
            generateMaze(start, visitedCells);
        }

    private:
        std::vector<std::vector<bool> > theMaze;
        int columnNum, rowNum, visitedCells;
        Cells cells;

        bool generateMaze(std::vector<int> from, int &visitedCells);
};

bool Maze::findPath(std::vector<int> from, std::vector<int> &to)
{
    theMaze.at(from.at(0)).at(from.at(1)) = true;

    if (from.at(0) == to.at(0) && from.at(1) == to.at(1))
    {
        cells.markPath(from.at(0), from.at(1));

        return true;
    }
    std::vector<std::vector<int> > randomMoves = {{from.at(0) + 1, from.at(1)}, {from.at(0), from.at(1) + 1}, {from.at(0) - 1, from.at(1)}, {from.at(0), from.at(1) - 1}};

    for (unsigned int i = 0; i < 4; i++)
    {
        int ran = rand() % randomMoves.size();

        if (isValidMove(randomMoves, ran) && !theMaze.at(randomMoves.at(ran).at(0)).at(randomMoves.at(ran).at(1)) && !cells.isBlocked(from, randomMoves.at(ran)))
        {
            if (findPath(randomMoves.at(ran), to) == true)
            {
                cells.markPath(from.at(0), from.at(1));

                return true;
            } 
        }   
        randomMoves.at(ran).swap(randomMoves.at(randomMoves.size() - 1));
        randomMoves.resize(randomMoves.size() - 1);
    }
    theMaze.at(from.at(0)).at(from.at(1)) = false;

    return false;
}        

bool Maze::generateMaze(std::vector<int> from, int &visitedCells)
{
    theMaze.at(from.at(0)).at(from.at(1)) = true;

    if (visitedCells == ((columnNum * rowNum) - 1))
    {
        return true;
    }
    std::vector<std::vector<int> > randomMoves = {{from.at(0) + 1, from.at(1)}, {from.at(0), from.at(1) + 1}, {from.at(0) - 1, from.at(1)}, {from.at(0), from.at(1) - 1}};

    for (unsigned int i = 0; i < 4; i++)
    {
        int ran = rand() % randomMoves.size();

        if (isValidMove(randomMoves, ran))
        {
            std::vector<int> nextMove = randomMoves.at(ran);

            if (!theMaze.at(randomMoves.at(ran).at(0)).at(randomMoves.at(ran).at(1)))
            {
                visitedCells++;
                cells.removeWall(from, nextMove);

                if (generateMaze(nextMove, visitedCells) == true)
                {
                    return true;
                }
            }
        }    
        randomMoves.at(ran).swap(randomMoves.at(randomMoves.size() - 1));
        randomMoves.resize(randomMoves.size() - 1);
    }
    return false;
}        

class Input
{
    public:
        Input(int argc, char **argv)
        {
            if (!std::stoi(argv[1]) || !std::stoi(argv[2]))
            {
                throw std::runtime_error("Error: Invalid input(s)");
            }
            columnNum = std::stoi(argv[1]);
            rowNum = std::stoi(argv[2]);

            if (argc == 4)
            {
                seedValue = std::stoi(argv[3]);
                srand(seedValue);
            }
            else
            {
                srand(time(NULL));
            }
        }

        void processInput()
        {
            std::vector<int> start = {0, 0};
            std::vector<int> end = {columnNum - 1, rowNum - 1};

            Maze maze(columnNum, rowNum);
            maze.generateMaze(start);
            maze.clearVisited();
            maze.findPath(start, end);
            maze.printCells();
        }

    private:
        int columnNum, rowNum, seedValue;
};

int main(int argc, char **argv)
{
    try 
    {
        if (argc != 3 && argc != 4)
        {
            throw std::runtime_error("Error: invalid number of inputs");
        }
        Input input(argc, argv);

        input.processInput();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}