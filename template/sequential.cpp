#include <iostream>
#include <type_traits>

template<typename T>
struct RemoveReferenceConst_ {
private:
    using inter_type = typename std::remove_const<T>::type;
public:
    using type = typename std::remove_reference<inter_type>::type;
};

template<typename T>
using RemoveReferenceConst = typename RemoveReferenceConst_<T>::type;

template<typename T>
void func(T t) {
    std::cout << "default type " << std::endl;
}

template<>
void func<int>(int t) {
    std::cout << "int type" << std::endl;
}

template<>
void func<const int>(const int t) {
    std::cout << "const int type" << std::endl;
}

int main() {
    /**
     * call RemoveReferenceConst:
     * step1: calculate inter_type
     * step2: calculate type
    */
    RemoveReferenceConst<const int&> p = 1;
    func(p);
}