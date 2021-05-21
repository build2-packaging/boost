#include <boost/stacktrace.hpp>

int
main ()
{
  // Let's make sure that some basic functionality links properly and doesn't
  // crash.
  //
  boost::stacktrace::stacktrace();
  return 0;
}
