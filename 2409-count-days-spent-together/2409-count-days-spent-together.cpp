class Solution {
public:
    int convertToDays(string date , vector<int> &months){
        int m = (date[0]-'0')*10 + date[1]-'0';
        int days = 0;
        for ( int i = 0; i < m-1; i++){
            days += months[i];
        }

        // last
        days+= (date[3]-'0')*10 + date[4]-'0';
        return days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aa =  convertToDays(arriveAlice , months);
        int al = convertToDays(leaveAlice , months);
        int ba = convertToDays(arriveBob , months);
        int bl = convertToDays(leaveBob , months);

        int start = max (aa, ba);
        int end = min (al , bl);
        if (start>end) return 0;
        return  end - start+1;
    }
};