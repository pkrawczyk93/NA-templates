#pragma once
#include <utility>
#include <cstddef>

template<typename T>
class container_wrapper
{
public:
 container_wrapper() = default;
 container_wrapper(T _arg) : _value(std::move(_arg)) 
 {
 }
 container_wrapper(const container_wrapper&) = default;
 container_wrapper(container_wrapper &&) = default;
 container_wrapper& operator=(const container_wrapper&) = default;
 container_wrapper& operator=(const container_wrapper&&) = default;
  
 std::size_t size() const;
 {
  return _value.size();
 }
private:
 T _value;
};

