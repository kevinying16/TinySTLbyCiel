#ifndef TINYSTLBYCIEL_INCLUDE_CIEL_TYPE_TRAITS_IMPL_IS_SCOPED_ENUM_H
#define TINYSTLBYCIEL_INCLUDE_CIEL_TYPE_TRAITS_IMPL_IS_SCOPED_ENUM_H

#include <ciel/utility_impl/declval.h>
#include <ciel/type_traits_impl/is_enum.h>
#include <type_traits>

namespace ciel {

    namespace is_scoped_enum_details {

        template<class T, class = decltype(sizeof(T))>
        true_type test_sizable(int);

        template<class>
        false_type test_sizable(...);

        template<class T, class = decltype(static_cast<void (*)(int)>(nullptr)(declval<T>()))>
        false_type test_nonconvertible_to_int(int);

        template<class>
        true_type test_nonconvertible_to_int(...);
    }

    template<class>
    struct is_scoped_enum : false_type {};

    template<class T>
        requires is_enum_v<T>
    struct is_scoped_enum<T> : bool_constant<decltype(is_scoped_enum_details::test_sizable<T>(0))::value && decltype(is_scoped_enum_details::test_nonconvertible_to_int<T>(0))::value> {};

    template<class T>
    inline constexpr bool is_scoped_enum_v = is_scoped_enum<T>::value;

}   //namespace ciel

#endif //TINYSTLBYCIEL_INCLUDE_CIEL_TYPE_TRAITS_IMPL_IS_SCOPED_ENUM_H