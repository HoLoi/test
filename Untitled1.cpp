#include <stdio.h>
// Hàm ð? so sánh và t?m giá tr? l?n nh?t
int max(int a, int b) { return (a > b)? a : b; }

// Hàm ð? quy ð? t?m giá tr? l?n nh?t có th? ð?t ðý?c
int knapsack(int W, int wt[], int val[], int n) {
    // Trý?ng h?p cõ s?
    if (n == 0 || W == 0)
        return 0;

    // N?u tr?ng lý?ng c?a ð? v?t cu?i cùng l?n hõn tr?ng lý?ng ba lô, b? qua nó
    if (wt[n-1] > W)
        return knapsack(W, wt, val, n-1);

    // Tr? v? giá tr? l?n nh?t gi?a hai trý?ng h?p:
    // 1. Ð? v?t cu?i cùng ðý?c ch?n
    // 2. Ð? v?t cu?i cùng không ðý?c ch?n
    else
        return max(
            val[n-1] + knapsack(W-wt[n-1], wt, val, n-1),
            knapsack(W, wt, val, n-1)
        );
}


int main() {
    int val[] = {60, 100, 120}; // Giá tr? c?a các ð? v?t
    int wt[] = {10, 20, 30}; // Tr?ng lý?ng c?a các ð? v?t
    int W = 50; // Tr?ng lý?ng t?i ða c?a ba lô
    int n = sizeof(val)/sizeof(val[0]);
    printf("Giá tr? l?n nh?t có th? ð?t ðý?c là %d", knapsack(W, wt, val, n));
    return 0;
}

