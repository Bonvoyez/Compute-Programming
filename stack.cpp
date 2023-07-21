#include <iostream>
#include <limits>
#include <vector>

class Stack {
    public:
        Stack() {

        }
        bool isEmpty() const
        {
            if (elements.size() == 0)
            {
                return true;
            }
            return false;
        }

        int top() const
        {
            if (!isEmpty())
            {
                return elements.at(elements.size() - 1);
            }
            
            throw std::runtime_error("stack is empty");
        }

        int pop()
        {
            if (!isEmpty())
            {
                int top = elements.at(elements.size() - 1);
                elements.resize(elements.size() - 1);
                return top;
            }

            throw std::runtime_error("stack is empty");
        }

        void push(int element)
        {
            elements.push_back(element);
        }

        std::string toString() const
        {
            std::string elementList = "[";

            if (!isEmpty())
            {
                for (int i = elements.size() - 1; i > 0; i--)
            {
                elementList = elementList + std::to_string(elements.at(i)) + ",";
            }

            elementList = elementList + std::to_string(elements.at(0));
            }

            elementList = elementList + "]";

            return elementList;
        }

    private:
        std::vector<int> elements;
};

int main() {
    Stack stack;
    
    while (true) {
        try {
            std::cout << "stack> ";
            
            std::string command;
            std::cin >> command;
            
            if ( (command.compare("end") == 0) || std::cin.eof() ){
                break;
            } else if (command.compare("top") == 0) {
                std::cout << stack.top() << std::endl;
            } else if (command.compare("pop") == 0) {
                std::cout << stack.pop() << std::endl;
            } else if (command == "push") {
                if ( std::cin.eof() ) break;

                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if ( failed ){
                  throw std::runtime_error("not a number");
                }

                stack.push(i);
            } else if ( command.compare("list") == 0){
                std::cout << stack.toString() << std::endl;;
            } else {
                throw std::runtime_error("invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}