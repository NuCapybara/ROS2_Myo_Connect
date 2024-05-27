// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__MYO_ARM__STRUCT_HPP_
#define MYO_INTERFACES__MSG__DETAIL__MYO_ARM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__myo_interfaces__msg__MyoArm __attribute__((deprecated))
#else
# define DEPRECATED__myo_interfaces__msg__MyoArm __declspec(deprecated)
#endif

namespace myo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyoArm_
{
  using Type = MyoArm_<ContainerAllocator>;

  explicit MyoArm_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arm = 0;
      this->xdir = 0;
    }
  }

  explicit MyoArm_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arm = 0;
      this->xdir = 0;
    }
  }

  // field types and members
  using _arm_type =
    uint8_t;
  _arm_type arm;
  using _xdir_type =
    uint8_t;
  _xdir_type xdir;

  // setters for named parameter idiom
  Type & set__arm(
    const uint8_t & _arg)
  {
    this->arm = _arg;
    return *this;
  }
  Type & set__xdir(
    const uint8_t & _arg)
  {
    this->xdir = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myo_interfaces::msg::MyoArm_<ContainerAllocator> *;
  using ConstRawPtr =
    const myo_interfaces::msg::MyoArm_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myo_interfaces::msg::MyoArm_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myo_interfaces::msg::MyoArm_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myo_interfaces__msg__MyoArm
    std::shared_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myo_interfaces__msg__MyoArm
    std::shared_ptr<myo_interfaces::msg::MyoArm_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyoArm_ & other) const
  {
    if (this->arm != other.arm) {
      return false;
    }
    if (this->xdir != other.xdir) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyoArm_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyoArm_

// alias to use template instance with default allocator
using MyoArm =
  myo_interfaces::msg::MyoArm_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace myo_interfaces

#endif  // MYO_INTERFACES__MSG__DETAIL__MYO_ARM__STRUCT_HPP_
