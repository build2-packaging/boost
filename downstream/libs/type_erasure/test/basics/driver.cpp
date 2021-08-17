#include <boost/type_erasure/any_cast.hpp>
#include <boost/type_erasure/any.hpp>
#include <boost/type_erasure/binding.hpp>
#include <boost/type_erasure/binding_of.hpp>
#include <boost/type_erasure/builtin.hpp>
#include <boost/type_erasure/callable.hpp>
#include <boost/type_erasure/call.hpp>
#include <boost/type_erasure/check_match.hpp>
#include <boost/type_erasure/concept_interface.hpp>
#include <boost/type_erasure/concept_of.hpp>
#include <boost/type_erasure/config.hpp>
#include <boost/type_erasure/constructible.hpp>
#include <boost/type_erasure/deduced.hpp>
#include <boost/type_erasure/derived.hpp>
#include <boost/type_erasure/dynamic_any_cast.hpp>
#include <boost/type_erasure/dynamic_binding.hpp>
#include <boost/type_erasure/exception.hpp>
#include <boost/type_erasure/free.hpp>
#include <boost/type_erasure/is_empty.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/type_erasure/is_subconcept.hpp>
#include <boost/type_erasure/iterator.hpp>
#include <boost/type_erasure/member.hpp>
#include <boost/type_erasure/operators.hpp>
#include <boost/type_erasure/param.hpp>
#include <boost/type_erasure/placeholder.hpp>
#include <boost/type_erasure/placeholder_of.hpp>
#include <boost/type_erasure/rebind_any.hpp>
#include <boost/type_erasure/register_binding.hpp>
#include <boost/type_erasure/relaxed.hpp>
#include <boost/type_erasure/require_match.hpp>
#include <boost/type_erasure/same_type.hpp>
#include <boost/type_erasure/static_binding.hpp>
#include <boost/type_erasure/tuple.hpp>
#include <boost/type_erasure/typeid_of.hpp>

#include <boost/mpl/vector.hpp>

int
main ()
{
  using namespace boost::type_erasure;

  // This pulls in one of only two functions defined in a source file.
  //
  register_binding<boost::mpl::vector<copy_constructible<>, typeid_<>, relaxed>,
                   _self> ();

  return 0;
}
