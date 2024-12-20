// This code is based on the upstream `trivial.cpp` example.

#include <boost/parser/parser.hpp>

#include <string>
#include <vector>

using namespace std;

namespace bp = boost::parser;

int
main ()
{
  string input ("1.2,999.999,0.009");

  optional<vector<double>> r (
    bp::parse (input, bp::double_ >> *(',' >> bp::double_)));

  if (!r || *r != vector<double> {1.2, 999.999, 0.009})
    return 1;

  return 0;
}
