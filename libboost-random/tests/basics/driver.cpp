#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

int
main ()
{
  boost::random::random_device dev;
  boost::random::uniform_int_distribution dist (10, 20);

  for (int i (0); i != 100; ++i)
  {
    if (dist (dev) < 10 || dist (dev) > 20)
      return 1;
  }

  return 0;
}
