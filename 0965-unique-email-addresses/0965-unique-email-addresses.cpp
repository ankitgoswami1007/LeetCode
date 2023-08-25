class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans = 0;
        int len = emails.size();
        if(len == 0) return 0;
        unordered_set<string> uset;
        for(auto email : emails){
            string s;
            int i = 0;
            for(; i < email.length() ; i++){
                if(email[i] == '@') break;
                if(email[i] == '+'){
                    if( email[i+1] != '@' )  email[i+1] = '+';
                    continue;
                }
                if(email[i] == '.') {
                    continue;
                 }
                s += email[i];
            }
            for(; i < email.length() ; i++){
                s += email[i];
            }
            cout<<s<<"\n";
            uset.insert(s);
        }
        return uset.size();
    }
};