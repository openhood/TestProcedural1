#pragma once

#include <vector>

// Explanations:
// http://flafla2.github.io/2014/08/09/perlinnoise.html
// Implementation:
// https://github.com/sol-prog/Perlin_Noise/blob/master/PerlinNoise.cpp
// Original implementation copyright 2002 Ken Perlin:
// http://mrl.nyu.edu/~perlin/noise/

class PerlinNoise {
  // The permutation vector
  std::vector<int> p;
public:
  // Initialize with the reference values for the permutation vector
  PerlinNoise();
  // Generate a new permutation vector based on the value of seed
  PerlinNoise(unsigned int seed);
  // Get a combined noise value with multiple levels of irregularities
  // http://flafla2.github.io/2014/08/09/perlinnoise.html
  double octave_noise(double x, double y, double z, int octaves, double persistence)
  // Get a noise value, for 2D images z can have any value
  double noise(double x, double y, double z);
private:
  double fade(double t);
  double lerp(double t, double a, double b);
  double grad(int hash, double x, double y, double z);
};
