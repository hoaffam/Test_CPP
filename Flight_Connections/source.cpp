#include <iostream>
#include <vector>
//#define RunTests 1
using namespace std;
//Function to check the connection from vertex i to vertex j in the matrix
//When using references (&), a function parameter can be passed to a function by passing a reference to the original object 
//without creating a new copy. 
//This can help save time and resources by avoiding unnecessary copying of the object.
int checkConnections(const vector<vector<bool>>& matrix, int i, int j)
{

    if(matrix[i][j])
    {
        return true;
    }
    else{
        for(int k = 0; k < matrix.size(); k++) 
        {
            if(matrix[i][k])
            {
                if(checkConnections(matrix,j,k))
                {
                    return true;
                }
            }
        }
    }
    return false;
} 
//Function to calculate the minimum number of connections needed 
//to form a connected graph from the input matrix
int getMinimumConnections(const vector<vector<bool>>& matrix)
{
    // throw std::logic_error("Waiting to be implemented");
    int count = 0; //number of new created connections if exist 0 connection
    vector<vector<bool>> copy = matrix;
    int start_Point = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        if(checkConnections, start_Point, i)
        {
            continue;
        }
        else{
            copy[start_Point][i] = 1;
            copy[i][start_Point] = 1;
            count++;
        }
    }
    return count;
}
// #ifndef RunTests
int main()
{
    vector<vector<bool>> matrix 
    {
        {false, true, false, false, true},
        {true, false, false, false, false},
        {false, false, false, true, false},
        {false, false, true, false, false},
        {true, false, false, false, false}
    };
    cout << getMinimumConnections(matrix) << endl; //1
}
// #endif