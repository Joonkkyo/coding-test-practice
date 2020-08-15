class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",
                          ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                          "...","-","..-","...-",".--","-..-","-.--","--.." };
        set<string> word_set;

        for (auto word : words)
        {
            string tmp = "";

            for (char c : word)
                tmp += morse[c - 'a'];

            word_set.insert(tmp);
        }

        return word_set.size();
    }
};

//         string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
//                       ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
//                       "...","-","..-","...-",".--","-..-","-.--","--.."};
//         char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
//                          'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//         vector<string> vec;
//         string ret = "";

//         for (int i = 0; i < words.size(); i++)
//         {
//             for (int j = 0; j < words[i].size(); j++)
//             {
//                 for (int k = 0; k < 26; k++)
//                 {
//                     if (words[i][j] == alpha[k])
//                     {
//                         ret.append(morse[k]);
//                     }
//                 }
//             }
//             vec.push_back(ret);
//             ret.clear();
//         }
//         sort(vec.begin(), vec.end());
//         vec.erase(unique(vec.begin(), vec.end()), vec.end());

//         return vec.size();
