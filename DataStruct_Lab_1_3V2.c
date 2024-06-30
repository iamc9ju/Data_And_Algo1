#include <stdio.h>
int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a,a);
}
int main() {
    int n, result;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    printf("%d", result);
    return 0;
}
