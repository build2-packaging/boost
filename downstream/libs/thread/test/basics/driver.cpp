#include <boost/thread.hpp>

int
main ()
{
  boost::thread t ([] () {});
  t.join ();
  return 0;
}
