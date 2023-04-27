#ifndef TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ADD_REFERENCE_H_
#define TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ADD_REFERENCE_H_

//Not C++ standard

namespace ciel {

	template<class T>
	struct add_reference_helper {
		using type = T&;
	};
	template<class T>
	struct add_reference_helper<T&> {
		using type = T&;
	};
	template<>
	struct add_reference_helper<void> {
		using type = void;
	};

	template<class T>
	struct add_reference {
		using type = typename add_reference_helper<T>::type;
	};

	template<class T>
	using add_reference_t = typename add_reference<T>::type;

}   //namespace ciel

#endif //TINYSTLBYCIEL_INCLUDE___TYPE_TRAITS_ADD_REFERENCE_H_