// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__BUILDER_HPP_
#define MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myo_interfaces/msg/detail/emg_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myo_interfaces
{

namespace msg
{

namespace builder
{

class Init_EmgArray_data
{
public:
  Init_EmgArray_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::myo_interfaces::msg::EmgArray data(::myo_interfaces::msg::EmgArray::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myo_interfaces::msg::EmgArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::myo_interfaces::msg::EmgArray>()
{
  return myo_interfaces::msg::builder::Init_EmgArray_data();
}

}  // namespace myo_interfaces

#endif  // MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__BUILDER_HPP_
