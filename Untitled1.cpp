#include <stdio.h>
// H�m �? so s�nh v� t?m gi� tr? l?n nh?t
int max(int a, int b) { return (a > b)? a : b; }

// H�m �? quy �? t?m gi� tr? l?n nh?t c� th? �?t ��?c
int knapsack(int W, int wt[], int val[], int n) {
    // Tr�?ng h?p c� s?
    if (n == 0 || W == 0)
        return 0;

    // N?u tr?ng l�?ng c?a �? v?t cu?i c�ng l?n h�n tr?ng l�?ng ba l�, b? qua n�
    if (wt[n-1] > W)
        return knapsack(W, wt, val, n-1);

    // Tr? v? gi� tr? l?n nh?t gi?a hai tr�?ng h?p:
    // 1. �? v?t cu?i c�ng ��?c ch?n
    // 2. �? v?t cu?i c�ng kh�ng ��?c ch?n
    else
        return max(
            val[n-1] + knapsack(W-wt[n-1], wt, val, n-1),
            knapsack(W, wt, val, n-1)
        );
}


int main() {
    int val[] = {60, 100, 120}; // Gi� tr? c?a c�c �? v?t
    int wt[] = {10, 20, 30}; // Tr?ng l�?ng c?a c�c �? v?t
    int W = 50; // Tr?ng l�?ng t?i �a c?a ba l�
    int n = sizeof(val)/sizeof(val[0]);
    printf("Gi� tr? l?n nh?t c� th? �?t ��?c l� %d", knapsack(W, wt, val, n));
    return 0;
}

