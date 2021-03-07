#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs == nullptr || rhs == nullptr) return;
    int t = *lhs;
    *lhs = *rhs;
    *rhs = t;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_cols < 1 || num_rows < 1) return nullptr;
    int **arr2d = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        arr2d[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_rows; j++)
        {
            arr2d[i][j] = init_value;
        }
    }
    return arr2d;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (!arr_2d_source || !arr_2d_target) return false;
    if (num_cols < 1 || num_rows < 1) return false;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    if (arr.empty()) return;
    for (int i = 0; i < arr.size() / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = t;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (!arr_begin || !arr_end) return;
    while (arr_begin < arr_end)
    {
        swap_args(arr_begin, arr_end);
        arr_begin++;
        arr_end--;
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (!arr || size < 1) return nullptr;
    int *max = arr;
    for (int i = 0; i < size; i++, arr++)
    {
        if (*arr > *max) max = arr;
    }
    return max;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> result;
    for (int n : arr)
    {
        if (n % 2 != 0) result.push_back(n);
    }
    return result;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    if (arr_a.empty() || arr_b.empty()) return {};
    vector<int> result;
    for (int a : arr_a)
    {
        for (int b : arr_b)
        {
            if (a == b) {
                bool duplicateFound = false;
                for (int i : result)
                {
                    if (i == a) {
                        duplicateFound = true;
                        break;
                    }
                }
                if (!duplicateFound) result.push_back(a);
            }
        }
    }
    return result;
}
