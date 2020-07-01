
#include <cstdio>

#include <ensemble/random.hpp>
using Ensemble::Random;

int main()
{
    auto random = Random();
    random.Randomize();

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", random.GetRand(100));
    }
}
