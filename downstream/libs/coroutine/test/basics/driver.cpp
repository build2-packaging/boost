#include <boost/coroutine/all.hpp>

using namespace std;
using namespace boost::coroutines;

int
main ()
{

  symmetric_coroutine<int>::call_type coro (
      [&] (symmetric_coroutine<int>::yield_type& yield)
      {
        for (;;)
        {
          static_cast<void> (yield.get ());
          yield ();
        }
      });

  coro (1);

  return 0;
}
