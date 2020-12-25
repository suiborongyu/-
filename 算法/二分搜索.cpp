#include <iostream>
using namespace std;
#include <vector>

/*二分搜索是一种常见的搜索方法，可使时间复杂度较低到O(nlogn)*/

//普通版二分搜索
template <typename T>
int binary_sort(vector<T> &v, T val)
{
    int left = 0, right = v.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; //这样可防止溢出
        if (v[mid] == val)
            return mid;
        if (v[mid] < val)
            left = mid + 1;
        if (v[mid] > val)
            right = mid - 1;
    }
    return -1;
}

//取最左端的二分搜索
template <typename T>
int binary_sort(vector<T> &v, T val)
{
    int left = 0, right = v.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2; //这样可防止溢出
        if (v[mid] == val)
            right = mid - 1;
        if (v[mid] < val)
            left = mid + 1;
        if (v[mid] > val)
            right = mid - 1;
    }
    //检查是否越界
    if (left > v.size() - 1 || v[left] != val)
        return -1;
    return left;
}

//取最右端的二分搜索
template <typename T>
int binary_sort(vector<T> &v, T val)
{
    int left = 0, right = v.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2; //这样可防止溢出
        if (v[mid] == val)
            left = mid + 1;
        if (v[mid] < val)
            left = mid + 1;
        if (v[mid] > val)
            right = mid - 1;
    }
    //检查是否越界
    if (right - 1 < 0 || v[right - 1] != val)
        return -1;
    return right - 1;
}

int main()
{
    return 0;
}