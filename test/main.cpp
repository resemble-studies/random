/* License: MIT. See LICENSE in root directory. */

/**
 * @author Yvan Burrie
 * @date 2020/07/02
 */

#include <cstdio>
#include <cassert>

#include <ensemble/random.hpp>

using Ensemble::Random;

int main()
{
    auto random = Random();
    assert(random.GetSeed() == 0);

    random.Randomize();
    auto initialSeed = random.GetSeed();
    printf("Initial seed: %lu\n", initialSeed);

    const int count = 10;
    const int range = 1000;

    printf("Test random integers:\n");
    auto ar1 = new ulong[count];
    for (int i = 0; i < count; ++i)
    {
        auto value = random.GetRand(range);
        ar1[i] = value;
        printf("%d\n", value);
        assert(value <= range);
    }
    printf("Test random floats:\n");
    auto ar2 = new float[count];
    for (int i = 0; i < count; ++i)
    {
        auto value = random.GetRandF(range);
        ar2[i] = value;
        printf("%f\n", value);
        assert(value <= range);
    }

    random = Random(initialSeed);

    printf("Verify seeded integers:\n");
    for (int i = 0; i < count; ++i)
    {
        auto value = random.GetRand(range);
        printf("%d\n", value);
        assert(value == ar1[i]);
    }
    printf("Verify seeded floats:\n");
    for (int i = 0; i < count; ++i)
    {
        auto value = random.GetRandF(range);
        printf("%f\n", value);
        assert(value == ar2[i]);
    }
}
