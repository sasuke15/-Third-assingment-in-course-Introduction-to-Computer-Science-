
/*
    Assigend by:
    Shay Bach #204263842,61101-7
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void Ex1a();
void Ex1b();
void Ex2();
void Ex3();
void Ex4a();
void Ex4b();
void Ex5();

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once-enter 0,cyclically-enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do {
            for (i = 1; i <= 7; i++) {
                if (i == 1)
                    printf("Ex1a--->1\n");
                if (i == 2)
                    printf("Ex1b--->2\n");
                if (i == 3 || i == 4)
                    printf("Ex%d--->%d\n", i - 1, i);
                if (i == 5)
                    printf("Ex4a--->5\n");
                if (i == 6)
                    printf("Ex4b--->6\n");
                if (i == 7)
                    printf("Ex5--->7\n");
            }
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-7:");
                scanf("%d", &select);
            } while ((select < 0) || (select > 7));
            switch (select) {
            case 1:
                Ex1a();
                break;
            case 2:
                Ex1b();
                break;
            case 3:
                Ex2();
                break;
            case 4:
                Ex3();
                break;
            case 5:
                Ex4a();
                break;
            case 6:
                Ex4b();
                break;
            case 7:
                Ex5();
                break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

/* ------------------- */
/* int put array */
int* input_array_dyn(int condition, int size)
{
    int *one_dimantion_arry, i;
    if (condition == 1) {
        one_dimantion_arry = (int*)malloc(size * sizeof(int));
        for (i = 0; size > i; i++)
            scanf("%d", &one_dimantion_arry[i]);
        return one_dimantion_arry;
    }
    else {
        one_dimantion_arry = (int*)malloc(size * sizeof(int));
        return one_dimantion_arry;
    }
}
int** input_array_dyn2(int size)
{
    int **two_dimantion_arry, i, j;
    two_dimantion_arry = (int**)malloc(size * sizeof(int*));
    for (i = 0; size > i; i++)
        two_dimantion_arry[i] = (int*)malloc(size * sizeof(int));
    for (i = 0; size > i; i++)
        for (j = 0; size > j; j++)
            scanf("%d", &two_dimantion_arry[i][j]);
    return two_dimantion_arry;
}
/* algoritems */
void merge(int* a, int p, int q, int r)
{
    int i = p, j = q + 1, k = 0;
    int* temp = (int*)calloc(r - p + 1, sizeof(int));
    while ((i <= q) && (j <= r))
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    while (j <= r)
        temp[k++] = a[j++];
    while (i <= q)
        temp[k++] = a[i++];
    for (i = p, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
    free(temp);
}
void merge_sort(int* a, int first, int last)
{
    int middle;
    if (first < last) {
        middle = (first + last) / 2;
        merge_sort(a, first, middle);
        merge_sort(a, middle + 1, last);
        merge(a, first, middle, last);
    }
}
int bin_search(int key, int* a, int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == a[mid])
            return 1;
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
int search(int** a, int n, int x)
{
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (a[i][j] == x)
            return 1;
        if (a[i][j] > x)
            j--;
        else
            i++;
    }
    return 0;
}
/* Exercise1a */
int funckchia_1a(int* A, int* B, int n)
{
    int i;
    for (i = 0; n > i; i++)
        if (A[i] != B[i])
            return 0;
    return 1;
}
void Ex1a()
{
    int *A, *B, n, result;
    printf("please enter the size of the arrays\n");
    scanf("%d", &n);
    printf("please enter the objects in array A\n");
    A = input_array_dyn(1, n);
    printf("please enter the objects in array B\n");
    B = input_array_dyn(1, n);
    merge_sort(A, 0, n - 1);
    merge_sort(B, 0, n - 1);
    result = funckchia_1a(A, B, n);
    printf("%d\n", result);
    if (result == 1)
        printf("true\n");
    else
        printf("false\n");
    free(A);
    free(B);
}
/* Exercise1b */
int funckchia_1b(int* A, int* B, int n)
{
    int help_arry[100], i;
    for (i = 0; 100 > i; i++)
        help_arry[i] = 0;
    for (i = 0; n > i; i++)
        ++help_arry[A[i]];
    for (i = 0; n > i; i++)
        --help_arry[B[i]];
    for (i = 0; 100 > i; i++)
        if (help_arry[i] != 0)
            return 0;
    return 1;
    free(help_arry);
}
void Ex1b()
{
    int *A, *B, result, n;
    printf("please enter the size of the arrys\n");
    scanf("%d", &n);
    printf("please enter the objects of the arry A (the objects must be bitween 1 to 100)\n");
    A = input_array_dyn(1, n);
    printf("please enter the objects of the arry B (the objects must be bitween 1 to 100)\n");
    B = input_array_dyn(1, n);
    result = funckchia_1b(A, B, n);
    printf("%d\n", result);
    if (result == 1)
        printf("true\n");
    else
        printf("false\n");
    free(A);
    free(B);
}
/* Exercise2 */
int funkchia_2(int* A, int* B, int d, int n, int m)
{
    int i, result;
    if (n > m) {
        merge_sort(A, 0, n - 1);
        for (i = 0; m > i; i++) {
            result = bin_search(B[i] + d, A, n);
            if (result == 1)
                return 1;
        }
    }
    else {
        merge_sort(B, 0, n - 1);
        for (i = 0; n > i; i++) {
            result = bin_search(A[i] - d, B, n);
            if (result == 1)
                return 1;
        }
    }
    return 0;
}
void Ex2()
{
    int *A, *B, m, n, d, result;
    printf("please enter the number d\n");
    scanf("%d", &d);
    printf("please enter the size of arry A\n");
    scanf("%d", &n);
    printf("please enter the size of arry B\n");
    scanf("%d", &m);
    printf("please enter the objects in array A\n");
    A = input_array_dyn(1, n);
    printf("please enter the objects in array B\n");
    B = input_array_dyn(1, m);
    result = funkchia_2(A, B, d, n, m);
    printf("%d\n", result);
    if (result == 1)
        printf("true\n");
    else
        printf("false\n");
    free(A);
    free(B);
}
/* Exercise3 */
int* funkchia_3(int* A, int* B, int n, int m, int* size)
{
    int i = 0, j = 0, *new_arry;
    *size = 0;
    if (n > m)
        new_arry = input_array_dyn(-1, m);
    else
        new_arry = input_array_dyn(-1, n);
    merge_sort(A, 0, n - 1);
    merge_sort(B, 0, m - 1);
    while (n > i && m > j) {
        if (A[i] == B[j]) {
            new_arry[*size] = A[i];
            ++*size;
            ++i;
            ++j;
        }
        else {
            if (A[i] > B[j])
                ++j;
            else
                ++i;
        }
    }
    new_arry = (int*)realloc(new_arry, *size * sizeof(int));
    return new_arry;
}
void Ex3()
{
    int *A, *B, n, m, *new_arry, size, i;
    printf("please enter the size of A\n");
    scanf("%d", &n);
    printf("please enter the size of B\n");
    scanf("%d", &m);
    printf("please enter the objects in A\n");
    A = input_array_dyn(1, n);
    printf("please enter the objects in B\n");
    B = input_array_dyn(1, m);
    new_arry = funkchia_3(A, B, n, m, &size);
    printf("the size of the new array is:%d\n", size);
    printf("the objects of the array are:\t");
    for (i = 0; size > i; i++)
        printf("%d\t", new_arry[i]);
    printf("\n");
    free(A);
    free(B);
    free(new_arry);
}
/* Exercise4a */
int funkchia_4a(int* arry, int n)
{
    int *help_arry, i;
    help_arry = input_array_dyn(0, n);
    for (i = 0; n > i; i++)
        help_arry[i] = 0;
    for (i = 0; n > i; i++)
        ++help_arry[arry[i]];
    for (i = 0; n > i; i++)
        --help_arry[i];
    for (i = 0; n > i; i++)
        if (help_arry[i] != 0)
            return 0;
    return 1;
    free(help_arry);
}
void Ex4a()
{
    int *arry, n, result, i, condition = 1;
    printf("please enter the size of the array\n");
    scanf("%d", &n);
    printf("please enter the objects of the array (the objects must be between 0 to size-1)\n");
    arry = input_array_dyn(1, n);
    for (i = 0; n > i; i++)
        if (arry[i] < 0 || arry[i] > n - 1)
            condition = 0;
    if (condition == 1) {
        result = funkchia_4a(arry, n);
        printf("%d\n", result);
        if (result == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    else
        printf("you did not write the objects according to the instractions\n");
    free(arry);
}
/* Exercise4b */
int funkchia_4b(int* arry, int n)
{
    int k = 0, temp;

    while (n - 1 >= k) {

        while (arry[k] == k)
            k++;

        if (k >= n)
            return 1;

        if (arry[arry[k]] == arry[k])
            return 0;

        temp = arry[arry[k]];
        arry[arry[k]] = arry[k];
        arry[k] = temp;
    }

    return 1;
}
void Ex4b()
{
    int *arry, n, result, i, condition = 1;
    printf("please enter the size of the array\n");
    scanf("%d", &n);
    printf("please enter the objects of the array\n");
    arry = input_array_dyn(1, n);
    for (i = 0; n > i; i++)
        if (arry[i] < 0 || arry[i] > n - 1)
            condition = 0;
    if (condition == 1) {
        result = funkchia_4b(arry, n);
        printf("%d\n", result);
        if (result == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    else
        printf("you did not write the objects according to the instractions\n");
    free(arry);
}
/* Exercise5 */
void Ex5()
{
    int **arry, n, result, k, i, j, condition1 = 1, condition2 = 1, condition3 = 1, condition4 = 1, condition = 1, p = 0;
    printf("plese enter the number k\n");
    scanf("%d", &k);
    printf("please enter the size of the matrix\n");
    scanf("%d", &n);
    printf("please enter the matrix (the matrix must be selected squred)\n");
    arry = input_array_dyn2(n);
    for (i = 0; n > i; i++) {
        for (j = 0; n - 1 > j; j++) {
            if (i == p && arry[i][j] > arry[i][j + 1])
                condition1 = 0;
            if (i == p && arry[i][j] < arry[i][j + 1])
                condition2 = 0;
            if (i == p && arry[j][i] > arry[j + 1][i])
                condition3 = 0;
            if (i == p && arry[j][i] < arry[j + 1][i])
                condition4 = 0;
            if ((condition1 == 0 && condition2 == 0) || (condition3 == 0 && condition4 == 0)) {
                condition = 0;
                break;
            }
            p = i;
        }
        condition1 = 1;
        condition2 = 1;
        condition3 = 1;
        condition4 = 1;
    }
    if (condition == 0)
        printf("you did not write a squard matrix\n");
    else {
        result = search(arry, n, k);
        printf("%d\n", result);
        if (result == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    for (i = 0; n > i; i++)
        free(arry[i]);
    free(arry);
}


