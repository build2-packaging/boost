#include <cmath>

#include <boost/timer/timer.hpp>

using namespace std;

// All code taken from the upstream documentation.
//

int
main ()
{
  boost::timer::cpu_timer t;

  for (long i (0); i < 100000000; ++i)
    static_cast<void> (sqrt (123.456L)); // burn some time

  return 0;
}
