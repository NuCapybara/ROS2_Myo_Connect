// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from myo_interfaces:msg/MyoArm.idl
// generated code does not contain a copyright notice
#include "myo_interfaces/msg/detail/myo_arm__rosidl_typesupport_fastrtps_cpp.hpp"
#include "myo_interfaces/msg/detail/myo_arm__functions.h"
#include "myo_interfaces/msg/detail/myo_arm__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace myo_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myo_interfaces
cdr_serialize(
  const myo_interfaces::msg::MyoArm & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: arm
  cdr << ros_message.arm;
  // Member: xdir
  cdr << ros_message.xdir;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myo_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  myo_interfaces::msg::MyoArm & ros_message)
{
  // Member: arm
  cdr >> ros_message.arm;

  // Member: xdir
  cdr >> ros_message.xdir;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myo_interfaces
get_serialized_size(
  const myo_interfaces::msg::MyoArm & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: arm
  {
    size_t item_size = sizeof(ros_message.arm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xdir
  {
    size_t item_size = sizeof(ros_message.xdir);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_myo_interfaces
max_serialized_size_MyoArm(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: arm
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: xdir
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = myo_interfaces::msg::MyoArm;
    is_plain =
      (
      offsetof(DataType, xdir) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MyoArm__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const myo_interfaces::msg::MyoArm *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyoArm__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<myo_interfaces::msg::MyoArm *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyoArm__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const myo_interfaces::msg::MyoArm *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyoArm__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MyoArm(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MyoArm__callbacks = {
  "myo_interfaces::msg",
  "MyoArm",
  _MyoArm__cdr_serialize,
  _MyoArm__cdr_deserialize,
  _MyoArm__get_serialized_size,
  _MyoArm__max_serialized_size
};

static rosidl_message_type_support_t _MyoArm__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyoArm__callbacks,
  get_message_typesupport_handle_function,
  &myo_interfaces__msg__MyoArm__get_type_hash,
  &myo_interfaces__msg__MyoArm__get_type_description,
  &myo_interfaces__msg__MyoArm__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace myo_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_myo_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<myo_interfaces::msg::MyoArm>()
{
  return &myo_interfaces::msg::typesupport_fastrtps_cpp::_MyoArm__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, myo_interfaces, msg, MyoArm)() {
  return &myo_interfaces::msg::typesupport_fastrtps_cpp::_MyoArm__handle;
}

#ifdef __cplusplus
}
#endif
