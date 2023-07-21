#include <iostream>
#include <string>
#include <exception>
#include <typeinfo>

class BigInt{
    public:
        std::vector<int> numbers;
        BigInt()
        {
            numbers.push_back(0);
        }
        BigInt(unsigned int value)
        {
            std::string valueStr = std::to_string(value);

            for(int i = 0; i < valueStr.size(); i++)
            {
                numbers.push_back(int(valueStr.at(i)) - 48);
            }

        }
        BigInt(std::string digitString)
        {
            for (int i = 0; i < digitString.size(); i++)
            {
                if (std::isalpha(digitString.at(i)))
                {
                    throw std::runtime_error("Error");
                }
                numbers.push_back(int(digitString.at(i)) - 48);
            }
        }

        BigInt operator+(const int rightValue)
        {
            std::string result = "";
            
            for (int i = 0; i < numbers.size(); i++)
            {
                if(i != numbers.size() - 1)
                {
                    result = result + std::to_string(numbers.at(i));
                }
                else 
                {
                    result = result + std::to_string(numbers.at(i) + 1);
                }
            }

            return BigInt(result);
        }
        
        BigInt operator+(const BigInt& rightValue)
        {
            std::string result = "";
            std::vector<int> tempVec = rightValue.numbers;
            //std::cout << std::endl <<  typeid(rightValue).name() << std::endl;

            if (tempVec.size() > numbers.size())
            {
                for (int i = 0; i < tempVec.size(); i++)
                {
                    if(i < numbers.size())
                    {
                        if (tempVec.at(tempVec.size() - 1 - i) + numbers.at(numbers.size() - 1 - i) < 10)
                        {
                            tempVec.at(tempVec.size() - 1 - i) = tempVec.at(tempVec.size() - 1 - i) + numbers.at(numbers.size() - 1 - i);
                        }
                        else {
                            tempVec.at(tempVec.size() - 1 - i) = tempVec.at(tempVec.size() - 1 - i) + numbers.at(numbers.size() - 1 - i) - 10;
                            tempVec.at(tempVec.size() - 1 - i - 1) = tempVec.at(tempVec.size() - 1 - i - 1) + 1;
                        }
                    }
                    else
                    {
                        if(tempVec.at(tempVec.size() - 1- i) >= 10)
                        {
                            
                            tempVec.at(tempVec.size() - 1- i) = tempVec.at(tempVec.size() - 1- i) - 10;
                            if (tempVec.size() - 1- i != 0)
                            {
                                tempVec.at(tempVec.size() - 1 - i - 1) = tempVec.at(tempVec.size() - 1 - i - 1) + 1;
                            }
                            else
                            {
                                result = result + "1";
                            }
                        }
                    }
                }
                for(int i = 0; i < tempVec.size(); i++)
                {
                    result = result + std::to_string(tempVec.at(i));
                }
            }
            else
            {
                for (int i = 0; i < numbers.size(); i++)
                {
                    if(i < tempVec.size())
                    {
                        if (numbers.at(numbers.size() - 1 - i) + tempVec.at(tempVec.size() - 1 - i) < 10)
                        {
                            numbers.at(numbers.size() - 1 - i) = numbers.at(numbers.size() - 1 - i) + tempVec.at(tempVec.size() - 1 - i);
                        }
                        else {
                            numbers.at(numbers.size() - 1 - i) = numbers.at(numbers.size() - 1 - i) + tempVec.at(tempVec.size() - 1 - i) - 10;
                            numbers.at(numbers.size() - 1 - i - 1) = numbers.at(numbers.size() - 1 - i - 1) + 1;
                        }
                    }
                    else
                    {
                        if(numbers.at(numbers.size() - 1- i) >= 10)
                        {
                            
                            numbers.at(numbers.size() - 1- i) = numbers.at(numbers.size() - 1- i) - 10;
                            if (numbers.size() - 1- i != 0)
                            {
                                numbers.at(numbers.size() - 1 - i - 1) = numbers.at(numbers.size() - 1 - i - 1) + 1;
                            }
                            else
                            {
                                result = result + "1";
                            }
                        }
                    }
                }
                for(int i = 0; i < numbers.size(); i++)
                {
                    result = result + std::to_string(numbers.at(i));
                }
            }
            return BigInt(result);
        }

        bool operator<(const BigInt& rightValue)
        {
            if(numbers.size() < rightValue.numbers.size())
            {
                return true;
            }
            else if(numbers.size() == rightValue.numbers.size())
            {
                for(int i = 0; i < numbers.size(); i++)
                {
                    if (numbers.at(i) < rightValue.numbers.at(i))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        std::string toString() const
        {
            std::string result = "";
            for (int i = 0; i < numbers.size(); i++)
            {
                result = result + std::to_string(numbers.at(i));
            }
            return result;
        }
        
    private:
        
};
