#include <iostream>

using namespace std;

//ALI ELSHIMY

/*
Selection sort is a simple sorting algorithm where we loop on our list and then find the smalles
    element, after that we swap it to the top of the list. We repeat this process again for the remaining list.
    for(index = 0; index < length-1; index++)
    {
        1.Find the location of the smalles element in list[index]->list[index-1].
        2.Swap the smallest element with list[smalles index].
    }
The following code contains 3 main functions:
- findMinimum : This function takes the list, start_index and end_index and returns the index of the smalles element.
- swapElement : This function takes a reference to the two list elements that needs to be swaped and it swaps them.
- selectionSort : This function loops on the whole list from start till length-1 and calls findMinimum function then swapElement functions.
And one complimentary function:
- printList : A function to print the whole element in the list for observation.
*/



template <typename T>
int findMinimum(T inputList[],int startIndex, int endIndex)
{
    for(int i = startIndex+1; i < endIndex; i++)
    {   
        if(inputList[i] < inputList[startIndex])
        {
            startIndex = i;
        }
    }
    return startIndex;
}

template <typename T>
void swapElements(T &a ,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void selectionSort(T inputList[] , int size)
{
    for(int i = 0; i<size-1 ;i++ )
    {
        auto minElement = findMinimum(inputList, i, size);
        swapElements<T>(inputList[minElement], inputList[i]);
    }
}

template <typename T>
void printList(T inputList[], int size)
{
    for(int i = 0; i<size ; i++)
    {
        cout<< inputList[i] <<"\t";
    }
    cout<<endl;
}

int main(void)
{
    float arr[5] = {5.1,2.2,4.9,8.4,1.1};
    printList<float>(arr,5);
    selectionSort<float>(arr,5);
    printList<float>(arr,5);
    return 0;
}
