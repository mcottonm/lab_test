#include <iostream>

inline long op(long num1, long num2, char sign) {
    if (sign == '-')
        num1 -= num2;
    else
        num1 += num2;
    return num1;
}

bool calculate(const std::string& s) {
    long sum = 0;
    char sign = '+';
    std::string tmp;
    for (char c : s){
        if (isdigit(c)) {
            tmp += c;
        } else {
            sum = op(sum, std::stol(tmp), sign);
            tmp.clear();
            sign = c;
        }
    }
    sum = op(sum, std::stol(tmp), sign);
    return sum == 200;
}

void combine(std::string s, char num, char sign) {
    if (sign) {
        s += sign;
    }
    s += num;
    if (num > '0') {
        combine(s, num - 1, 0);
        combine(s, num - 1, '-');
        combine(s, num - 1, '+');
    } else if (calculate(s))
        std::cout << s << '\n';
}

int main() {
    std::string s;
    combine(s, '9', 0);
    return 0;
}