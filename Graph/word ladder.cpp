int Solution::solve(string A, string B, vector<string> &C) 
{
    queue<string>q;
    q.push(A);
    int depth = 0;
    int levelSize = 0;
    set<string>s;
    for(int i=0;i<C.size();i++)
        s.insert(C[i]);
    
    while(!q.empty())
    {
        depth++;
        levelSize = q.size();
        while(levelSize--)
        {
            string word = q.front();
            q.pop();
            
            for(int i=0;i<word.length();i++)
            {
                string temp = word;
                for(char c='a';c<='z';c++)
                {
                    temp[i] = c;
                    if(temp.compare(word) == 0)//skip the same word
                        continue;
                    if(temp.compare(B) == 0)
                        return depth + 1;
                    if(s.find(temp) != s.end())
                    {
                        q.push(temp);
                        s.erase(temp);
                    }
                }
            }
        }
    }
    
    return 0;
}