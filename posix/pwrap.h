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

#ifndef PWRAP_H_
#define PWRAP_H_

#ifdef __cplusplus
extern "C" {
#endif

int Execv (const char *path, char * const argv[], int *result);
int Execvp(const char *file, char * const argv[], int *result);

int Nanosleep(int sec, long nsec);

#ifdef __cplusplus
}
#endif

#endif /* PWRAP_H_ */
