class Solution 
{
private:
int n;
vector<string> res;
vector<string> curr_ip;
bool valid_digit(const string& ip)
{
    if(ip.empty() || (ip[0] == '0' && ip.size() > 1) || stoi(ip) > 255)
        return false;
    
    return true;
}

void restore_ip(const string& s, int index = 0)
{
    if(index == n || curr_ip.size() == 4)
    {
        if(index == n && curr_ip.size() == 4)
            res.push_back(curr_ip[0] + "." + curr_ip[1] + "." + curr_ip[2] + "." + curr_ip[3]);
            
        return;
    }

    string tmp = "";
    int end = min(n, index + 3);
    for(int i = index; i < end; ++i)
    {
        tmp+= s[i];
        if(valid_digit(tmp))
        {
            curr_ip.push_back(tmp);
            restore_ip(s, i + 1);
            curr_ip.pop_back();
        }
        else
            return;
    }
}
public:
    vector<string> restoreIpAddresses(string& s) 
    {
        n = s.size();
        restore_ip(s);
        return res;
    }
};
