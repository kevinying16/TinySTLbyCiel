#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_TRIVIAL_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_TRIVIAL_H_

#include "is_trivially_copyable.h"
#include "is_default_constructible.h"

namespace ciel {

	template<class T>
	struct is_trivial : bool_constant<is_trivially_copyable_v<T> && is_trivially_default_constructible_v<T>> {};

	template<class T>
	inline constexpr bool is_trivial_v = is_trivial<T>::value;

}   //namespace ciel

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_TRIVIAL_H_