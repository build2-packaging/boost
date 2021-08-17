#include <string>

#include <boost/fiber/all.hpp>

using namespace std;

inline void
fn (string const& str, int n)
{
  for (int i (0); i != n; ++i)
    boost::this_fiber::yield ();
}

int
main ()
{
  try
  {
    boost::fibers::fiber f1 (fn, "abc", 5);
    f1.join ();
    return 0;
  }
  catch (...)
  {
    return 1;
  }
}
