// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pupper_interfaces:srv/GoPupper.idl
// generated code does not contain a copyright notice

#ifndef PUPPER_INTERFACES__SRV__DETAIL__GO_PUPPER__STRUCT_HPP_
#define PUPPER_INTERFACES__SRV__DETAIL__GO_PUPPER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pupper_interfaces__srv__GoPupper_Request __attribute__((deprecated))
#else
# define DEPRECATED__pupper_interfaces__srv__GoPupper_Request __declspec(deprecated)
#endif

namespace pupper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoPupper_Request_
{
  using Type = GoPupper_Request_<ContainerAllocator>;

  explicit GoPupper_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  explicit GoPupper_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pupper_interfaces__srv__GoPupper_Request
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pupper_interfaces__srv__GoPupper_Request
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoPupper_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoPupper_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoPupper_Request_

// alias to use template instance with default allocator
using GoPupper_Request =
  pupper_interfaces::srv::GoPupper_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pupper_interfaces


#ifndef _WIN32
# define DEPRECATED__pupper_interfaces__srv__GoPupper_Response __attribute__((deprecated))
#else
# define DEPRECATED__pupper_interfaces__srv__GoPupper_Response __declspec(deprecated)
#endif

namespace pupper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoPupper_Response_
{
  using Type = GoPupper_Response_<ContainerAllocator>;

  explicit GoPupper_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->executed = false;
    }
  }

  explicit GoPupper_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->executed = false;
    }
  }

  // field types and members
  using _executed_type =
    bool;
  _executed_type executed;

  // setters for named parameter idiom
  Type & set__executed(
    const bool & _arg)
  {
    this->executed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pupper_interfaces__srv__GoPupper_Response
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pupper_interfaces__srv__GoPupper_Response
    std::shared_ptr<pupper_interfaces::srv::GoPupper_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoPupper_Response_ & other) const
  {
    if (this->executed != other.executed) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoPupper_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoPupper_Response_

// alias to use template instance with default allocator
using GoPupper_Response =
  pupper_interfaces::srv::GoPupper_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pupper_interfaces

namespace pupper_interfaces
{

namespace srv
{

struct GoPupper
{
  using Request = pupper_interfaces::srv::GoPupper_Request;
  using Response = pupper_interfaces::srv::GoPupper_Response;
};

}  // namespace srv

}  // namespace pupper_interfaces

#endif  // PUPPER_INTERFACES__SRV__DETAIL__GO_PUPPER__STRUCT_HPP_
