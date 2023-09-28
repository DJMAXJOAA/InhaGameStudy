class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        map<string, int> Anagram;
        string first = strs[0];
        sort(first.begin(), first.end());
        Anagram[first] = 0;

        vector<string> temp;
        temp.push_back(strs[0]);
        ans.push_back(vector<string>(temp));

        for (int i = 1; i < strs.size(); i++)
        {
            string temp1 = strs[i];
            sort(temp1.begin(), temp1.end());

            if (Anagram.find(temp1) != Anagram.end())
            {
                ans[Anagram[temp1]].push_back(strs[i]);
            }

            else
            {
                Anagram[temp1] = Anagram.size();
                vector<string> temp;
                temp.push_back(strs[i]);
                ans.push_back(vector<string>(temp));
            }


        }


        return ans;
    }
};

// class Solution 
// {
// public:
//     vector<string> Anagram(vector<string>& strs)
//     {
//         vector<string> ana;
//         ana.push_back(strs[0]);
//         string temp1 = strs[0];
//         sort(temp1.begin(), temp1.end());
//         strs.erase(strs.begin());

//         for(int i = 0; i < strs.size(); i++)
//         {
//             string temp2 = strs[i];
//             sort(temp2.begin(), temp2.end());

//             if(temp1 == temp2)
//             {
//                 ana.push_back(strs[i]);
//                 strs.erase(strs.begin()+i);
//                 i--;
//             }
//         }
//         return ana;
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) 
//     {
//         vector<vector<string>> ans;

//         while(!strs.empty())
//         {
//             ans.push_back(Anagram(strs));
//         }

//         return ans;
//     }
// };