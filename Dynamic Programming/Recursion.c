//
//  막대 자르기 - 재귀 함수
//  Recursion
//
//  Created by 홍준우 on 7/10/24.
//

#include <stdio.h>
#include <limits.h>

/// 정수를 비교하여 둘 중 큰 수를 반환한다.
int max(int i, int j) { return (i > j) ? i : j; }

/// 재귀적으로 자기 자신을 호출하여 최대 이익일 때를 구한다.
int Recursion(int *p, int n) {
    if (n == 0) return 0;
    int q = INT_MIN;
    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + Recursion(p, n - i));
    }
    return q;
}

int main(void) {
    int n;
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    scanf("%d", &n);
    printf("%d\n", Recursion(p, n));
    return 0;
}
