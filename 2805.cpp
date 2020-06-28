#include <iostream>

using namespace std;

const int MAX_TREE = 1000001;

int trees[MAX_TREE];

long long getCutTreeSize(long long &mid, int &N)
{
    long long sum = 0;
    int cutTree;
    for (int index = 0; index < N; index++)
    {
        cutTree = trees[index] - mid;
        if(cutTree > 0)
            sum += cutTree;
    }

    return sum;
}

long long binarySearch(int &max, long long &target, int &N)
{
    long long left, right, mid, answer;
    left = 0;
    right = max;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (getCutTreeSize(mid, N) < target)
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

    int N;
    long long M;

    cin >> N >> M;

    int maxTree = 0;
    for (int index = 0; index < N; index++)
    {
        cin >> trees[index];
        if (maxTree < trees[index])
            maxTree = trees[index];
    }

    cout << binarySearch(maxTree, M, N) << '\n';
    return 0;
}