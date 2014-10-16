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
 * Failed.
 */
template<bool Cond, typename T = void> struct enable_if { };
template<typename T> struct enable_if<true, T> { typedef T type; };

template<typename T>
struct has_member_func {
    typedef char yes;
    typedef short no;

    template<typename C>
    static yes& test(void (C::*pt)());

    template<typename C>
    static no& test( ... );

    static const bool value = (sizeof(test<T>(0)) == sizeof(yes));
};

