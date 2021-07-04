#include <iostream>
#define BITS sizeof(int) * 8

int setBitNumber(int n)
{
    n |= n >> 1;
    n |= n >> 2;
 
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n = n + 1;
 
   return (n >> 1);
}

int* create_test_data(int count)
{
    int *arr = new int[count];
    for (size_t i = 0; i < count; i++)
    {
        arr[i] = i+1;
    }
    
    return arr;
}

void print_max_and_zero_k(int n)
{
    std::cout<< setBitNumber(n) - 1 << std::endl;
}

int main()
{
    int sz;
    std::cin >> sz;
    // int * arr = create_test_data(sz);

    for (int i = 0; i < sz; i++)
    {
        
        // int n = arr[i];
        int n;
        std::cin >> n;
        print_max_and_zero_k(n);
    }
    
}