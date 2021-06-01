#include <boost/container/adaptive_pool.hpp>
#include <boost/container/allocator.hpp>
#include <boost/container/allocator_traits.hpp>
#include <boost/container/container_fwd.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/devector.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/list.hpp>
#include <boost/container/map.hpp>
#include <boost/container/new_allocator.hpp>
#include <boost/container/node_allocator.hpp>
#include <boost/container/node_handle.hpp>
#include <boost/container/options.hpp>
#include <boost/container/scoped_allocator_fwd.hpp>
#include <boost/container/scoped_allocator.hpp>
#include <boost/container/set.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/small_vector.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/container/static_vector.hpp>
#include <boost/container/string.hpp>
#include <boost/container/throw_exception.hpp>
#include <boost/container/uses_allocator_fwd.hpp>
#include <boost/container/uses_allocator.hpp>
#include <boost/container/vector.hpp>

using namespace boost::container;

int
main ()
{
  // All code taken from the upstream documentation.
  //

  // A vector that can reallocate memory to implement faster insertions.
  //
  vector<int, allocator<int>> extended_alloc_vector;

  // A flat set that can reallocate memory to implement faster insertions.
  //
  flat_set<int, std::less<int>, allocator<int>> extended_alloc_flat_set;

  // A list that can manages nodes to implement faster range insertions and
  // deletions.
  //
  list<int, adaptive_pool<int>> extended_alloc_list;

  // A set that can recycle nodes to implement faster range insertions and
  // deletions.
  //
  set<int, std::less<int>, adaptive_pool<int>> extended_alloc_set;

  // Now use them as always.
  //
  extended_alloc_vector.push_back (0);
  extended_alloc_flat_set.insert (0);
  extended_alloc_list.push_back (0);
  extended_alloc_set.insert (0);

  return 0;
}
