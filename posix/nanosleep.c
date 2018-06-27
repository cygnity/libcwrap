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
#include <errno.h>

int
Nanosleep(int sec, long nsec)
{
  struct timespec wtime, rtime;
  int result;

  wtime.tv_sec = sec;
  wtime.tv_nsec = nsec;

  rtime.tv_sec = 0;
  rtime.tv_nsec = 0;

  while ((result = nanosleep(&wtime, &rtime)) == -1 && errno == EINTR) {
    wtime.tv_sec = rtime.tv_sec;
    wtime.tv_nsec = rtime.tv_nsec;

    rtime.tv_sec = 0;
    rtime.tv_nsec = 0;
  }

  return result;
}
