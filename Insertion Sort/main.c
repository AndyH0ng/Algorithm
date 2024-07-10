//
//  삽입 정렬
//  Insertion Sort
//
//  Created by 홍준우 on 6/19/24.
//

#include <stdio.h>
#define ASCENDING 0
#define DESCENDING 1

void insertion_sort(int *A, int order) {
    if (order == 0) {
        for (int j = 1; j < 6; j++) {
            int key = A[j];
            // A[j]를 정렬된 배열 A[0. . j - 1] 에 삽입한다.
            int i = j - 1;
            // MARK: A[j + 1. . n] 은 아직 정렬되지 않은 것이지만, A[0. . j - 1] 은 정렬되어 저장된 것이다. 이러한 특성을 루프 불변성 Loop invariant 이라 한다.
            while (i >= 0 && A[i] > key) {
                A[i + 1] = A[i];
                i--;
            }
            A[i + 1] = key;
        }
        for (int i = 0; i < 6; i++) printf("%d ", A[i]);
    }
    else if (order == 1) {
        for (int j = 5; j >= 0; j--) {
            int key = A[j];
            // A[j]를 정렬된 배열 A[j + 1. . n] 에 삽입한다.
            int i = j + 1;
            // MARK: A[0. . j - 1] 은 아직 정렬되지 않은 것이지만, A[j + 1. . n] 은 정렬되어 저장된 것이다. 이러한 특성을 루프 불변성 Loop invariant 이라 한다.
            while (i < 6 && A[i] > key) {
                A[i - 1] = A[i];
                i++;
            }
            A[i - 1] = key;
        }
        for (int i = 0; i < 6; i++) printf("%d ", A[i]);
    }
}

int main(void) {
    int A[6] = {5, 2, 4, 6, 1, 3};
    insertion_sort(A, DESCENDING);
    return 0;
}
