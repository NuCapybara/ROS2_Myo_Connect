// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__MYO_ARM__TRAITS_HPP_
#define MYO_INTERFACES__MSG__DETAIL__MYO_ARM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myo_interfaces/msg/detail/myo_arm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace myo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MyoArm & msg,
  std::ostream & out)
{
  out << "{";
  // member: arm
  {
    out << "arm: ";
    rosidl_generator_traits::value_to_yaml(msg.arm, out);
    out << ", ";
  }

  // member: xdir
  {
    out << "xdir: ";
    rosidl_generator_traits::value_to_yaml(msg.xdir, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyoArm & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arm: ";
    rosidl_generator_traits::value_to_yaml(msg.arm, out);
    out << "\n";
  }

  // member: xdir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xdir: ";
    rosidl_generator_traits::value_to_yaml(msg.xdir, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyoArm & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace myo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use myo_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const myo_interfaces::msg::MyoArm & msg,
  std::ostream & out, size_t indentation = 0)
{
  myo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const myo_interfaces::msg::MyoArm & msg)
{
  return myo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<myo_interfaces::msg::MyoArm>()
{
  return "myo_interfaces::msg::MyoArm";
}

template<>
inline const char * name<myo_interfaces::msg::MyoArm>()
{
  return "myo_interfaces/msg/MyoArm";
}

template<>
struct has_fixed_size<myo_interfaces::msg::MyoArm>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<myo_interfaces::msg::MyoArm>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<myo_interfaces::msg::MyoArm>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MYO_INTERFACES__MSG__DETAIL__MYO_ARM__TRAITS_HPP_
