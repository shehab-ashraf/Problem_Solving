class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& array) {
    stack<int> S;
	vector<int> res(array.size(),-1);
	for(int Idx = 0 ; Idx < 2*array.size() ; Idx++) {
        int CurrentIdx = Idx % array.size();
		while(!S.empty() && array[CurrentIdx ] > array[S.top()]) {
			res[S.top()] = array[CurrentIdx ];
			S.pop();
		}
		S.push(CurrentIdx );
	}
        return res;
    }
};
