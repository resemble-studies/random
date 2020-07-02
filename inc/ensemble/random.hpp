/* License: MIT. See LICENSE in root directory. */

/**
 * @date 2020/07/02
 */

#pragma once

namespace Ensemble
{

class Random
{
protected:

    static constexpr ulong M = 0x7FFFFFFF;

    static ulong RandLocalSeed;

    static constexpr float RandMultiplier = 4.656612e-10;

    ulong seed = 0;

public:

    explicit
    Random(ulong initialSeed = 0);

public:

    ulong GetSeed();

    void SetSeed(ulong newSeed);

    void Randomize();

    int GetRand(int maxVal = 0);

    float GetRandF(float maxVal = 0);
};

} // namespace Ensemble
