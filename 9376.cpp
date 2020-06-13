#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

const int MAX_SIZE = 102;
const int MAX_DEQUE = MAX_SIZE * MAX_SIZE;

struct Pos{
public:
    int y;
    int x;
    Pos(){}
    Pos(int m_y, int m_x):y(m_y), x(m_x){}
};

template <typename T>
class Deque
{
private:
    T deque[MAX_DEQUE];
    int begin;
    int end;
public:
    Deque():begin(0), end(0){}
    
    bool empty()
    {
        if(begin == end) return true;
        return false;
    }
    T front()
    {
        assert(!empty() && "Deque empty");
        if(!empty())
        {
            return deque[begin];
        }
    }
    T back()
    {
        assert(!empty() && "Deque empty");
        if(!empty())
        {
            return deque[(end - 1 + MAX_DEQUE) % MAX_DEQUE];
        }
    }
    void push_front(T inputValue)
    {
        begin = (begin - 1 + MAX_DEQUE) % MAX_DEQUE;
        deque[begin] = inputValue;
    }
    void push_back(T inputValue)
    {
        deque[end] = inputValue;
        end = (end + 1) % MAX_DEQUE;
    }
    void pop_front()
    {
        if(!empty())
        {
            begin = (begin + 1) % MAX_DEQUE;
        }
    }
    void pop_back()
    {
        if(!empty())
        {
            end = (end - 1 + MAX_DEQUE) % MAX_DEQUE;
        }
    }
    
};

int dY[4] = {0, 0, 1, -1};
int dX[4] = {1, -1, 0, 0};

void bfs(char (&board)[MAX_SIZE][MAX_SIZE], Pos start, 
         const int &h, const int &w, int (*mask)[MAX_SIZE])
{
    Deque<Pos> dq;
    dq.push_front(start);
    
    mask[start.y][start.x] = 0;
    
    while(!dq.empty())
    {
        int y = dq.front().y;
        int x = dq.front().x;
        dq.pop_front();
        
        for(int index = 0; index < 4; index++)
        {
            int m_y = y + dY[index];
            int m_x = x + dX[index];
            
            if(m_y < 0 || m_y > h+1 || m_x < 0 || m_x > w+1)
                continue;
            if(board[m_y][m_x] == '*' || mask[m_y][m_x] != -1)
                continue;
            else if(board[m_y][m_x] == '.')
            {
                mask[m_y][m_x] = mask[y][x];
                dq.push_front(Pos(m_y, m_x));
            }
            else if(board[m_y][m_x]=='#')
            {
                mask[m_y][m_x] = mask[y][x] + 1;
                dq.push_back(Pos(m_y, m_x));
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int h, w;
        cin >> h >> w;
        
        char board[MAX_SIZE][MAX_SIZE];
        for(int index = 0; index < MAX_SIZE ; index++)
        {
            memset(board[index], '.', sizeof(char)* MAX_SIZE);
        }
        
        char ch;
        Pos prisoner1, prisoner2;
        bool check = true;
        for(int row = 1 ; row <= h ; row++)
        {
            for(int col = 1 ; col <= w ; col++)
            {
                cin >> board[row][col];
                if(board[row][col] == '$')
                {
                    board[row][col] = '.';
                    if(check)
                    {
                        prisoner1.y = row;
                        prisoner1.x = col;
                        check = false;
                    }
                    else
                    {
                        prisoner2.y = row;
                        prisoner2.x = col;
                    }
                }
            }
        }
        
        int prisoner1Mask[MAX_SIZE][MAX_SIZE];
        int prisoner2Mask[MAX_SIZE][MAX_SIZE];
        int boardMask[MAX_SIZE][MAX_SIZE];
        
        for(int index = 0 ; index < MAX_SIZE ; index++)
        {
            memset(prisoner1Mask[index], -1, sizeof(int)*MAX_SIZE);
            memset(prisoner2Mask[index], -1, sizeof(int)*MAX_SIZE);
            memset(boardMask[index], -1, sizeof(int)*MAX_SIZE);
        }
        
        bfs(board, prisoner1, h, w, prisoner1Mask);
        bfs(board, prisoner2, h, w, prisoner2Mask);
        bfs(board, Pos(0,0), h, w, boardMask);
        
        int answer = MAX_SIZE * MAX_SIZE;
        for(int row = 0 ; row < h + 1 ; row++)
        {
            for(int col = 0 ; col < w + 1 ; col++)
            {
                boardMask[row][col] += prisoner1Mask[row][col] + prisoner2Mask[row][col];
                if(board[row][col] == '#')
                {
                    boardMask[row][col] -=2;
                }
                
                if(boardMask[row][col] >= 0  && answer > boardMask[row][col])
                    answer = boardMask[row][col];
            }
        }
        
        cout<< answer << '\n';
    }
}