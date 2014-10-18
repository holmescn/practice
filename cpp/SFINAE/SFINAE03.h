#pragma once

template<bool Cond, typename T = void> struct enable_if { };
template<typename T> struct enable_if<true, T> { typedef T type; };

/**
 * The SFINAE in C++03
 */
template<typename T>
struct has_typedef_foo {
    typedef char yes;
    typedef short no;

    template<typename C>
    static yes& test( typename C::foo* );

    template<typename C>
    static no& test( ... );

    static const bool value = (sizeof(test<T>(0)) == sizeof(yes));
};


/**
 * Has member function with specified signature.
 */
template<typename T>
struct has_member_func {
    typedef char yes;
    typedef short no;
    typedef void (T::*signature)();

    template<typename C, signature>
    struct SignatureTest {
        static const bool value = true;
    };

    template<typename C>
    static yes& test(typename enable_if<SignatureTest<C, &C::member_func>::value, int>::type);

    template<typename C>
    static no& test(...);

    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};


/**
 * Has member variable with specified type.
 */
template<typename T>
struct has_member_var_int {
    typedef char yes;
    typedef short no;
    typedef int T::*var_type;

    template<typename C, var_type>
    struct VarTypeTest {
        static const bool value = true;
    };


    template<typename C>
    static yes& test(typename enable_if<VarTypeTest<C, &C::member_var_int>::value, int>::type);

    template<typename C>
    static no& test(...);

    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};


