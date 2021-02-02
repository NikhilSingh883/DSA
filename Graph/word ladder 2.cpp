    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>res;       
        unordered_set<string>uset(wordList.begin(), wordList.end());
        
        queue<vector<string>>pathes;        
        pathes.push({beginWord});
        
        bool found = false;
        while(!pathes.empty())
        {
            int n = pathes.size();
            unordered_set<string>visited;

            if(found == true) break;

            for(int i = 0; i < n; i++)
            {
                vector<string>path = pathes.front();
                pathes.pop();              
                
                string cur = path.back();
                
                if(cur == endWord)
                {
                    res.push_back(path);
                    found = true;
                }
                for(int i = 0; i < cur.size(); i++)
                {
                    string curorg = cur;
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        cur[i] = c;
                        if(uset.find(cur) != uset.end())
                        {
                            visited.insert(cur);
                            vector<string>newpath = path;
                            newpath.push_back(cur);
                            pathes.push(newpath);
                        }
                    }
                    cur = curorg;                  
                }              
                                
            }
            for(auto it : visited)
            {
                uset.erase(it);
            }

        }
        
        return res;
    }