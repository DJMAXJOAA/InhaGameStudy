[Programmers] 이중우선순위큐 / Lv.3 / https://school.programmers.co.kr/learn/courses/30/lessons/42628
1. set.erase()시 s.rbegin은 인자로 넣을 수 없고, --end()로 마지막 요소를 지워야 한다
2. string.substr()는 특정 인덱스에서 마지막까지 다 자름

#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

void Push(int val)
{
    s.insert(val);
}
void Pop(int val)
{
    if (s.empty()) return;

    if (val == 1)
    {
        s.erase(--s.end());

    }
    if (val == -1)
    {
        s.erase(s.begin());
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
        string temp = operations[i];
        if (temp[0] == 'I')
        {
            int val = stoi(temp.substr(2));
            Push(val);
        }
        if (temp[0] == 'D')
        {
            int val = stoi(temp.substr(2));
            Pop(val);
        }
    }
    if (s.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*s.rbegin());
        answer.push_back(*s.begin());
    }

    return answer;
}