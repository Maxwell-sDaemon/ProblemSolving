#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <unordered_set>
// #include <unordered_set>


class Timer
{
    private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
    public:  
    Timer()
    {
        start = std::chrono::system_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    
        std::cout << "finished computation at " << std::ctime(&end_time)
                << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }

};

int main() 
{
    
    std::string m_string;
    std::cin >> m_string;
    std::string my_string = m_string;
    {
        Timer timer;
        int x = 0;

        std::sort(m_string.begin(), m_string.end(), [&x](const char & a, const char & b ) -> bool {
            if(a > b) {
                x++;
                return true;
            }
            return false;
        });

        if( x % 2 == 0 ) 
                std::cout << "CHAT WITH HER!";
        else
            std::cout << "IGNORE HIM!!";

    }

    {
        Timer timer;
        std::unordered_set<char> my_set;
        // std::string my_string ;
        // std::cin >> my_string ;
        for(auto i : my_string) 
            my_set.emplace(i);
        if(my_set.size() % 2 == 0) 
            std::cout << "CHAT WITH HER!";
        else
            std::cout << "IGNORE HIM!!";

    }   
    // std::unordered_set<char> my_set;
    // std::string my_string ;
    // std::cin >> my_string ;
    // for(auto i : my_string) 
    //     my_set.emplace(i);
    // if(my_set.size() % 2 == 0) 
    //     std::cout << "CHAT WITH HER!";
    // else
    //     std::cout << "IGNORE HIM!!";

    std::cin.get();
}