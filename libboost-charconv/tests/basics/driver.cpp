// This code is a slightly modified example from the upstream documentation.

#include <boost/charconv.hpp>

int
main ()
{
  {
    const char* buffer ("42");
    int v (0);
    boost::charconv::from_chars_result r (
      boost::charconv::from_chars (buffer, buffer + std::strlen (buffer), v));
    assert(r.ec == std::errc());
    assert(v == 42);
  }

  {
    char buffer[64];
    int v (123456);
    boost::charconv::to_chars_result r (
      boost::charconv::to_chars (buffer, buffer + sizeof (buffer), v));
    assert (r.ec == std::errc ());
    assert(!strncmp(buffer, "123456", 6)); // Strncmp returns 0 on match
  }

  return 0;
}
