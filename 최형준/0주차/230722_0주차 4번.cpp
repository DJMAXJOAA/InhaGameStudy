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
		if (node == nullptr) // 널포인트면 그대로 반환
			return nullptr;

		queue<Node*> que; // BFS 탐색을 위한 Node*형식의 큐 선언
		vector<bool> visit;
		visit.resize(101); // 방문 여부를 100칸짜리 배열에 미리 모두 false로 저장

		Node* start = new Node;
		start->val = node->val;

		map<Node*, Node*> mp;
		mp[node] = start;

		que.push(node);
		visit[node->val] = true;

		while (que.empty() == false)
		{
			Node* temp = que.front();
			que.pop(); // 큐에서 빼기전에 미리 등록
			for (auto itr = temp->neighbors.begin(); itr != temp->neighbors.end(); ++itr)
			{
				auto& value = *itr;

				if (visit[value->val] == false)
				{
					Node* add = new Node(value->val); // 값만 복사해서 동적할당
					mp[value] = add; // 현재 이터레이터의 밸류값으로 할당한 node 대입
					que.push(value); // 큐 넣기
					visit[value->val] = true; // 방문 처리
				}
				mp[temp]->neighbors.push_back(mp[value]); // 이웃만 추가
			}
		}
		return mp[node]; // 맨 처음값 반환 mp[node] = start;
	}
};