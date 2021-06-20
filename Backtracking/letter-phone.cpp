unordered_map<char,vector<char>> ump;

void CreateMapping(unordered_map<char,vector<char>> &ump)
{
    ump['2'].push_back('a');
    ump['2'].push_back('b');
    ump['2'].push_back('c');

    ump['3'].push_back('d');
    ump['3'].push_back('e');
    ump['3'].push_back('f');    

    ump['4'].push_back('g');
    ump['4'].push_back('h');
    ump['4'].push_back('i');

    ump['5'].push_back('j');
    ump['5'].push_back('k');
    ump['5'].push_back('l');

    ump['6'].push_back('m');
    ump['6'].push_back('n');
    ump['6'].push_back('o');

    ump['7'].push_back('p');
    ump['7'].push_back('q');
    ump['7'].push_back('r');
    ump['7'].push_back('s');

    ump['8'].push_back('t');
    ump['8'].push_back('u');
    ump['8'].push_back('v');

    ump['9'].push_back('w');
    ump['9'].push_back('x');
    ump['9'].push_back('y');
    ump['9'].push_back('z');

    return ;}

void Permutate(vector<string> &res, string &digits
                    ,int index,string comb)
{
    //BASE CASE
    if(index==digits.size())
    {
        res.push_back(comb);
        return;
    }

    //RECURSION
    for(int i=0;i<ump[digits[index]].size();i++)
        Permutate(res,digits,index+1,comb+ump[digits[index]][i]);
    
}

vector<string> Solution::letterCombinations(string digits)
{
    vector<string> res;
    int N = digits.size();
    
    CreateMapping(ump);
    Permutate(res,digits,0,"");
    
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        if(res[i]==res[i+1])
        {
            res.erase(res.begin()+i);
            i--;
        }
    }
    
    return res;
}
