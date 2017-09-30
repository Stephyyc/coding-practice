/* Prompt 
A left rotation operation on an array of size shifts each of the array's elements unit to the left. 
For example, if 4 left rotations are performed on array [1,2,3,4,5], then the array would become [5,1,2,3,4].
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* code started here */
vector<int> array_left_rotation(vector<int> a, int n, int k) {
    
    vector<int> return_vector;
    
    for (int i = 0; i < k; i++) {
        int push_me = a[i];
        a.push_back(push_me);
    }
    
    for (int i = k; i < a.size(); i++) {
        return_vector.push_back(a[i]);
    }
    
    return return_vector;
}
/* code ended here */

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
