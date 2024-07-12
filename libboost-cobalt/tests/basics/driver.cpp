// This code is based on the upstream `channel.cpp` example.

#include <boost/cobalt/channel.hpp>
#include <boost/cobalt/main.hpp>
#include <boost/cobalt/promise.hpp>

#include <vector>

namespace cobalt = boost::cobalt;

cobalt::promise<void> producer(cobalt::channel<int> & chan)
{
  for (int i = 0; i < 4; i++)
    co_await chan.write(i);

  chan.close();
}

cobalt::main co_main(int argc, char * argv[])
{
  cobalt::channel<int> c;

  auto p = producer(c);

  std::vector<int> ints;

  while (c.is_open())
    ints.push_back (co_await c.read());

  co_await p;
  co_return 0;
}
