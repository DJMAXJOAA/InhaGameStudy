[12���� 4��] / Serialize and Deserialize Binary Tree / 1�ð� 20�� / https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

[���� ����]
�ʺ� �켱 Ž��(BFS) : O(n), O(n)
1. ����ȭ : BFS�� �̿��ؼ� ������ ��ȸ�� ���ڿ� ����ȭ
2. ������ȭ : ���ڿ��� �Ľ��ؼ� �迭�� �����ϰ�, ���� ���ڸ� ������ �θ� ��忡 ���� ����

[������]
1. ostringstream, istringstream ���ڿ� �Ľ� �Լ��� ���ڿ��� '+=' ������ ���� ������
   ('+=' ������ �Ź� ���ο� ���ڿ��� �����ϰ� �Ǿ ������尡 �߻��ȴٳ׿�)
2. \n ���๮�� üũ�� �� �ʿ� ���� ','�� ����ؼ� �����ص� ��
3. ���ʿ��� null üũ�� �����ϰ� ������ �� ����

[�ٸ� Ǯ�� ���]
1. DFS ������ȸ ����ȭ, ������ȸ ������ȭ : O(n), O(n)
2. �����丵�Ͽ� ������ BFS : O(n), O(n)

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

[�ٸ� Ǯ�� ���]
DFS�� ����ϴ� ����ȭ �� ������ȭ O(n), O(n)
1. DFS�� ����ϴ� �ڵ尡 �������� ����� �ش���
2. BFS�� �������� Ʈ���� ��ȸ -> �������� ���ڿ� ����
3. DFS�� ��� ������ �ڵ尡 ��������

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

[�ٸ� Ǯ�� ���]
�����丵�Ͽ� ������ BFS : O(n), O(n)
1. ostringstream, istringstream ���ڿ� �Ľ� �Լ��� ���ڿ��� '+=' ������ ���� ������
   ('+=' ������ �Ź� ���ο� ���ڿ��� �����ϰ� �Ǿ ������尡 �߻��ȴٳ׿�)
2. \n ���๮�� üũ�� �� �ʿ� ���� ','�� ����ؼ� �����ص� ��
3. ���ʿ��� null üũ�� �����ϰ� ������ �� ����

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
