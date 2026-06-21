// C++ program to find maximum height pyramid
// from the given object width

#include <iostream>
using namespace std;

int MaximumHeight(int a[], int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i) {
 
        // Just checking whether ith level
        // is possible or not if possible
        // then we must have atleast
        // (i*(i+1))/2 elements in the
        // array
        long long y = (i * (i + 1)) / 2;
 
        // updating the result value
        // each time
        if (y <= n) 
            result = i;
         
        // otherwise we have exceeded n value
        else
            break;
    }
    return result;
}

int getMaxHeight(int objects[], int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        // 1 2 3 4 5 ... mid this will be the pyramid and
        // then it takes 1+2+3+4+5+...+mid elements atleast
        int reqElements = (mid * (mid + 1)) / 2;
        if (reqElements <= n) {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

// Driver Program
int main()
{
    int boxes[] = { 10, 20, 30, 50, 60, 70 };
    int n = sizeof(boxes) / sizeof(boxes[0]);
    cout << getMaxHeight(boxes, n) << endl;
    return 0;
}

// This code is contributed by Susobhan Akhuli