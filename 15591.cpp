#include <iostream>
#include <vector>

using namespace std;

const int VIDEO_MAX = 5001;
const int COST_MAX = 1000000001;

struct videoInfo
{
public:
    int video;
    int usado;
    videoInfo() {}
    videoInfo(int m_video, int m_usado) : video(m_video), usado(m_usado) {}
};

int min(int &a, int &b)
{
    return a < b ? a : b;
}

int dfs(int &K, int &node, vector<vector<videoInfo>> &USADO, vector<bool> &mask)
{
    int answer = 0;

    for (int index = 0; index < USADO[node].size(); index++)
    {
        int video = USADO[node][index].video;
        int usado = USADO[node][index].usado;

        if (mask[video] == false)
        {
            mask[node] = true;
            if(K<=usado)
            {
                answer++;
                answer += dfs(K, video, USADO, mask);
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;

    cin >> N >> Q;

    vector<vector<videoInfo>> USADO(N + 1);
    vector<bool> mask(N + 1, false);

    int from, to, cost;
    for (int index = 0; index < N - 1; index++)
    {
        cin >> from >> to >> cost;
        USADO[from].push_back(videoInfo(to, cost));
        USADO[to].push_back(videoInfo(from, cost));
    }

    int K, V;
    for (int index = 0; index < Q; index++)
    {
        cin >> K >> V;
        for (int row = 0; row <= N; row++)
        {
            mask[row] = false;
        }
        mask[V] = true;
        cout << dfs(K, V, USADO, mask) << '\n';
    }

    return 0;
}