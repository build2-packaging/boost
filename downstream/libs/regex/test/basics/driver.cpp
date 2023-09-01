#include <boost/regex.hpp>

#ifdef LIBBOOST_REGEX_TESTS_ICU_ENABLED
#  include <boost/regex/icu.hpp>
#endif

int
main ()
{
#ifdef LIBBOOST_REGEX_TESTS_ICU_ENABLED
  // boost::icu_regex_traits::tolower() makes inline calls to u_tolower() in
  // libicuuc, one of libboost-regex's interface dependencies, so call it here
  // to ensure ICU is being exported properly.
  //
  boost::icu_regex_traits::char_type c ('a');
  return boost::icu_regex_traits ().tolower (c) == c ? 0 : 1;
#else
  return 0;
#endif
}
