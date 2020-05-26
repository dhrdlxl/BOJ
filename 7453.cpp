#include <iostream>
#include <algorithm>
using namespace std;

const int ALPHABET_SIZE = 4;

struct Range
{
    int lower;
    int upper;
};

long long AB[16000000];
long long CD[16000000];

void Bound(const int &size, const long long &target, Range *bound)
{
    int mid, start, end;
    start = 0;
    end = size;

    while (start < end) // LowerBound
    {
        mid = (end + start) / 2;
        if (target <= CD[mid])
        {
            end = mid;
        }
        else if (CD[mid] < target)
        {
            start = mid + 1;
        }
    }
    bound->lower = end;

    start = 0;
    end = size;
    while (start < end) // UpperBound
    {
        mid = (end + start) / 2;
        if (target < CD[mid])
        {
            end = mid;
        }
        else if (CD[mid] <= target)
        {
            start = mid + 1;
        }
    }
    bound->upper = end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int arr[ALPHABET_SIZE][4000];

    cin >> n;

    for (int index = 0; index < n; index++)
    {
        for (int alphabet = 0; alphabet < ALPHABET_SIZE; alphabet++)
        {
            cin >> arr[alphabet][index];
        }
    }

    int ABSize = 0;
    int CDSize = 0;
    for (int left = 0; left < n; left++)
    {
        for (int right = 0; right < n; right++)
        {
            AB[ABSize++] = arr[0][left] + arr[1][right];
            CD[CDSize++] = arr[2][left] + arr[3][right];
        }
    }

    sort(CD, CD + CDSize);

    Range range;
    long long answer = 0;
    for (int index = 0; index < ABSize; index++)
    {
        Bound(CDSize, (-1 * AB[index]), &range);
        answer += range.upper - range.lower;
    }

    cout << answer;
    return 0;
}