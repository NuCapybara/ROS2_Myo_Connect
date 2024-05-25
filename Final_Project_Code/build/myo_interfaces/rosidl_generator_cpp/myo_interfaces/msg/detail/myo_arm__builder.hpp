// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__MYO_ARM__BUILDER_HPP_
#define MYO_INTERFACES__MSG__DETAIL__MYO_ARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "myo_interfaces/msg/detail/myo_arm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace myo_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyoArm_xdir
{
public:
  explicit Init_MyoArm_xdir(::myo_interfaces::msg::MyoArm & msg)
  : msg_(msg)
  {}
  ::myo_interfaces::msg::MyoArm xdir(::myo_interfaces::msg::MyoArm::_xdir_type arg)
  {
    msg_.xdir = std::move(arg);
    return std::move(msg_);
  }

private:
  ::myo_interfaces::msg::MyoArm msg_;
};

class Init_MyoArm_arm
{
public:
  Init_MyoArm_arm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyoArm_xdir arm(::myo_interfaces::msg::MyoArm::_arm_type arg)
  {
    msg_.arm = std::move(arg);
    return Init_MyoArm_xdir(msg_);
  }

private:
  ::myo_interfaces::msg::MyoArm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::myo_interfaces::msg::MyoArm>()
{
  return myo_interfaces::msg::builder::Init_MyoArm_arm();
}

}  // namespace myo_interfaces

#endif  // MYO_INTERFACES__MSG__DETAIL__MYO_ARM__BUILDER_HPP_
