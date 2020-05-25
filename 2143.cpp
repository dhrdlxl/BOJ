#include <iostream>
#include <algorithm>
using namespace std;

const int MAXNEWARR = 500500;
const int MAXARR = 1000;

long long NewA[MAXNEWARR], NewB[MAXNEWARR];

bool Less(long long a, long long b)
{
    return a > b ? true : false;
}
bool Greater(long long a, long long b)
{
    return a < b ? true : false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, m;
    int A[MAXARR], B[MAXARR];
    long long answer = 0;

    cin >> T >> n;
    for (int index = 0; index < n; index++)
    {
        cin >> A[index];
    }
    cin >> m;
    for (int index = 0; index < m; index++)
    {
        cin >> B[index];
    }

    int SizeOfNewA = 0;
    int SizeOfNewB = 0;
    long long sum = 0;
    for (int start = 0; start < n; start++)
    {
        sum = 0;
        for (int index = start; index < n; index++)
        {
            sum += A[index];
            NewA[SizeOfNewA] = sum;
            SizeOfNewA++;
        }
    }

    for (int start = 0; start < m; start++)
    {
        sum = 0;
        for (int index = start; index < m; index++)
        {
            sum += B[index];
            NewB[SizeOfNewB] = sum;
            SizeOfNewB++;
        }
    }

    sort(NewA, NewA + SizeOfNewA, Less);
    sort(NewB, NewB + SizeOfNewB, Greater);

    int indexA = 0, indexB = 0;
    while (indexA < SizeOfNewA && indexB < SizeOfNewB)
    {
        sum = NewA[indexA] + NewB[indexB];
        if (sum > T)
        {
            indexA++;
        }
        else if (sum < T)
        {
            indexB++;
        }
        else
        {
            long long tempA = NewA[indexA];
            long long tempB = NewB[indexB];
            long long countA = 1;
            long long countB = 1;
            while (indexA + 1 < SizeOfNewA)
            {
                indexA++;
                if (NewA[indexA] != tempA)
                {
                    indexA--;
                    break;
                }
                countA++;
            }
            while (indexB + 1 < SizeOfNewB)
            {
                indexB++;
                if (NewB[indexB] != tempB)
                {
                    indexB--;
                    break;
                }
                countB++;
            }
            indexA++;
            indexB++;
            answer += (countA * countB);
        }
    }

    cout << answer;
    return 0;
}