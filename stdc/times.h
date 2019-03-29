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

#ifndef TIMES_H_
#define TIMES_H_

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

time_t tdate(int year, int mon, int day);
time_t ttime(int year, int mon, int day, int hour, int min, int sec);

time_t tadd_day(time_t t, int count);
time_t tadd_hour(time_t t, int count);
time_t tadd_minute(time_t t, int count);
time_t tadd_second(time_t t, int count);

time_t tget_zone();

#ifdef __cplusplus
}
#endif

#endif /* TIMES_H_ */
