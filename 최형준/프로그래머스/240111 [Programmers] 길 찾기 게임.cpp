[Programmers] 길 찾기 게임 / Lv.3 / https://school.programmers.co.kr/learn/courses/30/lessons/42892
1. 우선순위 큐는 구조체를 선언해서 operator()로 비교해서 특정 조건 비교 방법 외우기
2. 큐를 pop()시키면서 트리를 구축하는 과정 확인해두기

#include <string>
#include <vector>
#include <queue>

using namespace std;
struct Node
{
    int val;
    int x, y;
    Node* left;
    Node* right;
    Node(int val, int x, int y) : val(val), x(x), y(y), left(nullptr), right(nullptr) {}
};
struct cmp
{
    bool operator()(Node* a, Node* b)
    {
        if (a->y == b->y)
        {
            return a->x > b->x;
        }
        return a->y < b->y;
    }
};
priority_queue<Node*, vector<Node*>, cmp> q;
void PreOrder(vector<int>& v, Node* node)
{
    if (node == nullptr) return;
    v.push_back(node->val);
    PreOrder(v, node->left);
    PreOrder(v, node->right);
}
void PostOrder(vector<int>& v, Node* node)
{
    if (node == nullptr) return;
    PostOrder(v, node->left);
    PostOrder(v, node->right);
    v.push_back(node->val);
}
void InsertNode(Node*& current, Node* newNode)
{
    if (current == nullptr) {
        current = newNode;
    }
    else {
        if (newNode->x < current->x) {
            InsertNode(current->left, newNode);
        }
        else {
            InsertNode(current->right, newNode);
        }
    }
}
void MakeTree(Node*& root, priority_queue<Node*, vector<Node*>, cmp>& q)
{
    if (!q.empty())
    {
        root = q.top();
        q.pop();
        while (!q.empty())
        {
            Node* newNode = q.top();
            q.pop();
            InsertNode(root, newNode);
        }
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        q.push(new Node(i + 1, x, y));
    }
    Node* head = nullptr;
    MakeTree(head, q);

    vector<int> pre, post;
    PreOrder(pre, head);
    PostOrder(post, head);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}