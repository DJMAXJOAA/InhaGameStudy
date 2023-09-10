[7���� 2��] / Find Median from Data Stream / 37�� / https://leetcode.com/problems/find-median-from-data-stream/

[���� ����]
��� �˰��� = �ΰ��� �켱���� ť�� �߾Ӱ� ã�� (�ּ���, �ִ���)
1. ¦���� ��쿡 less(�ִ���), Ȧ���� ��쿡 more(�ּ���)�� push
2. �켱���� ť�� �����ϱ� ���� �ٸ� ���� top()���� ���ؼ�, �߾Ӱ��� ����

[������]
1.  ���� ���� �ѵ� double() ������ �ʿ� ���� -> �� 2.0���� ������ double�� ��ȯ��

[�ٸ� Ǯ�� ���]
1. ���� ���� Ʈ��(Balanced Binary Search Tree) -> AVL Ʈ��

// Time taken : 17 m 1 s
// Runtime 278ms
// Beats 66.55 % of users with C++
// Memory 116.86MB
// Beats 70.61 % of users with C++

class MedianFinder {
private:
    priority_queue<int, vector<int>> less;
    priority_queue<int, vector<int>, greater<int>> more;

    int size;

public:
    MedianFinder()
        : less{}
        , more{}
        , size(0)
    {

    }

    void addNum(int num)
    {
        if (size == 0)
        {
            less.push(num);
            size++;
            return;
        }

        if (size % 2 == 0)
        {
            if (more.top() > num)
            {
                less.push(num);
            }
            else
            {
                less.push(more.top());
                more.pop();
                more.push(num);
            }
        }
        else
        {
            if (less.top() <= num)
            {
                more.push(num);
            }
            else
            {
                more.push(less.top());
                less.pop();
                less.push(num);
            }
        }
        size++;
    }

    double findMedian()
    {
        if (size % 2 == 0)
        {
            return double((less.top() + more.top()) / 2.0);
        }
        else
        {
            return less.top();
        }
    }
};

// [�ٸ� Ǯ�� ���]
// 1. ���� ���� Ʈ��(Balanced Binary Search Tree) -> AVL Ʈ��

// ��尡 �������� ����ǰ� �򸮴°��� �����ϱ� ���� ȸ���� ���� ������ ����
// ������ ���� ���̰� 1 �̻� ���� �ʰ� ��

// �ش� ������ �켱���� ť�� ����ϴ°� �����ϰ� ȿ������
// AVL Ʈ���� �켱���� ť�� ����ϴ� ����� �ð� ���⵵�� ����(�̷������� ������ �����ϴ�)

// ���� ���� Ʈ���� ����ϸ� �߰����� �ٷ� �� �� ����
// �׸��� �� �ϳ��� ����Ʈ���� ����ϰ� ��
// ������ ������ �����ϴϱ� ���߰��ϰ� ���Ÿ� �׳� �켱���� ť�� ȿ�����ϵ�

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;     // Ʈ�� ����� ���(���� ����?)
    int size;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1), size(1) {}
};

class MedianFinder {
private:
    TreeNode* root = nullptr;

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return node->height;
    }

    int getSize(TreeNode* node) {
        if (!node) return 0;
        return node->size;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T3 = x->right;

        x->right = y;
        y->left = T3;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        y->size = getSize(y->left) + getSize(y->right) + 1;
        x->size = getSize(x->left) + getSize(x->right) + 1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        x->size = getSize(x->left) + getSize(x->right) + 1;
        y->size = getSize(y->left) + getSize(y->right) + 1;

        return y;
    }

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);

        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->size = 1 + getSize(node->left) + getSize(node->right);

        int balance = getHeight(node->left) - getHeight(node->right);

        if (balance > 1 && val < node->left->val) return rightRotate(node);
        if (balance < -1 && val > node->right->val) return leftRotate(node);
        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    int kthSmallest(TreeNode* node, int k) {
        int leftSize = getSize(node->left);
        if (k <= leftSize) return kthSmallest(node->left, k);
        else if (k == leftSize + 1) return node->val;
        else return kthSmallest(node->right, k - leftSize - 1);
    }

public:
    void addNum(int num) {
        root = insert(root, num);
    }

    double findMedian() {
        int totalSize = getSize(root);
        if (totalSize % 2 == 1) {
            return kthSmallest(root, totalSize / 2 + 1);
        }
        else {
            return (kthSmallest(root, totalSize / 2) + kthSmallest(root, totalSize / 2 + 1)) / 2.0;
        }
    }
};