#include <cstdio>
#include <functional>

int main() {
    auto recursiveLambda = [](auto&& self, bool msb, auto... bits) -> int {
        if constexpr (sizeof...(bits) > 0) {
            return (msb << sizeof...(bits)) + self(self, bits...);
        } else {
            return msb;
        }
    };

    for (auto i = 0; std::putchar(
        recursiveLambda(recursiveLambda, i == 4, (3 > i) * i, !((i + 1) % 4), (i != 4) * i, i & (5 > i))
        + i * 2 + 97)
        - 115; ++i);

    return 0;
}
