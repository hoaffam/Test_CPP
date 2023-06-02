#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
//Function used to find the first position of a number n in an integer vector v. 
//The function iterates through the vector 
//and returns the index of the number to look up if it is found, otherwise returns 0.
int searchNumber(const vector<int>& v, int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == n)
        {
            return i;
        }
    }
    return 0;
}
//Function returns the minimum number of cut pieces 
int minPieces(const vector<int>& original, const vector<int>& desired)
{
    int count = 0;
    for (int i = 0; i < desired.size(); i++) //iterate through the desired list of integers
    {
        count++;
        int j = searchNumber(original, desired[i]);
        while(1)
        {
            if(i+1 == desired.size())
            {
                return count;
            }
            if(original[j+1] == desired[i+1])
            {
                i++;
                j++;
            }
            else
            {
                break; //the function continues iterating through the next elements in the desired
            }
        }
    }
    return count;
    throw logic_error("Waiting to be implemented");
}
#ifndef RunTests
int main()
{
    vector<int> original = { 1, 4, 3, 2 };
    vector<int> desired = { 1, 2, 4, 3 };
    cout << minPieces(original, desired) << std::endl; //should print 3 
}
#endif