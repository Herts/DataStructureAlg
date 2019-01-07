#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	std::vector<std::string> ops;
	ops[0] = "5";
	ops[1] = "2";
	ops[2] = "C";
	ops[3] = "D";
	ops[4] = "+";

	std::stack<std::string> st;
	int opsize = ops.size();
	int sum = 0;
	for(int n = 0; n < opsize ; n++) {
		std::string s = ops[n];
		if(s == "C") {
			if(st.empty()) continue;
			sum -= stoi(st.top());
			st.pop();
		} else if(s == "D") {
			if(st.empty()) continue;
			sum += 2 * stoi(st.top());
			st.push(to_string( 2 * stoi(st.top()) ));
		} else if(s == "+") {
			if(st.empty()) continue;
			string tmp = st.top();
			st.pop();
			if(st.empty()) {
				st.push(tmp);
				continue;
			}
			int tmpsum = stoi(st.top()) + stoi(tmp);
			sum += tmpsum;
			st.push(tmp);
			st.push(tmpsum);
		} else {
			sum += stoi(s);
			st.push(s);
		}

		
		       	
	}
}
