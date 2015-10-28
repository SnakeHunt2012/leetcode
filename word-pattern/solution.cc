class Solution {
private:
    void split(const string &str, vector<string> &token_vec);
    
public:
    bool wordPattern(string pattern, string str);
};

bool Solution::wordPattern(string pattern, string str) {
    vector<string> token_vec;
    split(str, token_vec);

    set<string> token_set;
    for (vector<string>::const_iterator iter = token_vec.begin(); iter != token_vec.end(); ++iter)
	token_set.insert(*iter);

    set<char> label_set;
    for (string::const_iterator iter = pattern.begin(); iter != pattern.end(); ++iter)
	label_set.insert(*iter);

    if (token_vec.size() != pattern.size())
	return false;
    if (token_set.size() != label_set.size())
	return false;

    map<string, char> label_map;
    vector<string>::const_iterator token_iter;
    string::const_iterator label_iter;
    for (token_iter = token_vec.begin(), label_iter = pattern.begin();
	 token_iter != token_vec.end() && label_iter != pattern.end();
	 ++token_iter, ++label_iter) {
	if (!label_map.count(*token_iter)) {
	    label_map[*token_iter] = *label_iter;
	    continue;
	}
	if (label_map[*token_iter] != *label_iter)
	    return false;
    }
    return true;
}

void Solution::split(const string &str, vector<string> &token_vec) {
    istringstream stream(str);
    string token;
    
    while (stream >> token) {
	token_vec.push_back(token);
    }
}
