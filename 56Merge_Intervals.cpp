/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool static comp(const Interval &s1, const Interval &s2){
        return s1.start < s2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty()) return intervals;
        Interval tmp;
        sort(intervals.begin(), intervals.end(), comp);
        tmp.start = intervals[0].start;
        tmp.end = intervals[0].end;
        for(int i=1; i<intervals.size(); i++){
            if (intervals[i].start <= tmp.end){
                tmp.end = intervals[i].end > tmp.end ? intervals[i].end : tmp.end;
                continue;
            }
            else{
                result.push_back(tmp);
                tmp.start = intervals[i].start;
                tmp.end = intervals[i].end;
            }
            
        }
        if(intervals[intervals.size()-1].end > tmp.end) tmp.end = intervals[intervals.size()-1].end;
        result.push_back(tmp);
        return result;
        
    }
};