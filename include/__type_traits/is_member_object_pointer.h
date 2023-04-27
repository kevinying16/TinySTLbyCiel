#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H_

#include "integral_constant.h"
#include "is_member_pointer.h"
#include "is_member_function_pointer.h"

namespace ciel {

	template<class T>
	struct is_member_object_pointer : bool_constant<is_member_pointer_v<T> && !is_member_function_pointer_v<T>> {};

	template<class T>
	inline constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value;
}

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H_