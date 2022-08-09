
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string p)
    {
        vector<string> res;
        for (string w : words)
        {
            map<char, char> mp;
            int i;
            for (i = 0; i < w.length(); i++)
            {
                if (mp.count(w[i]) == 0)
                {
                    mp[w[i]] = p[i];
                }
                else
                {
                    if (mp[w[i]] ! = p[i])
                        return false;
                }
            }

            if (i == w.length())
                res.push_back(w);
        }
        return res;
    }
};
