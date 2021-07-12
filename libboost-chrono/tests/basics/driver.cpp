#include <cmath>
#include <iostream>

#include <boost/chrono.hpp>

using namespace std;

int
main ()
{
  // All code taken from the upstream documentation.
  //

  boost::chrono::system_clock::time_point start (
      boost::chrono::system_clock::now ());

  for (long i (0); i < 10000000; ++i)
    static_cast<void> (sqrt (123.456L)); // burn some time

  boost::chrono::duration<double> sec (boost::chrono::system_clock::now () -
                                       start);

  return 0;
}
