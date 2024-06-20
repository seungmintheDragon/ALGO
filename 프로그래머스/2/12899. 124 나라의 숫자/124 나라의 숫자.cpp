#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string ans = "";
    string nums[3] = {"1", "2", "4"};
    
    for(int i = n; i > 0;) {
        i -= 1;
        ans = nums[i % 3] + ans;
        i /= 3;
    }
    
    return ans;
}