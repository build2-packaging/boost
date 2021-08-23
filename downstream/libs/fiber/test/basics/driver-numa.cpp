#include <boost/fiber/exceptions.hpp> // fiber_error
#include <boost/fiber/numa/topology.hpp>

#include <system_error> // errc

int
main ()
{
  // Note that on some platforms (currently Mac OS and MinGW), topology() is
  // not implemented and throws fiber_error exception with the
  // function_not_supported code. There, we make sure that if it fails, then
  // it happens exactly by this reason, in case a real (generic)
  // implementation (which may throw other kinds of exceptions) is added to
  // src/numa/topology.cpp upstream.
  //
  try
  {
    static_cast<void> (boost::fibers::numa::topology ());
  }
  catch (const boost::fibers::fiber_error& e)
  {
    if (e.code () != std::errc::function_not_supported)
      throw;
  }

  return 0;
}
