// These headers are deprecated.
//
// #include <boost/math/common_factor_ct.hpp>
// #include <boost/math/common_factor.hpp>
// #include <boost/math/common_factor_rt.hpp>

#include <boost/cstdfloat.hpp>
#include <boost/math/complex.hpp>
#include <boost/math/distributions.hpp>
#include <boost/math_fwd.hpp>
#include <boost/math/octonion.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/math/special_functions.hpp>

// This header is used by the other drivers.
//
// #include <boost/math/tr1.hpp>

int
main ()
{
  return boost::math::prime (0) == 2 && boost::math::prime (9) == 29 ? 0 : 1;
}
