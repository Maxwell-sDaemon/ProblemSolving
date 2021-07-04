#include <iostream>
#include <string.h>

#define SZ 16

int main()
{
    char l_number[SZ];
    
    int input_size;

    std::cin >> input_size;

    for(int i = 0 ; i < input_size ; i++) 
    {
        std::cin >> l_number;
        long long sz = strlen(l_number);
        long long count = 9 * (sz-1);
        char f_digit = l_number[0];
        
        int flag = 1;
        
        for(int j = 0 ; j < sz ; j++)
        {
            if( l_number[j] < f_digit  )
            {
                flag = 0;
                break;
            }
        }

        if(flag) 
        {
            std::cout << count + (f_digit - '0') << std::endl;
        } else {
            std::cout << count  << std::endl;

        }
        count = 0;
    }

 

}