#include <iostream>

using namespace std;

const int MAX_LAN = 10001;

long long getLanCount(int (&lans)[MAX_LAN], int &K, long long &length)
{
    long long count = 0;
    for (int index = 0; index < K; index++)
    {
        count += (lans[index] / length);
    }

    return count;
}

int upperBound(int (&lans)[MAX_LAN], int &K, int &target, int &maxK)
{
    long long left, right, mid, answer;
    left = 1;
    right = maxK;

    while (left <= right)
    {
        mid = (left + right) / 2;
        long long count = getLanCount(lans, K, mid);
        if(count < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            answer = mid;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    int maxK = 0;
    int lans[MAX_LAN];
    for (int index = 0; index < K; index++)
    {
        cin >> lans[index];
        if (maxK < lans[index])
            maxK = lans[index];
    }
    
    cout << upperBound(lans, K, N, maxK) << '\n';

    return 0;
}