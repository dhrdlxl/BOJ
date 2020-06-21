#include <iostream>

using namespace std;

long long min(long long a, long long b)
{
    return a < b ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int k;

    cin >> N >> k;

    long long left, right, answer;
    left = 1;
    right = N*N;

    while (left <= right)
    {
        long long count = 0;
        long long mid = (left + right) / 2;
        for (int index = 1; index <= N; index++)
        {
            count += min(mid / index, N);
        }
        if (count < k)
        {
            left = mid + 1;
        }
        else if (count >= k)
        {
            right = mid - 1;
            answer = mid;
        }
    }
    cout << answer;
    return 0;
}