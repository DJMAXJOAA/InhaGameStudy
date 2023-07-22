/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

class Solution {
public:
	Node* cloneGraph(Node* node)
	{
		if (node == nullptr)
			return nullptr;

		queue<Node*> que;
		vector<bool> visit; // 100ĭ
		visit.resize(101);

		Node* start = new Node;
		start->val = node->val;

		map<Node*, Node*> mp;
		mp[node] = start;

		que.push(node);
		visit[node->val] = true;

		while (que.empty() == false)
		{
			Node* temp = que.front();
			que.pop(); // ť���� �������� �̸� ���
			for (auto itr = temp->neighbors.begin(); itr != temp->neighbors.end(); ++itr)
			{
				auto& value = *itr;

				if (visit[value->val] == false)
				{
					Node* add = new Node(value->val); // ���� �����ؼ� �����Ҵ�
					mp[value] = add; // ���� ���ͷ������� ��������� �Ҵ��� node ����
					que.push(value); // ť �ֱ�
					visit[value->val] = true; // �湮 ó��
				}
				mp[temp]->neighbors.push_back(mp[value]); // �̿��� �߰�
			}
		}
		return mp[node];
	}
};