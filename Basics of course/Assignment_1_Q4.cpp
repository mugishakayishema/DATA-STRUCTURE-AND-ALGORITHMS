//reg number: 224003729
//Names: MUGISHA Kayishema
#include <iostream>
#include <cmath>

size_t base_address;

void measureStackRecursive(int n, int& maxUsage) {
    int x; // local variable
    size_t current = (size_t)&x;

    int used = std::abs((long long)base_address - (long long)current);
    maxUsage = std::max(maxUsage, used);

    if (n <= 1) return;
    measureStackRecursive(n - 1, maxUsage);
}

void measureStackIterative(int n, int& maxUsage) {
    int x; // local variable
    size_t current = (size_t)&x;
    int used = std::abs((long long)base_address - (long long)current);
    maxUsage = used; // iterative uses constant memory
}

int main() {
    int maxRec = 0, maxIter = 0;

    // establish base address
    int dummy;
    base_address = (size_t)&dummy;

    measureStackRecursive(1000, maxRec);
    measureStackIterative(1000, maxIter);

    std::cout << "Recursive stack usage: " << maxRec << " bytes\n";
    std::cout << "Iterative stack usage: " << maxIter << " bytes\n";

    return 0;
}
