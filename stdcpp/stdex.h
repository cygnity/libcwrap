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

#ifndef STDEX_H_
#define STDEX_H_

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

#include <utility>
using namespace std::rel_ops;

namespace stdex {

class Float {
public:
  inline Float(float tv, int tp) : v(tv), p(tp) {}
  inline float   value() const {return v;}
  inline int precision() const {return p;}
  operator float() const;
private:
  float v;
  int p;
};

class Double {
public:
  inline Double(double tv, int tp) : v(tv), p(tp) {}
  inline double  value() const {return v;}
  inline int precision() const {return p;}
  operator double() const;
private:
  double v;
  int p;
};

template<class charT, class traits>
inline std::basic_ostream<charT, traits> &
operator <<(std::basic_ostream<charT, traits> &strm, const Float &out) {
  std::basic_ostringstream<charT, traits> s;
  s.copyfmt(strm);
  s.width(0);

  s << std::fixed << std::setprecision(out.precision()) << out.value();
  strm << s.str();

  return strm;
}

template<class charT, class traits>
inline std::basic_ostream<charT, traits> &
operator <<(std::basic_ostream<charT, traits> &strm, const Double &out) {
  std::basic_ostringstream<charT, traits> s;
  s.copyfmt(strm);
  s.width(0);

  s << std::fixed << std::setprecision(out.precision()) << out.value();
  strm << s.str();

  return strm;
}

inline bool
operator == (const Float &v1, const Float &v2) {
  return (float)v1 == (float)v2;
}
inline bool
operator == (const Double &v1, const Double &v2) {
  return (double)v1 == (double)v2;
}
inline bool
operator < (const Float &v1, const Float &v2) {
  return (float)v1 < (float)v2;
}
inline bool
operator < (const Double &v1, const Double &v2) {
  return (double)v1 < (double)v2;
}

std::string trim(const std::string &str);
std::vector<std::string> split(const std::string &line, const char &limit);
std::vector<std::string> esplit(const std::string &line, const char &limit);
std::string join(const std::vector<std::string> &data, const char &limit);

}/* namespace stdex */

#endif  /* STDEX_H_ */
