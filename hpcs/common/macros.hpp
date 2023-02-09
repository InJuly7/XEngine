/***************************
@Author: Xhosa-LEE
@Contact: lixiaoxmm@163.com
@Time: 2023/01/10
@Desc: macros
***************************/
#pragma once
#include <concepts>
#include <limits>
#include <type_traits>

#include "common/log.hpp"
namespace XEngine {
#define HAS_MEMBER_TRAITS(name)                              \
  template <typename T, typename... Args>                    \
  static constexpr bool HasMember##name = requires(T && t) { \
    {t.name(std::forward<Args>()...)};                       \
  };

#define HAS_MEMBER_RET_TRAITS(name)                                            \
  template <typename T, typename Ret, typename... Args>                        \
  static constexpr bool HasRetMember##name = requires(T && t) {                \
    {t.name(std::forward<Args>()...)};                                         \
    requires std::is_same_v<Ret, decltype(T{}.name(std::forward<Args>()...))>; \
  };

#define HAS_STATIC_MEMBER_TRAITS(name)                     \
  template <typename T, typename... Args>                  \
  static constexpr bool HasStaticMember##name = requires { \
    {T::name(std::declval<Args>()...)};                    \
  };

#define HAS_OPERATOR_TRAITS(op, name)                                     \
  template <typename T1, typename T2>                                     \
  static constexpr bool HasOperator##name = requires(T1 && t, T2 && t2) { \
    {t1 op t2};                                                           \
  };

using NodeId = std::uint32_t;
inline static constexpr NodeId NodeIdNone = std::numeric_limits<NodeId>::max();

}  // namespace XEngine