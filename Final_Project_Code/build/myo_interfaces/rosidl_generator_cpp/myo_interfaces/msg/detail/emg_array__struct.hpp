// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#ifndef MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__STRUCT_HPP_
#define MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__myo_interfaces__msg__EmgArray __attribute__((deprecated))
#else
# define DEPRECATED__myo_interfaces__msg__EmgArray __declspec(deprecated)
#endif

namespace myo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EmgArray_
{
  using Type = EmgArray_<ContainerAllocator>;

  explicit EmgArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit EmgArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    myo_interfaces::msg::EmgArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const myo_interfaces::msg::EmgArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      myo_interfaces::msg::EmgArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      myo_interfaces::msg::EmgArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__myo_interfaces__msg__EmgArray
    std::shared_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__myo_interfaces__msg__EmgArray
    std::shared_ptr<myo_interfaces::msg::EmgArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EmgArray_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const EmgArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EmgArray_

// alias to use template instance with default allocator
using EmgArray =
  myo_interfaces::msg::EmgArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace myo_interfaces

#endif  // MYO_INTERFACES__MSG__DETAIL__EMG_ARRAY__STRUCT_HPP_
