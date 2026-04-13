class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long> rooms(n, 0);
        vector<int> meetingcount(n, 0);
        for(const auto& meeting:meetings)
        {
            int min_room=0;
            int found=0;
            for(int i=0;i<n;i++)
            {
                if(rooms[i]<=meeting[0])
                {
                    meetingcount[i]++;
                    rooms[i]=meeting[1];
                    found=1;
                    break;
                }
                if(rooms[min_room]>rooms[i])
                {
                    min_room=i;
                }
            }

            if(found) continue;
            meetingcount[min_room]++;
            rooms[min_room]+=(meeting[1]-meeting[0]);
        }

        int res=0;
        for(int i=1;i<n;i++)
        {
            if(meetingcount[res]<meetingcount[i])
            {
                res=i;
            }
        }        
        return res;
    }
};