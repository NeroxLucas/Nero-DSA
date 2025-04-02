//suppose an array of size >=6. its values must be initialized by inters of ur choice. we want to arrange this array and the output array so that the prime number are first and then non-prime numbers.
//note: prime numbers are natural numbers that are divisible by 1 and itself
//write a function to check a number is prime
//a function to swap prime's position in the array
//a function to display an input array
//main function to test 

#include <stdio.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rearrangeArray(int arr[], int size) {
    int temp[size], index = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {10, 30, 19, 13, 8, 17, 90}; // Example Checked
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    displayArray(arr, size);

    rearrangeArray(arr, size);

    printf("Rearranged array (prime numbers first): ");
    displayArray(arr, size);

    return 0;
}


//bai 2 
//implement a clock data structure to manipulate time
//a structure to store hours (values [0;23]), minutes [0;59], seconds [0;59];
//a function to initialize a clock variable with 3 values (hour, minutes, second)
//a function to increase a clock variable by 1 second
//a function to caluclate the difference between 2 clock variables 
//a main function to test

#include <stdio.h>

typedef struct {
    int hour;
    int minute;
    int second;
} Clock;

void initializeClock(Clock *c, int h, int m, int s) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        c->hour = h;
        c->minute = m;
        c->second = s;
    } else {
        printf("Invalid time.\n");
    }
}

void incrementClock(Clock *c) {
    c->second++;
    if (c->second >= 60) {
        c->second = 0;
        c->minute++;
        if (c->minute >= 60) {
            c->minute = 0;
            c->hour++;
            if (c->hour >= 24) {
                c->hour = 0; 
            }
        }
    }
}

int calculateDifference(Clock c1, Clock c2) {
    int t1 = c1.hour * 3600 + c1.minute * 60 + c1.second;
    int t2 = c2.hour * 3600 + c2.minute * 60 + c2.second;
    return t2 - t1; 
}

void displayClock(Clock c) {
    printf("%02d:%02d:%02d\n", c.hour, c.minute, c.second);
}

int main() {
    Clock clock1, clock2;

    initializeClock(&clock1, 10, 30, 59);
    initializeClock(&clock2, 10, 31, 46); // 2 cai nay lay vi du khac cung dc nhe

    printf("Clock 1: ");
    displayClock(clock1);

    printf("Clock 2: ");
    displayClock(clock2);

    incrementClock(&clock1);
    printf("After incrementing, Clock 1: ");
    displayClock(clock1);

    int diff = calculateDifference(clock1, clock2);
    printf("Difference between Clock 1 and Clock 2: %d seconds\n", diff);

    return 0;
}

