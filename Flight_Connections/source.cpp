#include <iostream>
#include <vector>
//#define RunTests 1
using namespace std;
//Function to check the connection from vertex i to vertex j in the matrix
int checkConnections(const vector<vector<bool>>& matrix, int i, int j)
{

    if(matrix[i][j])
    {
        return true;
    }
    else{
        for(int k = 0; k < matrix.size(); k++) //ne
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
    int startingPoint = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        if(checkConnections, startingPoint, i)
        {
            continue;
        }
        else{
            copy[startingPoint][i] = 1;
            copy[i][startingPoint] = 1;
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
    cout << getMinimumConnections(matrix) << endl; // should print 1
}
// #endif