#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_CLASS_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_CLASS_H_

#include "integral_constant.h"

namespace ciel {

	template<class T>
	struct is_class : bool_constant<__is_class(T)> {};

	template<class T>
	inline constexpr bool is_class_v = is_class<T>::value;
}

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_CLASS_H_