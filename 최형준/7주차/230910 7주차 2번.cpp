[7주차 2번] / Find Median from Data Stream / 37분 / https://leetcode.com/problems/find-median-from-data-stream/

[문제 접근]
사용 알고리즘 = 두개의 우선순위 큐로 중앙값 찾기 (최소힙, 최대힙)
1. 짝수인 경우에 less(최대힙), 홀수인 경우에 more(최소힙)에 push
2. 우선순위 큐에 대입하기 전에 다른 힙의 top()값을 비교해서, 중앙값을 유지

[개선점]
1.  딱히 없긴 한데 double() 연산은 필요 없음 -> 걍 2.0으로 나누면 double로 반환됨

[다른 풀이 방법]
1. 균형 이진 트리(Balanced Binary Search Tree) -> AVL 트리

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

// [다른 풀이 방법]
// 1. 균형 이진 트리(Balanced Binary Search Tree) -> AVL 트리

// 노드가 한쪽으로 편향되게 쏠리는것을 방지하기 위해 회전을 통해 균형을 맞춤
// 노드들의 높이 차이가 1 이상 나지 않게 됨

// 해당 문제는 우선순위 큐를 사용하는게 간단하고 효과적임
// AVL 트리와 우선순위 큐를 사용하는 방법의 시간 복잡도는 같다(이론적으로 성능이 동일하다)

// 균형 이진 트리를 사용하면 중간값을 바로 알 수 있음
// 그리고 단 하나의 이진트리만 사용하게 됨
// 하지만 구현이 복잡하니까 어중간하게 쓸거면 그냥 우선순위 큐가 효과적일듯

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;     // 트리 노드의 노드(현재 몇층?)
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