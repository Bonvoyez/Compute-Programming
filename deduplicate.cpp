#include <iostream>
#include <vector>

std::vector<int> findDuplicates(std::vector<int> vec) {
    int count = 0;
    std::vector<int> duplicates;

    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            if(vec.at(i) == vec.at(j)) {
                count++;
            }
        }
        if(count > 1) {
            duplicates.push_back(vec.at(i));
        }
        count = 0;
    }
    return duplicates;
}

int findIndexToErase(std::vector<int> vec, std::vector<int> duplicates) {
    for(int i = duplicates.size() - 1; i > 0; i--) {
            for(int j = vec.size() - 1; j > 0; j--) {
                if(duplicates.at(i) == vec.at(j)) {
                    return j;
                }
            }
        }
    return -1;
}

std::vector<int> erase(std::vector<int> vec, int index) {
    std::vector<int> tempVec;

    for(int i = index + 1; i < vec.size(); i++) {
        tempVec.push_back(vec.at(i));
    }

    vec.resize(index);

    for(int j = 0; j < tempVec.size(); j ++) {
        vec.push_back(tempVec.at(j));
    }

    return vec;
}

void deduplicate(std::vector<int> vec) {
    std::vector<int> duplicates = findDuplicates(vec);

       while(duplicates.size() != 0) {
        vec = erase(vec, findIndexToErase(vec, duplicates));
        duplicates = findDuplicates(vec);
       }

       for(int i = 0; i < vec.size(); i++) {
        if(i != vec.size() - 1) {
            std::cout << vec.at(i) << ", ";
        } else {
            std::cout << vec.at(i);
        }
       }
    }

int main(){
    std::vector<int> vec;
    int temp;

    std::cout << "Enter the vector elements: ";
    while(std::cin >> temp) {
        vec.push_back(temp);
    }

    std::cout << "The deduplicated vector is: [";
    deduplicate(vec);
    std::cout << "]";

    return 0;
}