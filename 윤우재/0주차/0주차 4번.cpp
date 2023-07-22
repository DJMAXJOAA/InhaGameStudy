
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };


class Solution {
public:
    Node* start;
    bool visited[101] = {0};
    Node* nodes[101] = {nullptr};
    
    void DFS(Node* node)
    {
        start = new Node(1);
        Node* ref = node;
        Node* cur = start;

        vector<Node*> refStack;
        vector<Node*> curStack;
        
        refStack.push_back(ref);
        curStack.push_back(cur);
        nodes[1] = cur;

        while (1)
        {
            if(!visited[cur->val])
            {
                for (int i = 0; i < ref->neighbors.size(); i++)
                {
                    if(nodes[ref->neighbors[i]->val] == nullptr)
                    {
                        Node* newNode = new Node(ref->neighbors[i]->val);
                        nodes[newNode->val] = newNode;
                        //newNode->neighbors.push_back(cur);
                        cur->neighbors.push_back(newNode); 
                        //visited[ref->neighbors[i]->val] = true;
                    }
                    else
                        cur->neighbors.push_back(nodes[ref->neighbors[i]->val]);
                }
            }
            
            visited[cur->val] = true;
            
            bool noNeighbor = true;
           
            //인접 노드의 방문 여부 확인
            //방문하지 않았다면 스택에 입력
            for(int i = 0; i<cur->neighbors.size();i++)
            {
                if (!visited[cur->neighbors[i]->val])
                {
                    noNeighbor = false;
                    refStack.push_back(ref->neighbors[i]);
                    curStack.push_back(cur->neighbors[i]);
                    break;
                }
            }

            
            //주변에 방문하지 않은 노드가 없다면 스택에서 pop
            if(noNeighbor)
            {
                refStack.pop_back();
                curStack.pop_back();
            }    
            
            //스택이 비지 않았다면 스택의 마지막 요소 가져와서 거기로 이동
            if(!refStack.empty())
            {
                ref = refStack.back();
                cur = curStack.back();
            }
            else
                break;
        }
    }
    Node* cloneGraph(Node* node)
    {
        if(node != nullptr)
        {
            start = new Node(node->val);
            DFS(node);
        }
        else 
            start = nullptr;
        
        return start;
    }
};