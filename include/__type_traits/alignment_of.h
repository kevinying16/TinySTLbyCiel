#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ALIGNMENT_OF_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ALIGNMENT_OF_H_

#include "integral_constant.h"
#include <cstddef>

namespace ciel {

	template<class T>
	struct alignment_of : integral_constant<size_t, alignof(T)> {};

	template<class T>
	inline constexpr size_t alignment_of_v = alignment_of<T>::value;
}

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ALIGNMENT_OF_H_