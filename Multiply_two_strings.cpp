string multiplyStrings(string& q, string& w) {
    bool a = true;
    bool b = true;
    if(q[0] == '-')    a = false;
    if(w[0] == '-')    b = false;
    string s1, s2;
    int ind = 0;
    while(ind<q.size()){
        if(q[ind] == '0' || q[ind] == '-')  ind++;
        else    break;
    }
    while(ind<q.size()){
        s1.push_back(q[ind]);
        ind++;
    }
    ind = 0;
    while(ind<w.size()){
        if(w[ind] == '0' || w[ind] == '-')  ind++;
        else    break;
    }
    while(ind<w.size()){
        s2.push_back(w[ind]);
        ind++;
    }
    vector<int> ans(s1.size()+s2.size(), 0);
    
    for(int i = 0; i<s1.size(); i++){
        int x = s1.size()-1-i;
        int carry = 0;
        int c = s1[x]-'0';
        for(int j = 0; j<s2.size(); j++){
            int y = s2.size()-1-j;
            int d = s2[y]-'0';
            ans[i+j] = ans[i+j]+c*d+carry;
            carry = ans[i+j]/10;
            ans[i+j] = ans[i+j]%10;
        }
        ans[i+s2.size()] += carry;
    }
    
    if(s1.empty() || s2.empty())    return "0";
    ind = ans.size()-1;
    while(ind >= 0 && ans[ind] == 0)      ind--;
    string answer;
    if(a ^ b)   answer.push_back('-');
    while(ind >= 0){
        answer.push_back('0'+ans[ind]);
        ind--;
    }
    if(answer.empty())  return "0";
    return answer;
}