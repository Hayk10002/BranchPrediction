#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <random>
#include <format>
#include <algorithm>

int generateRandomNumber(int min = 0, int max = 100) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

auto test(int number_count, int iteration_count)
{
    std::vector<int> vec(number_count);
    std::array<std::pair<std::chrono::milliseconds, std::pair<int, int>>, 40> results{};

    for (int i = 0; i < iteration_count; i++)
    {
        for (int j = 8000; j <= 10000; j += 100)
        {
            std::ranges::generate(vec, [j]{ return generateRandomNumber(j, j + 1999); });

            int ind = (j - 8000) / 100;
            
            auto start = std::chrono::high_resolution_clock::now();
            
            for (int el : vec) 
            {
                if (el < 10000) results[ind].second.first ++;
                else            results[ind].second.second++;
            }

            results[ind].first += std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
        }
    }

    for (int i = 0; i < iteration_count; i++)
    {
        for (int j = -9; j <= 9; j++)
        {
            for (int k = 0; k < vec.size(); k++)
                vec[k] = ((j >= 0) ? (k % (j + 2) != 0) : (k % (-j + 2) == (-j + 1))) ? generateRandomNumber(8000, 9999) : generateRandomNumber(10000, 12000);

              
// j  k 0 1 2 3 4 5 6 7 8 9
// 0 -> 0 1 0 1 0 1 0 1 0 1
// 1 -> 0 1 1 0 1 1 0 1 1 0        
//-1 -> 0 0 1 0 0 1 0 0 1 0     

            int ind = j + 30;

            auto start = std::chrono::high_resolution_clock::now();
            
            for (int el : vec) 
            {
                if (el < 10000) results[ind].second.first ++;
                else            results[ind].second.second++;
            }

            results[ind].first += std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
        }
    }
    
    return results;
}

int main(int argc, char* argv[]) 
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <vector_size> <iteration_count>\n";
        return 1;
    }

    std::cout << "CTEST_FULL_OUTPUT\n";

    int vector_size = std::stoi(argv[1]);
    int iteration_count = std::stoi(argv[2]);

    auto results = test(vector_size, iteration_count);

    for (int i = 0; i < 21; i++)
    {
        auto [time, sum] = results[i];
        std::cout << std::format("Probability of branch false: {:>3}%, time: {:>6}. Evaluated: false {} times, true {} times.\n", i * 5, time, sum.second, sum.first);
    }

    for (int i = 21; i < 40; i++)
    {
        auto [time, sum] = results[i];
        std::cout << std::format("Pattern:   {:>2} false    {:>2} true   , time: {:>6}. Evaluated: false {} times, true {} times.\n", std::max(31 - i, 1), std::max(i - 29, 1), time, sum.second, sum.first);
    }

    return 0;
}
   




