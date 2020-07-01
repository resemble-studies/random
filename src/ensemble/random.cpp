/* License: MIT. See LICENSE in root directory. */

/**
 * The algorithm should be from "Efficient and portable combined random number generators" by Pierre L'Ecuyer
 * Pages: 742-751 of "Communications of the ACM", Volume 31 Issue 6, June 1988
 * DOI: 10.1145/62959.62969
 * URL: http://www.contrib.andrew.cmu.edu/~roehrig/CompFin/Week3/randclas.html
 * @date 2020/07/02
 * @authors Yvan Burrie, Marco Savelli
 */

#include <afxres.h>

#include "../../inc/ensemble/random.hpp"

namespace Ensemble
{

ulong Random::RandLocalSeed = 0;

Random::Random(ulong initialSeed)
{
    SetSeed(initialSeed);
}

ulong Random::GetSeed()
{
    return seed;
}

void Random::SetSeed(ulong newSeed)
{
    seed = newSeed;
}

void Random::Randomize()
{
    ::LARGE_INTEGER t3;
    ::QueryPerformanceCounter(&t3);
    seed ^= t3.HighPart | (::GetTickCount() << 0x10u);
}

int Random::GetRand(int maxVal)
{
    seed = (39373 * seed) - 0x7FF9FDFD * (seed / 54532);

    if (seed < 0)
    {
        seed += 0x7FF9FDFD;
    }

    RandLocalSeed = seed;
    auto uniform = double(RandLocalSeed) * RandMultiplier;

    return (ulong)uniform % (ulong)(maxVal != 0 ? maxVal : RAND_MAX);
}

float Random::GetRandF(float maxVal)
{
    seed = (0x99CD * seed) - 0x7FF9FDFD * (seed / 0xD504);

    if (seed < 0)
    {
        seed += 0x7FF9FDFD;
    }

    RandLocalSeed = seed;
    auto uniform = double(RandLocalSeed) * RandMultiplier;

    return (ulong)uniform % (ulong)(maxVal != 0 ? maxVal : RAND_MAX);
}

} // namespace Ensemble
