#include <iostream>
#include <stdexcept>
#include <string>

// 예외 클래스 정의
class AccountException : public std::exception {
private:
    std::string message;
    int amount;

public:
    AccountException(const std::string& msg, int amt) : message(msg), amount(amt) {}

    // std::exception의 what() 오버라이드
    const char* what() const noexcept override {
        return message.c_str();
    }

    // 금액 정보 반환
    int getAmount() const {
        return amount;
    }
};

// CustomerAccount 클래스
class CustomerAccount {
private:
    int balance;

public:
    // 생성자
    CustomerAccount(int b = 0) : balance(b) {}

    // 잔액 조회
    int getBalance() const {
        return balance;
    }

    // 입금 메서드
    int deposit(int amount) {
        try {
            if (amount <= 0) {
                throw AccountException("유효하지 않은 입금 금액: 금액은 양수여야 합니다", amount);
            }
            balance += amount;
            return balance;
        } catch (const AccountException&) {
            return -1; // 예외 상황에서 -1 반환
        }
    }

    // 출금 메서드
    int withdraw(int amount) {
        try {
            if (amount > balance) {
                throw AccountException("잔액 부족으로 출금 불가", amount);
            }
            balance -= amount;
            return balance;
        } catch (const AccountException&) {
            return -1; // 예외 상황에서 -1 반환
        }
    }
};

// main 함수
int main() {
    CustomerAccount account(1000); // 초기 잔액 1000
    std::cout << "초기 잔액: " << account.getBalance() << "원" << std::endl;

    // 테스트 1: 정상 입금 (500 입금)
    try {
        std::cout << "\n테스트 1: 500원 입금" << std::endl;
        int result = account.deposit(500);
        if (result != -1) {
            std::cout << "입금 성공. 현재 잔액: " << result << "원" << std::endl;
        } else {
            std::cout << "에러 코드 -1" << std::endl;
        }
    } catch (const AccountException& e) {
        std::cout << "오류: " << e.what() << ", 금액: " << e.getAmount() << "원" << std::endl;
    }

    // 테스트 2: 음수 입금 (-200)
    try {
        std::cout << "\n테스트 2: -200원 입금" << std::endl;
        int result = account.deposit(-200);
        if (result != -1) {
            std::cout << "입금 성공. 현재 잔액: " << result << "원" << std::endl;
        } else {
            std::cout << "에러 코드 -1" << std::endl;
            std::cout << "입금 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
        }
    } catch (const AccountException& e) {
        std::cout << "오류: " << e.what() << ", 금액: " << e.getAmount() << "원" << std::endl;
        std::cout << "입금 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
    }

    // 테스트 3: 정상 출금 (300)
    try {
        std::cout << "\n테스트 3: 300원 출금" << std::endl;
        int result = account.withdraw(300);
        if (result != -1) {
            std::cout << "출금 성공. 현재 잔액: " << result << "원" << std::endl;
        } else {
            std::cout << "에러 코드 -1" << std::endl;
        }
    } catch (const AccountException& e) {
        std::cout << "오류: " << e.what() << ", 금액: " << e.getAmount() << "원" << std::endl;
    }

    // 테스트 4: 잔액 초과 출금 (2000)
    try {
        std::cout << "\n테스트 4: 2000원 출금" << std::endl;
        int result = account.withdraw(2000);
        if (result != -1) {
            std::cout << "출금 성공. 현재 잔액: " << result << "원" << std::endl;
        } else {
            std::cout << "에러 코드 -1" << std::endl;
            std::cout << "출금 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
        }
    } catch (const AccountException& e) {
        std::cout << "오류: " << e.what() << ", 금액: " << e.getAmount() << "원" << std::endl;
        std::cout << "출금 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
    }

    // 사용자 입력 루프
    std::cout << "\n=== 사용자 입력 테스트 ===" << std::endl;
    while (true) {
        std::cout << "\n작업을 선택하세요 (1: 입금, 2: 출금, 0: 종료): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "프로그램 종료. 최종 잔액: " << account.getBalance() << "원" << std::endl;
            break;
        }

        if (choice != 1 && choice != 2) {
            std::cout << "잘못된 선택입니다. 1, 2, 또는 0을 입력하세요." << std::endl;
            continue;
        }

        std::cout << "금액을 입력하세요 (원): ";
        int amount;
        std::cin >> amount;

        try {
            int result;
            if (choice == 1) {
                std::cout << amount << "원 입금 시도" << std::endl;
                result = account.deposit(amount);
                if (result != -1) {
                    std::cout << "입금 성공. 현재 잔액: " << result << "원" << std::endl;
                } else {
                    std::cout << "에러 코드 -1" << std::endl;
                    std::cout << "입금 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
                }
            } else {
                std::cout << amount << "원 출금 시도" << std::endl;
                result = account.withdraw(amount);
                if (result != -1) {
                    std::cout << "출금 성공. 현재 잔액: " << result << "원" << std::endl;
                } else {
                    std::cout << "에러 코드 -1 " << std::endl;
                    std::cout << "출금 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
                }
            }
        } catch (const AccountException& e) {
            std::cout << "오류: " << e.what() << ", 금액: " << e.getAmount() << "원" << std::endl;
            std::cout << "작업 실패 후 잔액: " << account.getBalance() << "원" << std::endl;
        }
    }

    return 0;
}
