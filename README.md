# Ensemble Random

Uniform distributed random number generator.

## Usage

```c++
using Ensemble::Random;
```

```c++
auto r = new Random();
r->Randomize();
printf("%d", r->GetRand(100));
```
