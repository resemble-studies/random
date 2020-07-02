/* License: MIT. See LICENSE in root directory. */

/**
 * The algorithm should be from "Efficient and portable combined random number generators" by Pierre L'Ecuyer
 * Pages: 742-751 of "Communications of the ACM", Volume 31 Issue 6, June 1988
 * DOI: 10.1145/62959.62969
 * URL: http://www.contrib.andrew.cmu.edu/~roehrig/CompFin/Week3/randclas.html
 * @date 2020/07/02
 * @authors Yvan Burrie, Marco Savelli
 */

#if WIN32
#include <afxres.h>
#else
#include <pthread_time.h>
#include <pthread.h>
#endif

#include "../../inc/ensemble/random.hpp"

namespace Ensemble
{

ulong Random::RandLocalSeed = 0;

Random::Random(ulong initialSeed)
{
    SetSeed(initialSeed);
}

ulong Random::GetSeed() const
{
    return seed;
}

void Random::SetSeed(ulong newSeed)
{
    seed = newSeed;
}

void Random::Randomize()
{
    long value;

#if WIN32
    ::LARGE_INTEGER t3;
    ::QueryPerformanceCounter(&t3);
    value = (t3.HighPart) | (::GetTickCount() << 0x10u);
#else
    ::timespec now {};
    ::clock_gettime(CLOCK_MONOTONIC, &now);
    value = (now.tv_sec) | (now.tv_nsec << 0x10u); // todo
#endif

    seed ^= value;
}

#define ENSEMBLE_RANDOM_CHANGE_SEED(s, m) \
    if ((s) = 39373 * (s) - 2147089917 * (s) / 54532, (s) < 0) (s) += (m);

int Random::GetRand(int maxVal)
{
    ENSEMBLE_RANDOM_CHANGE_SEED(seed, RandMaximum)
    RandLocalSeed = seed;

    auto uniform = (double)RandLocalSeed * RandMultiplier;
    auto result = (*((ulong*)&uniform)) % (ulong)(maxVal != 0 ? maxVal : RAND_MAX);

    return result;
}

float Random::GetRandF(float maxVal)
{
    ENSEMBLE_RANDOM_CHANGE_SEED(seed, RandMaximum)
    RandLocalSeed = seed;

    auto uniform = (double)RandLocalSeed * RandMultiplier;
    auto result = (*((ulong*)&uniform)) % (ulong)(maxVal != 0 ? maxVal : RAND_MAX);

    return result;
}

} // namespace Ensemble
