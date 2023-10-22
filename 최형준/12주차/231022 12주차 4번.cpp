[12주차 4번] / Serialize and Deserialize Binary Tree / 1시간 20분 / https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

[문제 접근]
너비 우선 탐색(BFS) : O(n), O(n)
1. 직렬화 : BFS를 이용해서 레벨별 순회로 문자열 직렬화
2. 역직렬화 : 문자열을 파싱해서 배열에 저장하고, 개행 문자를 만나면 부모 노드에 직접 연결

[개선점]
1. ostringstream, istringstream 문자열 파싱 함수로 문자열에 '+=' 연산을 생략 가능함
   ('+=' 연산은 매번 새로운 문자열을 생성하게 되어서 오버헤드가 발생된다네요)
2. \n 개행문자 체크를 할 필요 없이 ','만 사용해서 구분해도 됌
3. 불필요한 null 체크를 간결하게 개선할 수 있음

[다른 풀이 방법]
1. DFS 전위순회 직렬화, 후위순회 역직렬화 : O(n), O(n)
2. 리팩토링하여 개선된 BFS : O(n), O(n)

Time taken : 48 m 17 s
Runtime 33ms
Beats 52.83 % of users with C++
Memory 31.11MB
Beats 49.33 % of users with C++

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    class Codec {
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string result = "";

            if (root == nullptr)
            {
                return result;
            }

            queue<TreeNode*> que;
            que.push(root);

            int nullCheck = 0;
            int size = que.size();
            while (!que.empty())
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode* temp = que.front();
                    que.pop();

                    if (temp != nullptr)
                    {
                        result += to_string(temp->val) + ",";

                        que.push(temp->left);
                        que.push(temp->right);
                    }
                    else
                    {
                        result += "n,";
                    }
                }

                size = que.size();
                result += '\n';
            }

            cout << result;
            return result;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            TreeNode* root = nullptr;
            if (data.empty())
            {
                return root;
            }

            string val = "";
            queue<TreeNode*> parentNodes{};
            queue<string> nodeVals;

            int i = 0;
            for (; i < data.size(); i++)
            {
                if (data[i] == '\n')
                {
                    root = new TreeNode(stoi(val));
                    parentNodes.push(root);
                    val = "";
                    i++;

                    break;
                }
                else
                {
                    val += data[i];
                }
            }

            for (; i < data.size(); i++)
            {
                if (data[i] == ',')
                {
                    nodeVals.push(val);
                    val = "";
                }
                else if (data[i] == '\n')
                {
                    int queueSize = parentNodes.size();
                    for (int j = 0; j < queueSize; j++)
                    {
                        TreeNode* parent = parentNodes.front();
                        parentNodes.pop();

                        TreeNode* temp = nullptr;
                        if (nodeVals.front() != "n")
                        {
                            temp = new TreeNode(stoi(nodeVals.front()));
                            parent->left = temp;
                            parentNodes.push(temp);
                        }
                        nodeVals.pop();
                        if (nodeVals.front() != "n")
                        {
                            temp = new TreeNode(stoi(nodeVals.front()));
                            parent->right = temp;
                            parentNodes.push(temp);
                        }
                        nodeVals.pop();
                    }
                    val = "";
                }
                else
                {
                    val += data[i];
                }
            }

            return root;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

[다른 풀이 방법]
DFS를 사용하는 직렬화 및 역직렬화 O(n), O(n)
1. DFS를 사용하는 코드가 정석적인 방법에 해당함
2. BFS는 레벨별로 트리를 순회 -> 직관적인 문자열 생성
3. DFS는 재귀 구조로 코드가 간결해짐

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "n";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }

    TreeNode* helper(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "n") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = helper(ss);
        root->right = helper(ss);
        return root;
    }
};

[다른 풀이 방법]
리팩토링하여 개선된 BFS : O(n), O(n)
1. ostringstream, istringstream 문자열 파싱 함수로 문자열에 '+=' 연산을 생략 가능함
   ('+=' 연산은 매번 새로운 문자열을 생성하게 되어서 오버헤드가 발생된다네요)
2. \n 개행문자 체크를 할 필요 없이 ','만 사용해서 구분해도 됌
3. 불필요한 null 체크를 간결하게 개선할 수 있음

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        ostringstream out;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();

            if (curr) {
                out << curr->val << ',';
                que.push(curr->left);
                que.push(curr->right);
            }
            else {
                out << "n,";
            }
        }

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream in(data);
        string val;
        getline(in, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* parent = que.front();
            que.pop();

            if (getline(in, val, ',') && val != "n") {
                parent->left = new TreeNode(stoi(val));
                que.push(parent->left);
            }

            if (getline(in, val, ',') && val != "n") {
                parent->right = new TreeNode(stoi(val));
                que.push(parent->right);
            }
        }

        return root;
    }
};
