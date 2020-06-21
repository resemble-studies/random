
#include <cstdio>
#include "../inc/random.hpp"

using Ensemble::Random;

int main()
{
    auto r1 = new Random();
    r1->Randomize();

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", r1->GetRand(100));
    }
}
