class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int>vis(26,0) ;

        for(int i=0;i<sentence.size();i++){
            if(vis[sentence[i]-'a'] !=0)
                continue;
            else
                vis[sentence[i]-'a']+=1;
        }
        for(int j=0;j<26;j++){
            if(vis[j]==0)
               return false ;
        }
 return true;
    }
};