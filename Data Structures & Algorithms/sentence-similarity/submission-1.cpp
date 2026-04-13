class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size()!=sentence2.size()) return false;

        for(int i=0;i<sentence1.size();i++)
        {
            if(sentence1[i]==sentence2[i]) continue;
            vector<string> pair1 = {sentence1[i], sentence2[i]};
            vector<string> pair2 = {sentence2[i], sentence1[i]};
            if(std::count(similarPairs.begin(),similarPairs.end(),pair1))
            {
                continue;
            }else if(std::count(similarPairs.begin(),similarPairs.end(),pair2))
            {
                    continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
