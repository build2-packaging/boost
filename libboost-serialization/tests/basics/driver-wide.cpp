#include <sstream>

// Note that `boost/serialization/serialization.hpp` is not a super-header and
// that these includes are a proper use of the library.
//
#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/text_wiarchive.hpp>

using namespace std;

int
main ()
{
  // Write to and then read from a string-backed text archive.
  //
  wstring ws;

  {
    wostringstream os;
    boost::archive::text_woarchive oa (os);
    oa << 123;
    ws = os.str();
  }

  {
    wistringstream is (ws);
    boost::archive::text_wiarchive ia (is);
    int i;
    ia >> i;
  }

  return 0;
}
