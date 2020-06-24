#include <iostream>

using namespace std;

int getPercent(long long a, long long b)
{
    return b * 100 / a;
}

int binarySearch(const int &X, const int &Y)
{
    int answer = 0;
    int target = getPercent(X, Y) + 1;
    int left, right, mid, estimatedPercent;
    left = 1;
    right = X;

    if (target >= 100)
        return -1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        estimatedPercent = getPercent((X + mid), (Y + mid));
        if (estimatedPercent < target)
        {
            left = mid + 1;
        }
        else if (target <= estimatedPercent)
        {
            right = mid - 1;
            answer = mid;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y;

    cin >> X >> Y;
    cout << binarySearch(X, Y) << '\n';

    return 0;
}