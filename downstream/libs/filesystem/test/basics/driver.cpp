#include <boost/filesystem.hpp>

int
main ()
{
  // boost::filesystem::path("/") is not absolute on Windows but it is a valid
  // path.
  //
  return boost::filesystem::path ("/") ==
         boost::filesystem::path ("/foo/..").lexically_normal ()
             ? 0
             : 1;
}
