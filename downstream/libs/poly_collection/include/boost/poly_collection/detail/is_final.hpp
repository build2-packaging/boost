/* Copyright 2016-2017 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/poly_collection for library home page.
 */

#ifndef BOOST_POLY_COLLECTION_DETAIL_IS_FINAL_HPP
#define BOOST_POLY_COLLECTION_DETAIL_IS_FINAL_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/type_traits/is_final.hpp>
#include <type_traits>

/* technique explained at
 * http://bannalia.blogspot.com/2016/09/compile-time-checking-existence-of.html 
 */

namespace boost{
namespace poly_collection{
namespace detail{
namespace is_final_fallback{

template<typename T> using is_final=boost::is_final<T>;

struct hook{};

}}}}

/* DOWNSTREAM PATCH: this used to attach the static is_final_f() member by
 * specializing std::is_void< hook>, but libc++ 19 and later mark std::is_void
 * with [[clang::no_specializations]], which makes such a specialization a hard
 * error. Carry the member on a poly_collection-owned template instead. */

namespace boost{
namespace poly_collection{
namespace detail{
namespace is_final_fallback{

template<typename> struct hook_traits;

template<>
struct hook_traits<hook>
{
  template<typename T>
  static constexpr bool is_final_f()
  {
    return is_final<T>::value;
  }
};

}}}}

namespace boost{

namespace poly_collection{

namespace detail{

template<typename T>
struct is_final:std::integral_constant<
  bool,
  is_final_fallback::hook_traits<is_final_fallback::hook>::
    template is_final_f<T>()
>{};

} /* namespace poly_collection::detail */

} /* namespace poly_collection */

} /* namespace boost */

#endif
