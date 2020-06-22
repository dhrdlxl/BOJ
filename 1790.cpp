#include <iostream>

using namespace std;

int getNowPos(int number)
{
    int count = 0;

    for (int start = 1, digit = 1; start <= number; start *= 10, digit++)
    {
        int end = start * 10 - 1;

        if (end > number)
            end = number;

        count += digit * (end - start + 1);
    }

    return count;
}

int binarySearch(int &N, int &k)
{
    int answer = 0;
    int left, right, mid;
    left = 0;
    right = N;

    while (left <= right)
    {
        mid = (left + right) / 2;
        int pos = getNowPos(mid);

        if (pos < k)
        {
            left = mid + 1;
        }
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;

    cin >> N >> k;
    if (k > getNowPos(N))
    {
        cout << -1 << '\n';
    }
    else
    {
        int targetNum = binarySearch(N, k);
        int count = getNowPos(targetNum) - k;
        int answer = 0;

        for (int index = 0; index <= count; index++)
        {
            answer = targetNum % 10;
            targetNum /= 10;
        }

        cout << answer << '\n';
    }
    return 0;
}