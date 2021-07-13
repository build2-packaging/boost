#include <sstream>

#include <boost/log/utility/setup.hpp>

using namespace std;
using namespace boost::log;

int
main ()
{
  istringstream is;
  init_from_stream (is);

  return 0;
}
