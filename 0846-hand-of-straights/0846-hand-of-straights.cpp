class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ( hand.size()%groupSize!=0) return false;
        
        unordered_map<int,int> freq;
        sort(hand.begin(), hand.end());

        for (int n: hand){
            freq[n]++;
        }

        // whenever we start forming a group - always Greedily try to Form - smallest group....
        for ( int startCard: hand){
            
            // skip , if card already used in previous group making
            if (freq.find(startCard)==freq.end()) continue;

            // start forming the group from the smallest possible
            for ( int card=startCard ; card< startCard+groupSize ; card++){
                // check
                if (freq.find(card) == freq.end() ) return false;

                // if card is valid
                freq[card]--;

                // if no more cards left
                if (freq[card]==0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};