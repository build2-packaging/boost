#include <sstream>

// Note that `boost/serialization/serialization.hpp` is not a super-header and
// that these includes are a proper use of the library.
//
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

int
main ()
{
  // Write to and then read from a string-backed text archive.
  //
  string s;

  {
    ostringstream os;
    boost::archive::text_oarchive oa (os);
    oa << 123;
    s = os.str();
  }

  {
    istringstream is (s);
    boost::archive::text_iarchive ia (is);
    int i;
    ia >> i;
  }

  return 0;
}
