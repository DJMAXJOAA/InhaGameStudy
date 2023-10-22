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
    // 트리를 하나의 문자열로 인코딩합니다. (전위 순회 방식 사용)
    string serialize(TreeNode* root) {
        if (!root) return "n,";  // 1. 기본 케이스: 노드가 null인 경우 "n,"을 반환합니다.

        // 2. 현재 노드의 값을 직렬화한 후, 왼쪽과 오른쪽 자식을 직렬화합니다.
        // 전위 순회 방식: (루트, 왼쪽, 오른쪽)
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // 인코드된 데이터를 트리로 디코딩합니다.
    TreeNode* deserialize(string data) {
        stringstream ss(data);  // 3. 직렬화된 문자열을 파싱하기 위해 stringstream을 사용합니다.

        // 4. 트리를 구축하기 위해 재귀적인 헬퍼 함수를 호출합니다.
        return deserializeHelper(ss);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        getline(ss, val, ',');  // 5. stringstream에서 다음 값을 파싱합니다 (콤마까지).

        if (val == "n") return nullptr;  // 6. 기본 케이스: 파싱된 값이 "n"인 경우 null 포인터를 반환합니다.

        // 7. 파싱된 값을 가진 새로운 TreeNode를 생성합니다.
        TreeNode* root = new TreeNode(stoi(val));

        // 8. 왼쪽과 오른쪽 서브트리를 재귀적으로 구축합니다.
        // (직렬화에서 전위 순회를 사용했으므로, 여기서의 순서도 일치합니다)
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        // 9. 서브트리와 함께 구성된 트리 노드를 반환합니다.
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
