//
//  main.cpp
//  Credit card validator
//
//  Created by Umutcan Adıgüzel on 18.12.2022.
//

#include <iostream>

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

int main(int argc, const char * argv[]) {
    
    std::string cardNumber;
    int result = 0;
    
    std::cout << "Enter a credit card #: ";
    std::cin >> cardNumber;
    
    result = sumOddDigits(cardNumber) + sumEvenDigits(cardNumber);
    
    if (result % 10 == 0) {
        std::cout << cardNumber << " is valid";
    }
    else {
        std::cout << cardNumber << " is not valid";
    }
    
    return 0;
}

int getDigit(const int number) {
    
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string cardNumber) {
    
    int sum = 0;
    
    for(int i = cardNumber.size() - 1; i >= 0; i-=2) {
        sum += cardNumber[i] - '0';
    }
    
    return sum;
}

int sumEvenDigits(const std::string cardNumber) {
    
    int sum = 0;
    
    for(int i = cardNumber.size() - 2; i >= 0; i-=2) {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    
    return sum;
}
