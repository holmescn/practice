#include<type_traits>

/**
 * SFINAE in c++11
 */
template<typename T>
struct has_typedef_foo {
    template<typename C>
    static void test(typename C::foo*) noexcept(true);

    template<typename C>
    static void test( ... ) noexcept(false);

    static const bool value = noexcept(test<T>(0));
};

template<typename T>
struct has_member_func {
    typedef void (T::*func_type)();

    template<typename C>
    static void test(typename std::enable_if<std::is_same<decltype(&C::member_func), func_type>::value, int>::type) noexcept(true);

    template<typename C>
    static void test( ... ) noexcept(false);

    static const bool value = noexcept(test<T>(0));
};

template<typename T>
struct has_member_var_int {
    typedef int T::*var_type;

    template<typename C>
    static void test(typename std::enable_if<std::is_same<decltype(&C::member_var_int), var_type>::value, int>::type) noexcept(true);

    template<typename C>
    static void test( ... ) noexcept(false);

    static const bool value = noexcept(test<T>(0));
};


