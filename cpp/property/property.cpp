#include <string>
#include <iostream>

enum class PropertyType { ReadOnly, WriteOnly, ReadWrite };

template<typename T, typename Friend, PropertyType Type = PropertyType::ReadWrite>
class Property {
    T m_val;
    void Set(const T &val) { m_val = val; }
    T Get() const { return m_val; }
public:
    Property() : m_val( T() ) {}

    // Setter
    void operator=(const T &val) {
        static_assert(Type != PropertyType::ReadOnly, "This property is ReadOnly");
        Set(val);
    }
    // Getter
    operator T() {
        static_assert(Type != PropertyType::WriteOnly, "This property is WriteOnly");
        return Get();
    }

    typedef Friend friend_class;
    friend friend_class;
};

struct Vec2 {
    int x, y;
};

class C {
public:
    Property<int, C> property1;
    Property<float, C, PropertyType::ReadOnly> property2;
    Property<std::string, C, PropertyType::WriteOnly> property3;
    Property<Vec2, C> property4;

    void TestSet() {
        property2.Set(10.1);
    }

    void TestGet() {
        property3.Get();
    }
};

int main(int argc, char** argv) {
    using namespace std;

    C c;
    c.property1 = 2;
    int i = c.property1;
    cout << i << endl;

    // This will emit the static assert
    // c.property2 = 0.0f;
    c.TestSet();
    float f = c.property2;
    cout << f << endl;

    c.property3 = "AX";
    // This will emit the static assert
    //string s = c.property3;
    //cout << s << endl;
    c.TestGet();

    c.property4 = Vec2 { 1, 1 };
}

