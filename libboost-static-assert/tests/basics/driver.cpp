// Boost 1.91.0 merged StaticAssert into Config, so boost/static_assert.hpp now
// lives in Config. Check that dependents of this library can still include it
// (via the transitive libboost-config dependency).
//
#include <boost/static_assert.hpp>

int
main ()
{
  return 0;
}
