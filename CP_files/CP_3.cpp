#include <iostream>
#include <bitset>

int main() {
    std::bitset<4> b("1011"); // Your bitset
    int number_to_check = 2;   // The number you want to check

    // Check if the bit at the given index is set to 1
    if (b[number_to_check]) {
        std::cout << "Number " << number_to_check << " can be formed." << std::endl;
    } else {
        std::cout << "Number " << number_to_check << " cannot be formed." << std::endl;
    }

    return 0;
}
