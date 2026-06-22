/* Copyright 2016-2017 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/poly_collection for library home page.
 */

#ifndef BOOST_POLY_COLLECTION_DETAIL_IS_INVOCABLE_HPP
#define BOOST_POLY_COLLECTION_DETAIL_IS_INVOCABLE_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <functional>
#include <type_traits>

/* technique explained at
 * http://bannalia.blogspot.com/2016/09/compile-time-checking-existence-of.html 
 */

namespace boost{
namespace poly_collection{
namespace detail{
namespace is_invocable_fallback{

template <typename F,typename... Args>
struct is_invocable:
  std::is_constructible<
    std::function<void(Args...)>,
    std::reference_wrapper<typename std::remove_reference<F>::type>
  >
{};

template <typename R,typename F,typename... Args>
struct is_invocable_r:
  std::is_constructible<
    std::function<R(Args...)>,
    std::reference_wrapper<typename std::remove_reference<F>::type>
  >
{};

struct hook{};

}}}}

/* DOWNSTREAM PATCH: this used to attach the static is_invocable_f() and
 * is_invocable_r_f() members by specializing std::is_void< hook>, but libc++ 19
 * and later mark std::is_void with [[clang::no_specializations]], which makes
 * such a specialization a hard error. Carry the members on a
 * poly_collection-owned template instead. */

namespace boost{
namespace poly_collection{
namespace detail{
namespace is_invocable_fallback{

template<typename> struct hook_traits;

template<>
struct hook_traits<hook>
{
  template<typename F,typename... Args>
  static constexpr bool is_invocable_f()
  {
    return is_invocable<F,Args...>::value;
  }

  template<typename R,typename F,typename... Args>
  static constexpr bool is_invocable_r_f()
  {
    return is_invocable_r<R,F,Args...>::value;
  }
};

}}}}

namespace boost{

namespace poly_collection{

namespace detail{

template<typename F,typename... Args>
struct is_invocable:std::integral_constant<
  bool,
  is_invocable_fallback::hook_traits<is_invocable_fallback::hook>::template
    is_invocable_f<F,Args...>()
>{};

template<typename R,typename F,typename... Args>
struct is_invocable_r:std::integral_constant<
  bool,
  is_invocable_fallback::hook_traits<is_invocable_fallback::hook>::template
    is_invocable_r_f<R,F,Args...>()
>{};

} /* namespace poly_collection::detail */

} /* namespace poly_collection */

} /* namespace boost */

#endif
