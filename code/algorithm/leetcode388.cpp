class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> Q,nxt;
        Q.push(start);
        for(int i=1;i<=bank.size();i++){
            while(!Q.empty()){
                string cur=Q.front();
                Q.pop();
                for(string & str:bank){
                    if(diff(cur,str)==1){
                        nxt.push(str);
                    }
                    if(str==end)
                        return i;
                }
                
            }
           while(!nxt.empty()){
                string cur=nxt.front();
                nxt.pop();
                Q.push(cur);           } 
           
        }
        
        return -1;
    }
    
    int diff(string &s1,string &s2){
        int di=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                di++;
        }
        return di;
    }
};