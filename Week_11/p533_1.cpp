#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;
public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    // + 연산자
    friend TimeHMS operator+(const TimeHMS& lhs, const TimeHMS& rhs);

    // - 연산자
    friend TimeHMS operator-(const TimeHMS& lhs, const TimeHMS& rhs);

    // == 연산자
    friend bool operator==(const TimeHMS& lhs, const TimeHMS& rhs);

    // != 연산자
    friend bool operator!=(const TimeHMS& lhs, const TimeHMS& rhs);

    // 전위 ++ (1시간 증가)
    TimeHMS& operator++();

    // 전위 -- (1시간 감소)
    TimeHMS& operator--();

    // 후위 ++ (1초 증가)
    TimeHMS operator++(int);

    // 후위 -- (1초 감소)
    TimeHMS operator--(int);

    // 인덱스 연산자
    int operator[](int index) const;

    // int로 형 변환 (총 초)
    operator int() const;

    // double로 형 변환 (시간 단위)
    operator double() const;

    // 정수 * TimeHMS
    friend TimeHMS operator*(int n, const TimeHMS& t);

    // 입력 연산자 >>
    friend istream& operator>>(istream& is, TimeHMS& t);

    // 출력 연산자 <<
    friend ostream& operator<<(ostream& os, const TimeHMS& t);
};

// + 연산자 구현
TimeHMS operator+(const TimeHMS& lhs, const TimeHMS& rhs) {
    int totalSec = lhs.sec + rhs.sec;
    int carryMin = totalSec / 60;
    int finalSec = totalSec % 60;

    int totalMin = lhs.min + rhs.min + carryMin;
    int carryHour = totalMin / 60;
    int finalMin = totalMin % 60;

    int finalHour = lhs.hour + rhs.hour + carryHour;

    return TimeHMS(finalHour, finalMin, finalSec);
}

// - 연산자 구현
TimeHMS operator-(const TimeHMS& lhs, const TimeHMS& rhs) {
    int totalSec = lhs.sec - rhs.sec;
    int borrowMin = 0;
    if (totalSec < 0) {
        borrowMin = -1;
        totalSec += 60;
    }

    int totalMin = lhs.min - rhs.min + borrowMin;
    int borrowHour = 0;
    if (totalMin < 0) {
        borrowHour = -1;
        totalMin += 60;
    }

    int finalHour = lhs.hour - rhs.hour + borrowHour;

    return TimeHMS(finalHour, totalMin, totalSec);
}

// == 연산자 구현
bool operator==(const TimeHMS& lhs, const TimeHMS& rhs) {
    return lhs.hour == rhs.hour && lhs.min == rhs.min && lhs.sec == rhs.sec;
}

// != 연산자 구현
bool operator!=(const TimeHMS& lhs, const TimeHMS& rhs) {
    return !(lhs == rhs);
}

// 전위 ++ (1시간 증가)
TimeHMS& TimeHMS::operator++() {
    hour++;
    return *this;
}

// 전위 -- (1시간 감소)
TimeHMS& TimeHMS::operator--() {
    hour--;
    return *this;
}

// 후위 ++ (1초 증가)
TimeHMS TimeHMS::operator++(int) {
    TimeHMS temp = *this;
    sec++;
    if (sec >= 60) {
        sec -= 60;
        min++;
        if (min >= 60) {
            min -= 60;
            hour++;
        }
    }
    return temp;
}

// 후위 -- (1초 감소)
TimeHMS TimeHMS::operator--(int) {
    TimeHMS temp = *this;
    sec--;
    if (sec < 0) {
        sec += 60;
        min--;
        if (min < 0) {
            min += 60;
            hour--;
        }
    }
    return temp;
}

// 인덱스 연산자
int TimeHMS::operator[](int index) const {
    if (index == 0) return hour;
    if (index == 1) return min;
    if (index == 2) return sec;
    return 0;
}

// int로 형 변환 (총 초)
TimeHMS::operator int() const {
    return hour * 3600 + min * 60 + sec;
}

// double로 형 변환 (시간 단위)
TimeHMS::operator double() const {
    return hour + min / 60.0 + sec / 3600.0;
}

// 정수 * TimeHMS
TimeHMS operator*(int n, const TimeHMS& t) {
    int totalSec = (t.hour * 3600 + t.min * 60 + t.sec) * n;
    int finalSec = totalSec % 60;
    int totalMin = totalSec / 60;
    int finalMin = totalMin % 60;
    int finalHour = totalMin / 60;
    return TimeHMS(finalHour, finalMin, finalSec);
}

// 입력 연산자 >>
istream& operator>>(istream& is, TimeHMS& t) {
    cout << "Enter hours: ";
    is >> t.hour;
    cout << "Enter minutes: ";
    is >> t.min;
    cout << "Enter seconds: ";
    is >> t.sec;

    // 입력 유효성 검사: min과 sec를 0~59로 조정
    if (t.min >= 60 || t.sec >= 60 || t.min < 0 || t.sec < 0) {
        t.hour += t.min / 60 + t.sec / 60;
        t.min = t.min % 60;
        if (t.min < 0) {
            t.min += 60;
            t.hour--;
        }
        t.sec = t.sec % 60;
        if (t.sec < 0) {
            t.sec += 60;
            t.min--;
            if (t.min < 0) {
                t.min += 60;
                t.hour--;
            }
        }
    }
    return is;
}

// 출력 연산자 <<
ostream& operator<<(ostream& os, const TimeHMS& t) {
    os << t.hour << "h " << t.min << "m " << t.sec << "s";
    return os;
}

int main() {
    TimeHMS t1, t2, t3, t4;

    // t1 입력
    cout << "Enter time t1:" << endl;
    cin >> t1;

    // t2 입력
    cout << "\nEnter time t2:" << endl;
    cin >> t2;

    // 입력 확인
    cout << "\nt1: " << t1 << endl;
    cout << "t2: " << t2 << endl;

    // + 연산자 테스트
    t3 = t1 + t2;
    cout << "t1 + t2: " << t3 << endl;

    // - 연산자 테스트
    t4 = t1 - t2;
    cout << "t1 - t2: " << t4 << endl;

    // ==와 != 연산자 테스트
    cout << "t1 == t2: " << (t1 == t2) << endl;
    cout << "t1 != t2: " << (t1 != t2) << endl;

    // 전위 ++와 -- 테스트
    ++t1;
    cout << "++t1: " << t1 << endl;
    --t1;
    cout << "--t1: " << t1 << endl;

    // 후위 ++와 -- 테스트
    t3 = t1++;
    cout << "t1++: " << t1 << endl;
    t3 = t1--;
    cout << "t1--: " << t1 << endl;

    // 인덱스 연산자 테스트
    cout << "t1[0]: " << t1[0] << "h, t1[1]: " << t1[1] << "m, t1[2]: " << t1[2] << "s" << endl;

    // int 형 변환 테스트
    cout << "(int)t1: " << (int)t1 << " seconds" << endl;

    // double 형 변환 테스트
    cout << "(double)t1: " << (double)t1 << " hours" << endl;

    // 곱셈 연산자 테스트
    t3 = 2 * t1;
    cout << "2 * t1: " << t3 << endl;

    return 0;
}