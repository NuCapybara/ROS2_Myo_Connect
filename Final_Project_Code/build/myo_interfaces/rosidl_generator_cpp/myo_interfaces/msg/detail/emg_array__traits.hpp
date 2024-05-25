// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__TRAITS_HPP_
#define MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "myo_interfaces/msg/detail/emg_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace myo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EmgArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EmgArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EmgArray & msg, bool use_flow_style = false)
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
  const myo_interfaces::msg::EmgArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  myo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use myo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const myo_interfaces::msg::EmgArray & msg)
{
  return myo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<myo_interfaces::msg::EmgArray>()
{
  return "myo_interfaces::msg::EmgArray";
}

template<>
inline const char * name<myo_interfaces::msg::EmgArray>()
{
  return "myo_interfaces/msg/EmgArray";
}

template<>
struct has_fixed_size<myo_interfaces::msg::EmgArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<myo_interfaces::msg::EmgArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<myo_interfaces::msg::EmgArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__TRAITS_HPP_
