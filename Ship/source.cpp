#include <iostream>
#include <vector>
#include <functional>
class Ship
{
public:
    Ship(int containerCount, std::function<int(int)> fillContainer)
    {
        this->containers.reserve(containerCount); 

        for (int i = 0; i < containerCount; i++)
        {
            this->containers.push_back(fillContainer(i)); 
        }
    }

    int peekContainer(int containerIndex)
    {
        return this->containers.at(containerIndex); //use vector instead of unordered_map
        //returns the value of the container at that position in the vector.
    }
private:
    std::vector<int> containers; //storing information about the many containers on board.
};

#ifndef RunTests

int main()
{
    //The lambda function is used to populate each container with the container index.
    Ship ship(10, [](int containerIndex) { return containerIndex; }); // 10 container
    for (int i = 0; i < 10; i++) 
    {
        std::cout << "Container: " << i << ", cargo: " << ship.peekContainer(i) << "\n";
    }

}

#endif