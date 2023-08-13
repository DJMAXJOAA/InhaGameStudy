//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};

 // >> 비주얼 스튜디오로는 되는 버전 =============================================
struct cmp
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, cmp> temp;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* node = lists[i];
            while (node != nullptr)
            {
                temp.push(node);
                node = node->next;
            }
        }

        if (temp.empty())
            return NULL;

        ListNode* result = temp.top();
        ListNode* ptrFront = result;
        temp.pop();

        while (!temp.empty())
        {
            ListNode* add = temp.top();
            result->next = add;
            result = add;
            temp.pop();
        }

        return ptrFront;
    }
};
// << 비주얼 스튜디오로는 되는 버전 =============================================

// >> 제출 버전 ===============================================================
struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;

        priority_queue<int, vector<int>, cmp> temp;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* node = lists[i];
            while (node != nullptr)
            {
                temp.push(node->val);
                node = node->next;
            }
        }

        if (temp.empty())
            return NULL;

        ListNode* result = new ListNode(temp.top());
        ListNode* ptrFront = result;
        temp.pop();

        while (!temp.empty())
        {
            ListNode* add = new ListNode(temp.top());
            result->next = add;
            result = add;
            temp.pop();
        }

        return ptrFront;
    }
};
// << 제출 버전 ===============================================================