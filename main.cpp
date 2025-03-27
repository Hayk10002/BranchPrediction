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
    std::array<std::pair<std::chrono::milliseconds, int>, 21> results{};

    for (int i = 0; i < iteration_count; i++)
    {
        for (int j = 8000; j <= 10000; j += 100)
        {
            std::ranges::generate(vec, [j]{ return generateRandomNumber(j, j + 1999); });

            auto start = std::chrono::high_resolution_clock::now();
            
            for (int el : vec) if (el < 10000) results[(j - 8000) / 100].second += el;

            results[(j - 8000) / 100].first += std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
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

    int vector_size = std::stoi(argv[1]);
    int iteration_count = std::stoi(argv[2]);

    auto results = test(vector_size, iteration_count);

    for (int i = 0; i < results.size(); i++)
    {
        auto [time, sum] = results[i];
        std::cout << std::format("Probability of branch true: {:>3}%, time: {:>6}.\n", i * 5, time);
    }

    return 0;
}