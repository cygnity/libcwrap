/*
 Copyright 2019  Aaron Liu <dexin@informedia.net.cn>
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
#include <stdio.h>
#include <string.h>

int fgetline(FILE *file, char **output)
{
  static int BUFF_SIZE = 100;
  char buffer[100];

  char *line, *t;
  int   size = BUFF_SIZE;

  if ((line = (char *)calloc(size, sizeof(char))) == NULL) {
    return -1;
  }

  do {
    if (fgets(buffer, BUFF_SIZE, file) == NULL) {
      break;
    }

    strcat(line, buffer);

    if (buffer[strlen(buffer) - 1] == '\n') {
      break;
    }

    size += BUFF_SIZE;
    if ((t = (char *)realloc(line, size)) == NULL) {
      break;
    }

    line = t;
  } while (1);

  if (strlen(line) == 0) {
    free(line);
    return -1;
  }

  *output = line;
  return 0;
}
