class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int windex=0, aindex=0;
        int wn=word.size(), an=abbr.size();
        string tmp;
        bool tmpflag=false;
        word+='a';
        abbr+='a';
        while(windex<wn||aindex<an)
        {
            if(!tmpflag && word[windex]==abbr[aindex])
            {
                windex++;
                aindex++;
            }else{
                if(isdigit(abbr[aindex]))
                {
                    tmp+=abbr[aindex];
                    aindex++;
                    tmpflag=true;
                }else{
                    if(tmp[0]=='0') return false;
                    int cnt=stoi(tmp);
                    tmp="";
                    windex=windex+cnt;
                    tmpflag=false;
                    if(word[windex]==abbr[aindex])
                    {
                        windex++;
                        aindex++;
                    }else{
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};