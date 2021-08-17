#include <boost/context/fiber.hpp>

using namespace std;
namespace ctx = boost::context;

int
main ()
{
  int a (-1);

  ctx::fiber source {[&a] (ctx::fiber&& sink)
                     {
                       a = 0;
                       int b (1);
                       for (;;)
                       {
                         sink = move (sink).resume ();
                         int next (a + b);
                         a = b;
                         b = next;
                       }
                       return move (sink);
                     }};

  for (int j (0); j != 10; ++j)
    source = move (source).resume ();

  return a > 0 ? 0 : 1;
}
