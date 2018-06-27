/*
 Copyright 2018 Aaron Liu <dexin@informedia.net.cn>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <time.h>
#include <stdlib.h>
#include <math.h>

static unsigned int seed = 0;

/**
 * range 0 to max (inclusive)
 * [0, max]
 */
long 
randl(long max)
{
  if (seed == 0) {
    seed = (unsigned int) time(NULL);
    srand(seed);
  }

  long diff = max + 1;
  return (
      diff < RAND_MAX ?
      (long) (rand() % diff) :
      (long) ((double) rand() / (double) RAND_MAX * (double) diff)
  );
}

/**
 * range 0 to 1 inclusive
 * [0, 1]
 */
double
randd(unsigned int precision)
{
  double max = pow(10.0, precision);
  return (double) randl((long) max) / max;
}
