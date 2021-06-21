#include <boost/math/tr1.hpp>

int
main ()
{
  namespace tr1 = boost::math::tr1;

  // Use the TR1 libraries.
  //
  static_cast<void> (tr1::betaf (1.0f, 1.0f));
  static_cast<void> (tr1::beta (1.0, 1.0));

  // Boost.Math does not support long double on FreeBSD so only use the long
  // double library on other systems.
  //
#ifndef __FreeBSD__
  static_cast<void> (tr1::betal (1.0l, 1.0l));
#endif

  return 0;
}
