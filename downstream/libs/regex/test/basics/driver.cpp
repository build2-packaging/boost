#include <boost/regex.hpp>
#include <boost/regex/icu.hpp>

int
main ()
{
  // boost::icu_regex_traits::tolower() makes inline calls to u_tolower() in
  // libicuuc, one of libboost-regex's interface dependencies, so call it here
  // to ensure ICU is being exported properly.
  //
  boost::icu_regex_traits::char_type c ('a');
  return boost::icu_regex_traits ().tolower (c) == c ? 0 : 1;
}
