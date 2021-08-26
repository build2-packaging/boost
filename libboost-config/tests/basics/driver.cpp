#include <boost/config.hpp>

// Some of the Boost.Config macros fail to detect certain C++11 features under
// libstdc++ on Mac OS (our gcc/homebrew Mac OS configs) so flush out any
// other platforms for which detection is broken.
//
#ifdef BOOST_NO_CXX11_HDR_MUTEX
#error "BOOST_NO_CXX11_HDR_MUTEX is defined"
#endif

int
main ()
{
  return 0;
}
