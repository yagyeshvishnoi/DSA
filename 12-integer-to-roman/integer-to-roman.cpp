class Solution {
public:
    string key(int n,int digits){
        if(n==0) return "";
        if(digits==1){
           
            if(n==1) return "I";
            if(n==2) return "II";
            if(n==3) return "III";
            if(n==4) return "IV";
            if(n==5) return "V";
            if(n==6) return "VI";
            if(n==7) return "VII";
            if(n==8) return "VIII";
            if(n==9) return "IX";

        }
        if(digits==2){
            
            if(n==1) return "X";
            if(n==2) return "XX";
            if(n==3) return "XXX";
            if(n==4) return "XL";
            if(n==5) return "L";
            if(n==6) return "LX";
            if(n==7) return "LXX";
            if(n==8) return "LXXX";
            if(n==9) return "XC";
        }
        if(digits==3){
            
            if(n==1) return "C";
            if(n==2) return "CC";
            if(n==3) return "CCC";
            if(n==4) return "CD";
            if(n==5) return "D";
            if(n==6) return "DC";
            if(n==7) return "DCC";
            if(n==8) return "DCCC";
            if(n==9) return "CM";
        }
        if(digits==4){
            if(n==1) return "M";
            if(n==2) return "MM";
            if(n==3) return "MMM";
        }

        return "";
    }
    string intToRoman(int num) {
        string ans="";
        int digits = 0;
        while(num){
            digits++;
            int tmp = num%10;
            ans =  key(tmp,digits) + ans;
            num/=10;
        }
        return ans;
    }
};