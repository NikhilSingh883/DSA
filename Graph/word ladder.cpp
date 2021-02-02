    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>uset(wordList.begin(), wordList.end());
        
        queue<string>q;
        q.push(beginWord);
        
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int j = 0; j < n; j++)
            {
                string cur = q.front();
                q.pop();

                if(cur == endWord)
                {
                    return level+1;
                }

                for(int i = 0; i < cur.size(); i++)
                {
                    string curorig = cur;
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        cur[i] = ch;
                        if(uset.find(cur) != uset.end())
                        {
                            q.push(cur);
                            uset.erase(cur);
                        }
                    }
                    cur = curorig;
                }                
            }
            
            level ++;
        }
        
        return 0;
    }