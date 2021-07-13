#include <boost/fiber/numa/topology.hpp>

using namespace std;

int
main ()
{
  static_cast<void> (boost::fibers::numa::topology ());
  return 0;
}
