class Solution
{

public:
    int characterReplacement(string s, int k)
    {
        int ans = 0;
        int temp = 0; // compare number
        int times = k;
        int startIndex = 0;
        int n = s.size();
        bool frontFinish = false; // is front of startIndex already finish?

        while (startIndex < n)
        {
            for (int i = startIndex - 1; i >= 0; i--) // start at front of index 
            {
                if (s[startIndex] != s[i]) //compare char
                {
                    times--;
                    temp++;
                    if (times < 0) // k is finish
                    {
                        ans = max(ans, temp);
                        times = k;
                        temp = 0;
                        startIndex++;
                        frontFinish = true;
                        break;
                    }

                }

                else
                {
                    temp++;
                }
            }

            int j;

            if (!frontFinish) // can not go if front already use all k
            {
                for (j = startIndex + 1; j < n; j++) //after the index
                {
                    if (s[startIndex] != s[j])
                    {
                        times--;
                        temp++;
                        if (times < 0)
                        {
                            ans = max(ans, temp);
                            times = k;
                            temp = 0;
                            startIndex++;
                            break;
                        }

                    }

                    else
                    {
                        temp++;
                    }

                }


                if (j == n) // end of the string include substring
                {
                    ans = max(ans, temp + 1);
                    break;
                }
            }

            else
            {
                frontFinish = false;
            }
        }

        return ans;
    }
};