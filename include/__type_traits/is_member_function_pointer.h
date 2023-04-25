#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H_

#include "integral_constant.h"
#include "is_function.h"
#include "remove_cv.h"

namespace ciel {

	template<class T>
	struct is_member_function_pointer_helper : false_type {};

	template<class T, class U>
	struct is_member_function_pointer_helper<T U::*> : is_function<T> {};

	template<class T>
	struct is_member_function_pointer : is_member_function_pointer_helper<remove_cv_t<T> > {};

	template<class T>
	inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<T>::value;
}

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H_