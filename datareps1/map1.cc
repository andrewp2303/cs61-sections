#include <map> // gain access to `std::map`
#include <cstdio>
#include <cstdint>

std::map<uintptr_t, const char*> m;

int main() {
    // note that {} signify a k, v pair
    m.insert({0, "Hello"});
    m.insert({2, "!"});
    m.insert({1, "world"});

    for (auto it = m.begin(); it != m.end(); ++it) {
        // interesting: uses %zu to reference uintptr_t, works for all *_t
        fprintf(stderr, "key %zu, value %s\n", it->first, it->second);
    }
}

// ==> key 0, value Hello
//     key 1, value world
//     key 2, value !
