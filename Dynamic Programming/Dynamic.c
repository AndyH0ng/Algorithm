//
//  막대 자르기 - 동적 프로그래밍
//  Dynamic Programming
//
//  Created by 홍준우 on 7/10/24.
//

#include <stdio.h>
#include <limits.h>

int max(int i, int j) { return (i > j) ? i : j; }

int DP(int *p, int n, int *r) {
    // 이전 프로시저에서 문제를 풀었을 경우 저장했던 결과를 반환한다.
    if (r[n] >= 0) return r[n];
    int q;
    if (n == 0) q = 0;
    else {
        // "아직 모름"의 상태를 부여한다.
        q = INT_MIN;
        for (int i = 1; i <= n; i++)
            q = max(q, p[i] + DP(p, n - i, r));
    }
    // 현재 프로시저에서 문제를 풀었을 경우 결과를 저장한다.
    r[n] = q;
    return q;
}

int main(void) {
    int n;
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    scanf("%d", &n);
    // r[] : 개별 문제의 결과를 저장한다.
    int r[n + 1];
    for (int i = 0; i <= n; i++)
        r[i] = INT_MIN;
    printf("%d\n", DP(p, n, r));
    return 0;
}
