class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            int j = i;
            // Safety check added here to prevent out-of-bounds access
            while (j < s.length() && s[j] != '#') {
                j++;
            }
            
            // Extract the length of the upcoming string
            int len = stoi(s.substr(i, j - i));
            
            // Move pointer past the '#'
            i = j + 1;
            
            // Extract the actual string using the length
            decoded.push_back(s.substr(i, len));
            
            // Move pointer past the extracted string
            i += len;
        }
        
        return decoded;
    }
};