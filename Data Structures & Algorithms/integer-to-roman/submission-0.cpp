class Solution {
public:
    string intToRoman(int num) {
        int p3=num/1000;
        int p2=(num%1000)/100;
        int p1=(num%100)/10;
        int p0=(num%10);
        string res;
        for(int i=0;i<p3;i++)
        {
            res+='M';
        }

        if(p2==4)
        {
            res+="CD";
        }else if(p2==9)
        {
            res+="CM";
        }else if(p2<5)
        {
            for(int i=0;i<p2;i++)
            {
                res+='C';
            }
        }else{
            res+='D';
            for(int i=0;i<(p2-5);i++)
            {
                res+='C';
            }
            
        }

        if(p1==4)
        {
            res+="XL";
        }else if(p1==9)
        {
            res+="XC";
        }else if(p1<5)
        {
            for(int i=0;i<p1;i++)
            {
                res+='X';
            }
        }else{
            res+='L';
            for(int i=0;i<(p1-5);i++)
            {
                res+='X';
            }
            
        }

        if(p0==4)
        {
            res+="IV";
        }else if(p0==9)
        {
            res+="IX";
        }else if(p0<5)
        {
            for(int i=0;i<p0;i++)
            {
                res+='I';
            }
        }else{
            res+='V';
            for(int i=0;i<(p0-5);i++)
            {
                res+='I';
            }
            
        }
        return res;
    }
};