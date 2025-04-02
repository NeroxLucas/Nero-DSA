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
