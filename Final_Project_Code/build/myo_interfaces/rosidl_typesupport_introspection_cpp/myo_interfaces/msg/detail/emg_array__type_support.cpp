// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from myo_interfaces:msg/EmgArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "myo_interfaces/msg/detail/emg_array__functions.h"
#include "myo_interfaces/msg/detail/emg_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace myo_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void EmgArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) myo_interfaces::msg::EmgArray(_init);
}

void EmgArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<myo_interfaces::msg::EmgArray *>(message_memory);
  typed_message->~EmgArray();
}

size_t size_function__EmgArray__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__EmgArray__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__EmgArray__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__EmgArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__EmgArray__data(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__EmgArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__EmgArray__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__EmgArray__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EmgArray_message_member_array[1] = {
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(myo_interfaces::msg::EmgArray, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__EmgArray__data,  // size() function pointer
    get_const_function__EmgArray__data,  // get_const(index) function pointer
    get_function__EmgArray__data,  // get(index) function pointer
    fetch_function__EmgArray__data,  // fetch(index, &value) function pointer
    assign_function__EmgArray__data,  // assign(index, value) function pointer
    resize_function__EmgArray__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EmgArray_message_members = {
  "myo_interfaces::msg",  // message namespace
  "EmgArray",  // message name
  1,  // number of fields
  sizeof(myo_interfaces::msg::EmgArray),
  EmgArray_message_member_array,  // message members
  EmgArray_init_function,  // function to initialize message memory (memory has to be allocated)
  EmgArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EmgArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EmgArray_message_members,
  get_message_typesupport_handle_function,
  &myo_interfaces__msg__EmgArray__get_type_hash,
  &myo_interfaces__msg__EmgArray__get_type_description,
  &myo_interfaces__msg__EmgArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace myo_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<myo_interfaces::msg::EmgArray>()
{
  return &::myo_interfaces::msg::rosidl_typesupport_introspection_cpp::EmgArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, myo_interfaces, msg, EmgArray)() {
  return &::myo_interfaces::msg::rosidl_typesupport_introspection_cpp::EmgArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
