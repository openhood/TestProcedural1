// PCG-XSH-RR from https://en.wikipedia.org/wiki/Permuted_congruential_generator
// replacement for Rand(), RandRange() etc from Unreal Engine library which are
// very low quality, as stated in the documentation:
// https://api.unrealengine.com/INT/API/Runtime/Core/Math/FRandomStream/index.html

#include <stdint.h>
static uint64_t       state      = 0x4d595df4d0f33173;    // Or something seed-dependent
static uint64_t const multiplier = 6364136223846793005u;
static uint64_t const increment  = 1442695040888963407u;  // Or an arbitrary odd constant

static uint32_t rotr32(uint32_t x, unsigned r)
{
  return x >> r | x << (-r & 31);
}

uint32_t pcg32(void)
{
  uint64_t x = state;
  unsigned count = (unsigned)(x >> 59);      // 59 = 64 - 5

  state = x * multiplier + increment;
  x ^= x >> 18;                              // 18 = (64 - 27)/2
  return rotr32((uint32_t)(x >> 27), count); // 27 = 32 - 5
}

// One liner to generate a random string
// void gen_random(char *s, int l) {
//   for (int c; c=rand()%62, *s++ = (c+"07="[(c+16)/26])*(l-->0););
// }


// struct rnd_gen {
//     rnd_gen(char const* range = "abcdefghijklmnopqrstuvwxyz0123456789")
//         : range(range), len(std::strlen(range)) { }
//
//     char operator ()() const {
//         return range[static_cast<std::size_t>(std::rand() * (1.0 / (RAND_MAX + 1.0 )) * len)];
//     }
// private:
//     char const* range;
//     std::size_t len;
// };
//
// std::generate_n(s, len, rnd_gen());
// s[len] = '\0';

// To generate integer seed from string:
// uint64 CClass::FStrToUInt64(FString InputText)
// {
//   FString SeedString = FMD5::HashAnsiString(*InputText);
//   uint64_t SeedInteger = FCString::Strtoui64(*SeedString, NULL, 10);
//   return SeedInteger;
// }
void pcg32_init(uint64_t seed)
{
  state = seed + increment;
  (void)pcg32();
}
