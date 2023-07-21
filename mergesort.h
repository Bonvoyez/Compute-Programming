#include <iostream>
#include <vector>

template <typename T> void merge(std::vector<T>& data, unsigned int firstToSort, unsigned int middleNum, unsigned int lastToSort) 
{
    int mergedSize, mergePos, leftPos, rightPos;              
    std::vector<T> mergedNums(lastToSort - firstToSort + 1);

    mergePos = 0;
    leftPos = firstToSort;                             
    rightPos = middleNum + 1;     

    while (leftPos <= middleNum && rightPos <= lastToSort) 
    {
        if (data.at(leftPos) < data.at(rightPos)) 
        {
            mergedNums.at(mergePos) = data.at(leftPos);
            ++leftPos;
        }
        else 
        {
            mergedNums.at(mergePos) = data.at(rightPos);
            ++rightPos;
        }
        ++mergePos;
    }    

    while (leftPos <= middleNum) 
    {
        mergedNums.at(mergePos) = data.at(leftPos);
        ++leftPos;
        ++mergePos;
    }

    while (rightPos <= lastToSort) 
    {
        mergedNums.at(mergePos) = data.at(rightPos);
        ++rightPos;
        ++mergePos;
    }

    for (mergePos = 0; mergePos < mergedNums.size(); ++mergePos) 
    {
        data.at(firstToSort + mergePos) = mergedNums.at(mergePos);
    }
}

template <typename T> void mergeSort(std::vector<T>& data, unsigned int firstToSort,  unsigned int lastToSort) 
{
    int middleNum;

    if (firstToSort < lastToSort) 
    {
        middleNum = (firstToSort + lastToSort) / 2; 

        mergeSort(data, firstToSort, middleNum);
        mergeSort(data, middleNum + 1, lastToSort);

        merge(data, firstToSort, middleNum, lastToSort);
    }
}