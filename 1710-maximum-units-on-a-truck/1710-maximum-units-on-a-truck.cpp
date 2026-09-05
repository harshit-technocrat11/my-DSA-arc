class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int> , vector<pair<int, int>> > pq;

        for ( auto n: boxTypes){
            int units = n[1];
            int boxes = n[0];

            pq.push({units, boxes});
        }

        int sum = 0; 

        while(truckSize && !pq.empty()){
            int units =  pq.top().first;
            int boxes = pq.top().second;

            pq.pop();

            if ( truckSize >= boxes ){
                sum+= boxes*units;
                truckSize-=boxes;
            }

            else if(truckSize < boxes){
                sum+= truckSize*units;
                truckSize=0; //set to 0
            }
        }

        return sum;
    }
};