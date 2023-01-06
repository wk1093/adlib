#pragma once
#include <cstdint>
#include <cstdio>
#include <cmath>

struct Dec { // similar to how scientific notation works, but with no decimal point at all.
    // 1.2 = 12e-1
    // 12 = 12e0
    // 120 = 12e1
    int64_t num; // number
    int32_t pwr;  // power
    Dec(uint64_t num, int32_t pwr) : num(num), pwr(pwr) {}
    Dec() : num(0), pwr(0) {}
    Dec(double num) {
        this->pwr = 0;
        while (num != (int64_t)num) {
            num *= 10;
            this->pwr--;
        }
        this->num = num;

        while (this->num % 10 == 0 && this->num != 0) {
            this->num /= 10;
            this->pwr++;
        }
    }

    void print() {
        printf("%lde%d\n", num, pwr);
    }

    Dec operator+(Dec other) {
        if (this->pwr == other.pwr) {
            return Dec(this->num + other.num, this->pwr);
        } else if (this->pwr > other.pwr) {
            return Dec(this->num + other.num * pow(10, this->pwr - other.pwr), this->pwr);
        } else {
            return Dec(this->num * pow(10, other.pwr - this->pwr) + other.num, other.pwr);
        }
    }
    Dec operator-(Dec other) {
        if (this->pwr == other.pwr) {
            return Dec(this->num - other.num, this->pwr);
        } else if (this->pwr > other.pwr) {
            return Dec(this->num - other.num * pow(10, this->pwr - other.pwr), this->pwr);
        } else {
            return Dec(this->num * pow(10, other.pwr - this->pwr) - other.num, other.pwr);
        }
    }
    Dec operator*(Dec other) {
        return Dec(this->num * other.num, this->pwr + other.pwr);
    }
    Dec operator/(Dec other) {
        return Dec(this->num / other.num, this->pwr - other.pwr);
    }
    Dec operator%(Dec other) {
        return Dec(this->num % other.num, this->pwr);
    }
    Dec operator^(Dec other) {
        return Dec(pow(this->num, other.num), this->pwr * other.num);
    }
    Dec operator+=(Dec other) {
        return *this + other;
    }
    Dec operator-=(Dec other) {
        return *this - other;
    }
    Dec operator*=(Dec other) {
        return *this * other;
    }
    Dec operator/=(Dec other) {
        return *this / other;
    }
    Dec operator%=(Dec other) {
        return *this % other;
    }
    Dec operator^=(Dec other) {
        return *this ^ other;
    }
    Dec operator++() {
        return *this + Dec(1);
    }
    Dec operator--() {
        return *this - Dec(1);
    }
    Dec operator++(int) {
        Dec temp = *this;
        *this = *this + Dec(1);
        return temp;
    }
    Dec operator--(int) {
        Dec temp = *this;
        *this = *this - Dec(1);
        return temp;
    }
    Dec operator-() {
        return Dec(-this->num, this->pwr);
    }
    Dec operator+() {
        return *this;
    }
    bool operator==(Dec other) {
        return this->num == other.num && this->pwr == other.pwr;
    }
    bool operator!=(Dec other) {
        return this->num != other.num || this->pwr != other.pwr;
    }
    bool operator>(Dec other) {
        if (this->pwr == other.pwr) {
            return this->num > other.num;
        } else if (this->pwr > other.pwr) {
            return this->num > other.num * pow(10, this->pwr - other.pwr);
        } else {
            return this->num * pow(10, other.pwr - this->pwr) > other.num;
        }
    }
    bool operator<(Dec other) {
        if (this->pwr == other.pwr) {
            return this->num < other.num;
        } else if (this->pwr > other.pwr) {
            return this->num < other.num * pow(10, this->pwr - other.pwr);
        } else {
            return this->num * pow(10, other.pwr - this->pwr) < other.num;
        }
    }
    bool operator>=(Dec other) {
        if (this->pwr == other.pwr) {
            return this->num >= other.num;
        } else if (this->pwr > other.pwr) {
            return this->num >= other.num * pow(10, this->pwr - other.pwr);
        } else {
            return this->num * pow(10, other.pwr - this->pwr) >= other.num;
        }
    }
    bool operator<=(Dec other) {
        if (this->pwr == other.pwr) {
            return this->num <= other.num;
        } else if (this->pwr > other.pwr) {
            return this->num <= other.num * pow(10, this->pwr - other.pwr);
        } else {
            return this->num * pow(10, other.pwr - this->pwr) <= other.num;
        }
    }
};
Dec DecLR(int32_t left, int32_t right) {
        // get size of each number
        Dec result;
        int32_t lsize = 0, rsize = 0;
        int32_t l = left, r = right;
        while (l != 0) {
            l /= 10;
            lsize++;
        }
        while (r != 0) {
            r /= 10;
            rsize++;
        }
        int rs = left * pow(10, rsize) + right;
        result.pwr = -rsize;
        while (rs % 10 == 0 && rs != 0) {
            rs /= 10;
            result.pwr++;
        }
        result.num = rs;
        return result;
    }