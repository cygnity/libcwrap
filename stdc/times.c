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

#include <string.h>
#include "times.h"

time_t
tdate(int year, int mon, int day) {
  struct tm time_;
  memset(&time_, 0, sizeof(struct tm));

  time_.tm_year = year - 1900;
  time_.tm_mon = mon - 1;
  time_.tm_mday = day;

  return mktime(&time_);
}

time_t
ttime(int year, int mon, int day, int hour, int min, int sec) {
  struct tm time_;
  memset(&time_, 0, sizeof(struct tm));

  time_.tm_year = year - 1900;
  time_.tm_mon = mon - 1;
  time_.tm_mday = day;

  time_.tm_hour = hour;
  time_.tm_min = min;
  time_.tm_sec = sec;

  return mktime(&time_);
}

time_t
tadd_day(time_t t, int count) {
  struct tm time_, *ltime;
  ltime = localtime(&t);
  memcpy(&time_, ltime, sizeof(struct tm));

  time_.tm_mday += count;
  return mktime(&time_);
}

time_t
tadd_hour(time_t t, int count) {
  struct tm time_, *ltime;
  ltime = localtime(&t);
  memcpy(&time_, ltime, sizeof(struct tm));

  time_.tm_hour += count;
  return mktime(&time_);
}

time_t
tadd_minute(time_t t, int count) {
  struct tm time_, *ltime;
  ltime = localtime(&t);
  memcpy(&time_, ltime, sizeof(struct tm));

  time_.tm_min += count;
  return mktime(&time_);
}

time_t
tadd_second(time_t t, int count) {
  struct tm time_, *ltime;
  ltime = localtime(&t);
  memcpy(&time_, ltime, sizeof(struct tm));

  time_.tm_sec += count;
  return mktime(&time_);
}

time_t
tget_zone()
{
  time_t current;
  time(&current);

  return (time_t) difftime(
      mktime(localtime(&current)),
      mktime(gmtime(&current))
  );
}


