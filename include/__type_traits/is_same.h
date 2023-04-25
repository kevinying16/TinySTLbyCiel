#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_SAME_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_SAME_H_

#include "integral_constant.h"

namespace ciel {
	template<class T, class U>
	struct is_same : false_type {};

	template<class T>
	struct is_same<T, T> : true_type {};

	template<class T, class U>
	inline constexpr bool is_same_v = is_same<T, U>::value;
}

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_IS_SAME_H_