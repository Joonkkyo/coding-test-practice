class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector<bool> answer;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > max)
                max = candies[i];
        }
        
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies < max)
                answer.push_back(false);
            else
                answer.push_back(true);
        }
        return answer;
    }
};
