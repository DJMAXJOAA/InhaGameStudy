class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        queue<int> que;
        vector<vector<int>> ans;
        vector<int> part;
        int index = 0;
        bool isFinish = false;

        int k = intervals.size();

        if (k == 0)
        {
            ans.push_back(newInterval);
            return ans;
        }

        for (int i = 0; i < k; i++)
        {
            que.push(intervals[i][0]);
            que.push(intervals[i][1]);
        }

        int n;

        while (!que.empty())
        {
            n = que.front();

            if (isFinish)
            {
                if (index % 2 == 0)
                {
                    part.push_back(n);
                    que.pop();

                }

                else
                {
                    part.push_back(n);
                    que.pop();
                    ans.push_back(part);
                    part = {};
                }

                index++;

                continue;
            }

            if (n < newInterval[0])
            {
                part.push_back(n);
                que.pop();

                if (index % 2)
                {
                    ans.push_back(part);
                    part = {};
                }

                index++;
            }

            else
            {

                if (index % 2) //사이에 있다
                {
                    while (n <= newInterval[1])
                    {
                        que.pop();
                        index++;
                        if (que.empty())
                        {
                            part.push_back(newInterval[1]);
                            ans.push_back(part);
                            part = {};
                            isFinish = true;
                            break;
                        }

                        n = que.front();
                    }
                }

                else // 새로운 영역
                {
                    part.push_back(newInterval[0]);

                    while (n <= newInterval[1])
                    {
                        que.pop();
                        index++;
                        if (que.empty())
                        {
                            part.push_back(newInterval[1]);
                            ans.push_back(part);
                            part = {};
                            isFinish = true;
                            break;
                        }

                        n = que.front();
                    }

                }

                if (!que.empty())
                {
                    if (index % 2)
                    {
                        part.push_back(n);
                        que.pop();
                        index++;
                    }

                    else
                    {
                        part.push_back(newInterval[1]);
                    }

                    ans.push_back(part);
                    part = {};
                    isFinish = true;
                }

            }

        }

        if (isFinish == false)
        {
            ans.push_back(newInterval);
        }


        return ans;
    }

};