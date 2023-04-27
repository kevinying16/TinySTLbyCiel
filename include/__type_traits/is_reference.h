#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_REFERENCE_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_REFERENCE_H_

#include "integral_constant.h"

namespace ciel {

	template<class T>
	struct is_reference : false_type {};

	template<class T>
	struct is_reference<T&> : true_type {};

	template<class T>
	struct is_reference<T&&> : true_type {};

	template<class T>
	inline constexpr bool is_reference_v = is_reference<T>::value;

}   //namespace ciel

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_REFERENCE_H_