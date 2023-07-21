#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
#include <fstream>

void print(std::stack<int>& s)
{
    while (s.size() != 0)
    {
        std::cout << s.top() << " ";
        s.pop();
    }
}

void sortStack(std::stack<int>& s)
{

    if (s.size() > 1)
    {
        int top = s.top();
        s.pop();
        int temp = s.top();
        if (s.top() < top)
        {
            s.pop();
            s.push(top);
            sortStack(s);
            s.push(temp);
            sortStack(s);
        }
        else
        {
            sortStack(s);
            if(s.top() < top)
            {
                s.push(top);
                sortStack(s);
            }
            else
            {
                s.push(top);
            }
        }
    }
}

void processFile(int argc, char **argv)
{
    int input;
    std::ifstream fs;
    std::stack<int> s;

    if (argc == 2)
    {
        fs.open(argv[1]);
        if(fs.is_open())
        {
            fs >> input;
            while(!fs.fail())
            {
                s.push(input);
                fs >> input;
            }

            sortStack(s);

            print(s);
            
            fs.close();
        }
        else
        {
            throw std::runtime_error("an error occurred: could not open input file stack-foo");
        }
    } 
    else
    {
        throw std::runtime_error("an error occurred: no input file name given");
    }
}

int main(int argc, char **argv) 
{
    try
    {
        processFile(argc, argv);
    }
    catch(std::runtime_error& err)
    {
        std::cerr << err.what();
    }
}