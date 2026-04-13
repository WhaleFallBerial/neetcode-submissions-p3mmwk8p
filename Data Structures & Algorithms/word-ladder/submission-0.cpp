class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(), endWord)==wordList.end() || beginWord==endWord) return 0;

        int n=wordList.size();
        int m=wordList[0].size();
        vector<vector<int>> data(n);
        unordered_map<string,int> mp;
        queue<int> q;
        int res=1;
        unordered_set<int> visit;
        for(int i=0;i<n;i++)
        {
            mp[wordList[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cnt=0;
                for(int k=0;k<m;k++)
                {
                    if(wordList[i][k]!=wordList[j][k]) cnt++;               
                }
                if(cnt==1)
                {
                    data[i].push_back(j);
                    data[j].push_back(i);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(char c='a';c<='z';c++)
            {
                if(c==beginWord[i]) continue;
                string word=beginWord;
                word[i]=c;
                if(mp.find(word)!=mp.end()&&visit.find(mp[word])==visit.end())
                {
                    q.push(mp[word]);
                    visit.insert(mp[word]);
                }
            }
        }
        while(!q.empty())
        {
            res++;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int node=q.front();
                q.pop();
                if(wordList[node]==endWord) return res;

                for(int d:data[node])
                {
                    if(visit.find(d)==visit.end())
                    {
                        visit.insert(d);
                        q.push(d);
                    }
                }
            }
        }
        return 0;



    }
};
