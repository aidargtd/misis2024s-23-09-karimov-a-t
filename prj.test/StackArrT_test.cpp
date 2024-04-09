//unittest
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "StackArrT/StackArrT.hpp"
//#include <initializer_list>

TEST_CASE_TEMPLATE("t, f & r", T, int, float, double, long long, long, std::int64_t) {
    StackArrT<T> f;
    CHECK(f.empty());
    StackArrT<T> t(f);
    CHECK(t.empty());
    CHECK_THROWS(void(t.pop()));
    CHECK_THROWS(void(t.top()));
    f.push(7);
    f.push(8);
    CHECK(f.size() == 2);
    StackArrT <T> r(f);
    CHECK(r.size() == 2);
    CHECK(r.top() == 8);
    r.pop();
    CHECK(r.top() == 7);
    r.pop();
    CHECK(r.empty());
    r = f;
    CHECK(r == f);
    r.pop();
    CHECK(r != f);
}

TEST_CASE("x, y, z & a") {
    std::initializer_list<double> x = { 6.0, 2.3, 6.1, 3.6 };
    StackArrT<double> y(x);
    CHECK(y.size() == 4);
    CHECK(y.top() == 3.6);
    std::initializer_list<double> a = { 2.2, 6.2, 2.3, 8.2, 6.3, 7.2 };
    StackArrT<double> z = a;
    CHECK(y != z);
    y.swap(z);
    CHECK(y.top() == 7.2);
    CHECK(y.size() == 6);
    y.merge(z);
    CHECK(z.empty());
    CHECK(y.size() == 10);
    CHECK(y.top() == 3.6);

}