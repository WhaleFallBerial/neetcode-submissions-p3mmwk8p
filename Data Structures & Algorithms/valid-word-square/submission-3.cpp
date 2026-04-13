class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int row= words.size();
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<words[r].size();c++)
            {
                if(c>=row||r>=words[c].size()) return false;
                if(words[r][c]!=words[c][r]) return false;
            }
        }
        return true;
        
    }
};
