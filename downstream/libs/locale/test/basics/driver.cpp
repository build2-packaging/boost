#include <ctime>
#include <iostream>

#include <boost/locale.hpp>

int
main ()
{
  using namespace std;
  using namespace boost::locale;

  generator gen;

  // Create system default locale.
  //
  locale loc (gen (""));

  // Make it system global.
  //
  locale::global (loc);

  // Set as default locale for output.
  //
  cout.imbue (loc);

  return 0;
}
