#pragma once
#include <utility>
#include <cstddef>

#include <boost/optional.hpp>

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
 container_wrapper& operator=(container_wrapper&&) = default;
  
 std::size_t size() const
 {
  return _value.size();
 }
private:
 T _value;
};
////////////////////////////

template<typename T>
class container_wrapper<boost::optional<T> >
{
public:
 container_wrapper() = default;
 container_wrapper(boost::optional<T> _arg) : _value(std::move(_arg)) 
 {
 }
 container_wrapper(const container_wrapper&) = default;
 container_wrapper(container_wrapper &&) = default;
 container_wrapper& operator=(const container_wrapper&) = default;
 container_wrapper& operator=(container_wrapper&&) = default;
  
 std::size_t size() const
 {
  return _value ? 1 : 0;
 }
private:
  boost::optional<T> _value;
};
