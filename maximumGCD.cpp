#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <numeric>


typedef struct tests{
    int test_size;
    long int * tests;

} TEST;

TEST read_input() 
{
    int test_size;
    scanf("%d", &test_size);
    long  *tests = new long [test_size];

    for(size_t i = 0 ; i < test_size ; i++) {

        scanf("%ld",&tests[i]);
    }

    TEST test_data;
    test_data.tests = tests;
    test_data.test_size = test_size;

    return test_data;
}

void maximum_gcd()
{
    TEST test_data = read_input();
    // for (size_t idx = 0; idx < test_data.test_size; idx++)
    // {
    //     long int number = test_data.tests[idx];
    //     long int max_val=0;
    //     for (size_t i = 2; i < number+1; i++)
    //     {
    //         for (size_t j = 1; j < i; j++)
    //         {
    //             long int temp = std::__gcd(i,j);
    //             if ( temp > max_val) 
    //             {
    //                 max_val = temp;
    //             }

    //         }    
    //     }
    //  }
    //     std::cout << max_val << std::endl;
    for (size_t i = 0; i < test_data.test_size; i++)
    {
        long int number = test_data.tests[i];
        long int max_val=0;
        if(number % 2 == 0 )
            std::cout << number/2 << std::endl;
        else
        
            std::cout << (number-1)/2 << std::endl;
    
    }
    
    
}

int main() {
    
    maximum_gcd();
    // std::cout <<  "gcd(10,2) == "<<  std::__gcd(10000000,20) << std::endl; 

}
