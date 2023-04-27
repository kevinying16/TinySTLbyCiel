#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ADD_LVALUE_REFERENCE_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ADD_LVALUE_REFERENCE_H_

#include "type_identity.h"

namespace ciel {

	template<class T>
	type_identity<T&> add_lvalue_reference_helper(int);

	//SFINAE: 防止void到void&的编译错误，这时丢弃上述特化，而采用以下版本
	template<class T>
	type_identity<T> add_lvalue_reference_helper(...);

	template<class T>
	struct add_lvalue_reference : decltype(add_lvalue_reference_helper<T>(0)) {};

	template<class T>
	using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
}

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ADD_LVALUE_REFERENCE_H_