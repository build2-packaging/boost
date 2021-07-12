#include <boost/math/tr1.hpp>

int
main ()
{
  namespace tr1 = boost::math::tr1;

  // Use the C99 libraries.
  //
  static_cast<void> (tr1::roundf (0.51f));
  static_cast<void> (tr1::round (0.5));

  // Boost.Math does not support long double on FreeBSD so only use the long
  // double library on other systems.
  //
#ifndef __FreeBSD__
  static_cast<void> (tr1::roundl (0.5l));
#endif

  return 0;
}
