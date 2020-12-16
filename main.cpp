#include <iostream>
#include <cstdlib>
#include <unordered_map>

std::unordered_map<int, uint64_t> facts;

uint64_t factorial(uint64_t n);
uint64_t catalan(uint64_t n);

uint64_t factorial(uint64_t n)
{
    std::unordered_map<int, uint64_t>::iterator it = facts.find(n);
    if (it != facts.end())
    {
        // Found it
        return it->second;
    }
    else if (n == 1)
    {
        facts[n] = 1;
        return 1;
    }
    else
    {
        int index = n;
        n = n * factorial(n - 1);
        facts[index] = n;
        return n;
    }  
}

uint64_t catalan(uint64_t n)
{
    uint64_t top = factorial(2 * n);
    uint64_t bottom = (factorial(n + 1) * factorial(n));
    size_t cn = top / bottom;
    return cn;
}

int main(int argc, char* args[])
{
    int input = 2;
    if (argc > 1)
        input = std::atoi(args[1]);

    if (input == 0)
        return 1;

    // Cast input for functions to unsigned 64 bit int
    std::cout << "factorial of input: " << factorial(uint64_t(input)) << std::endl;
    std::cout << "catalan number of input: " << catalan(uint64_t(input)) << std::endl;

    return 0;
}