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

#include "stdex.h"

#include <sstream>
#include <iomanip>
#include <cmath>
#include <cctype>

namespace stdex {

std::string
trim(const std::string &str)
{
  std::string::const_iterator its = str.begin();
  std::string::const_iterator ite = str.end();

  while (isspace(*its)) {
    ++its;
  }

  if (its == ite)
    return "";

  while (isspace(*(ite - 1))) {
    --ite;
  }

  return std::string(its, ite);
}

std::vector<std::string>
split(const std::string &line, const char &limit)
{
  int size = line.length() + 1;
  char *buff = new char[size];

  std::vector<std::string> fields;
  std::istringstream strm(line);

  while (!strm.eof()) {
    strm.getline(buff, size, limit);

    if (strm.fail()) {
      // to string tail
      if (strm.eof())
        break;

      // read error
      delete[] buff;
      return std::vector<std::string>();
    }

    if (buff[0] != '\0') {
      fields.push_back(buff);
    }
  }

  delete[] buff;
  return fields;
}

std::vector<std::string>
esplit(const std::string &line, const char &limit)
{
  int size = line.length() + 1;
  char *buff = new char[size];

  std::vector<std::string> fields;
  std::istringstream strm(line);

  while (!strm.eof()) {
    strm.getline(buff, size, limit);

    if (strm.fail()) {
      // to string tail
      if (strm.eof())
        break;

      // read error
      delete[] buff;
      return std::vector<std::string>();
    }

    fields.push_back(buff);
  }

  delete[] buff;
  return fields;
}

std::string
join(const std::vector<std::string> &data, const char &limit)
{
  if (data.empty())
    return "";

  std::ostringstream ostrm;
  std::vector<std::string>::const_iterator its = data.begin();
  std::vector<std::string>::const_iterator ite = data.end();

  ostrm << *its;

  while (++its != ite) {
    ostrm << limit << *its;
  }

  return ostrm.str();
}

static double
_round(double x, short y)
{
  double val = x;

  val *= pow(10.0, y);
  val = round(val);
  val /= pow(10.0, y);

  return (val);
}

static float
_roundf(float x, short y)
{
  float val = x;

  val *= powf(10.0, y);
  val = roundf(val);
  val /= powf(10.0, y);

  return (val);
}

bool
operator ==(const Float &v1, const Float &v2)
{
  return _roundf(v1.value(), v1.precision())
      == _roundf(v2.value(), v2.precision());
}

bool
operator ==(const Double &v1, const Double &v2)
{
  return _round(v1.value(), v1.precision())
      == _round(v2.value(), v2.precision());
}

bool
operator <(const Float &v1, const Float &v2)
{
  return _roundf(v1.value(), v1.precision())
      < _roundf(v2.value(), v2.precision());
}

bool
operator <(const Double &v1, const Double &v2)
{
  return _round(v1.value(), v1.precision()) < _round(v2.value(), v2.precision());
}

}

