class Solution {
public:
    string intToRoman(int nums) {
        
    vector<string> thou	= {"","M","MM","MMM"};
    vector<string> hund	= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> tens	= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        string ans="";
        ans+=thou[nums/1000];
        ans+=hund[(nums%1000)/100];
        ans+=tens[(nums%100)/10];
        ans+=ones[nums%10];
        
        return ans;
    }
};