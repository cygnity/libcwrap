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

#include <string.h>
#include <stdlib.h>
#include <errno.h>

int
swap(void *a, void *b, size_t size)
{
  char *ca, *cb, tmp;

  if (a == NULL || b == NULL || size == 0) {
    errno = EINVAL;
    return -1;
  }

  if (a == b) return 0;

  ca = (char *) a;
  cb = (char *) b;

  do {
    tmp = *ca;
    *ca++ = *cb;
    *cb++ = tmp;
  } while (--size > 0);

  return 0;
}
