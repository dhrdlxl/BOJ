#include <iostream>
#include <algorithm>

using namespace std;

const int MAXSIZE = 500000;

int binarySearch(int &target, int &N, int (&arr)[MAXSIZE])
{
    int left, right, mid;
    int answer = 0;
    left = 0;
    right = N;

    //lowerBound
    while (left < right)
    {
        mid = (left + right) / 2;

        if (target > arr[mid])
        {
            left = mid + 1;
        }
        else if (target <= arr[mid])
        {
            right = mid;
        }
    }
    answer = right;

    left = 0;
    right = N;
    //upperBound
    while (left < right)
    {
        mid = (left + right) / 2;

        if (target >= arr[mid])
        {
            left = mid + 1;
        }
        else if (target < arr[mid])
        {
            right = mid;
        }
    }
    answer = right - answer;

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int NCard[MAXSIZE];
    int MCard[MAXSIZE];

    cin >> N;
    for (int index = 0; index < N; index++)
    {
        cin >> NCard[index];
    }
    cin >> M;
    for (int index = 0; index < M; index++)
    {
        cin >> MCard[index];
    }

    sort(NCard, NCard + N);

    for (int index = 0; index < M; index++)
    {
        cout << binarySearch(MCard[index], N, NCard) << ' ';
    }
    cout<<'\n';
    return 0;
}