[BOJ] 색종이 붙이기 / 골드2 / /https://www.acmicpc.net/problem/17136
### 브루트포스, 백트래킹, DFS
1. 이틀 전에 기업 코딩테스트 문제로 풀었던 문제와 비슷한 유형의 문제라서 풀어본 문제
2. 백트래킹에 익숙해졌다고 생각했는데, 좀 더 풀어봐야겠음
3. 백트래킹시 변수를 선언하고 복사 생성하여 visited 처리하지 말고, 이미 주어진 배열로 체크하기
4. C#로 코딩테스트에 대해 준비를 더 해야 할듯 (입력처리에서 좀 버벅거렸음)

const int N = 10;
int[,] grid = new int[N, N];
int[] paper = { 0, 5, 5, 5, 5, 5 };
int answer = int.MaxValue;
// :: >>
for (int i = 0; i < N; i++)
{
    var input = Console.ReadLine()!.Split(' ');
    for (int j = 0; j < N; j++)
    {
        grid[i, j] = int.Parse(input[j]);
    }
}
DFS(0, 0, 0);
answer = answer == int.MaxValue ? -1 : answer;
Console.WriteLine(answer);
// :: <<
bool CheckRange(int x, int y, int size)
{
    return x + size <= N && y + size <= N;
}
bool CanAttach(int x, int y, int size)
{
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (grid[i, j] != 1)
                return false;
        }
    }
    return true;
}
void AttachSticker(int x, int y, int size, int value)
{
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            grid[i, j] = value;
        }
    }
}
void DFS(int x, int y, int cnt)
{
    // 완전 탐색을 마친 경우에 기존 값과 최소값 비교
    if (x > N - 1 && y >= N - 1)
    {
        answer = Math.Min(answer, cnt);
        return;
    }
    // 현재 탐색 값이 기존 값보다 크면 가지치기
    if (cnt >= answer)
    {
        return;
    }
    // 열에서 탐색을 완료할경우 행을 늘리고 열의 처음부터 다시 탐색
    if (x > N - 1)
    {
        DFS(0, y + 1, cnt);
        return;
    }
    // 해당 위치에 스티커가 있는지 없는지 체크
    if (grid[y, x] == 1)
    {
        // 5가지의 스티커를 붙일 수 있는지 체크
        for (int i = 5; i >= 1; i--)
        {
            // 스티커를 가지고 있는지 + 붙일 수 있는지?
            if (paper[i] > 0 && CheckRange(x, y, i) && CanAttach(x, y, i))
            {
                // 백트래킹 + 복원
                paper[i]--;
                AttachSticker(x, y, i, 0);
                DFS(x + i, y, cnt + 1);
                AttachSticker(x, y, i, 1);
                paper[i]++;
            }
        }
    }
    // 스티커를 붙일 수 없다면, 다음 칸으로 넘어가기
    else
    {
        DFS(x + 1, y, cnt);
    }
}