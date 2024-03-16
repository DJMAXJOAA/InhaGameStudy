[BOJ] ������ ���̱� / ���2 / /https://www.acmicpc.net/problem/17136
### ���Ʈ����, ��Ʈ��ŷ, DFS
1. ��Ʋ ���� ��� �ڵ��׽�Ʈ ������ Ǯ���� ������ ����� ������ ������ Ǯ� ����
2. ��Ʈ��ŷ�� �ͼ������ٰ� �����ߴµ�, �� �� Ǯ����߰���
3. ��Ʈ��ŷ�� ������ �����ϰ� ���� �����Ͽ� visited ó������ ����, �̹� �־��� �迭�� üũ�ϱ�
4. C#�� �ڵ��׽�Ʈ�� ���� �غ� �� �ؾ� �ҵ� (�Է�ó������ �� �����ŷ���)

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
    // ���� Ž���� ��ģ ��쿡 ���� ���� �ּҰ� ��
    if (x > N - 1 && y >= N - 1)
    {
        answer = Math.Min(answer, cnt);
        return;
    }
    // ���� Ž�� ���� ���� ������ ũ�� ����ġ��
    if (cnt >= answer)
    {
        return;
    }
    // ������ Ž���� �Ϸ��Ұ�� ���� �ø��� ���� ó������ �ٽ� Ž��
    if (x > N - 1)
    {
        DFS(0, y + 1, cnt);
        return;
    }
    // �ش� ��ġ�� ��ƼĿ�� �ִ��� ������ üũ
    if (grid[y, x] == 1)
    {
        // 5������ ��ƼĿ�� ���� �� �ִ��� üũ
        for (int i = 5; i >= 1; i--)
        {
            // ��ƼĿ�� ������ �ִ��� + ���� �� �ִ���?
            if (paper[i] > 0 && CheckRange(x, y, i) && CanAttach(x, y, i))
            {
                // ��Ʈ��ŷ + ����
                paper[i]--;
                AttachSticker(x, y, i, 0);
                DFS(x + i, y, cnt + 1);
                AttachSticker(x, y, i, 1);
                paper[i]++;
            }
        }
    }
    // ��ƼĿ�� ���� �� ���ٸ�, ���� ĭ���� �Ѿ��
    else
    {
        DFS(x + 1, y, cnt);
    }
}