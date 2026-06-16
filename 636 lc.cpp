class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st; // stack to store function IDs
        int prev_time = 0;
        
        for (const string& log : logs) {
            // Parse the log
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1 + 1);
            
            int func_id = stoi(log.substr(0, pos1));
            string type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int timestamp = stoi(log.substr(pos2 + 1));
            
            if (type == "start") {
                if (!st.empty()) {
                    // Add time to the currently running function
                    // Time from prev_time to timestamp - 1
                    result[st.top()] += timestamp - prev_time;
                }
                st.push(func_id);
                prev_time = timestamp;
            } else { // "end"
                // Add time for the ending function
                result[st.top()] += timestamp - prev_time + 1;
                st.pop();
                prev_time = timestamp + 1;
            }
        }
        
        return result;
    }
};
