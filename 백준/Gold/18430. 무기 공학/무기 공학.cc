#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[5][5], temp, ans; // 4 ways
bool ch[5][5];

int first(int y, int x) {return arr[y][x]*2 + arr[y+1][x] + arr[y][x-1];}
int second(int y, int x) {return arr[y][x]*2 + arr[y-1][x] + arr[y][x-1];}
int third(int y, int x) {return arr[y][x]*2 + arr[y-1][x] + arr[y][x+1];}
int fourth(int y, int x) {return arr[y][x]*2 + arr[y][x+1] + arr[y+1][x];}

void input(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> arr[i][j];
	}
}

void backTracking(int y, int x, int sum){
	if(x==m){
		x = 0;
		y++;
	}
	if(y==n){
		ans = max(ans,sum);
		return;
	}
	if(!ch[y][x]){
		if(y+1<n&&x-1>=0&&!ch[y+1][x]&&!ch[y][x-1]){
			ch[y][x] = true;
			ch[y+1][x] = true;
			ch[y][x-1] = true;
			temp = sum + first(y,x);
			backTracking(y,x+1,temp);
			ch[y][x] = false;
			ch[y+1][x] = false;
			ch[y][x-1] = false;
		}
		if(y-1>=0&&x-1>=0&&!ch[y-1][x]&&!ch[y][x-1]){
			ch[y-1][x] = true;
			ch[y][x-1] = true;
			ch[y][x] = true;
			temp = sum + second(y,x);
			backTracking(y,x+1,temp);
			ch[y-1][x] = false;
			ch[y][x-1] = false;
			ch[y][x] = false;
		}
		if(y-1>=0&&x+1<m&&!ch[y-1][x]&&!ch[y][x+1]){
			ch[y-1][x] = true;
			ch[y][x] = true;
			ch[y][x+1] = true;
			temp = sum + third(y,x);
			backTracking(y,x+1,temp);
			ch[y-1][x] = false;
			ch[y][x] = false;
			ch[y][x+1] = false;
		}
		if(y+1<n&&x+1<m&&!ch[y+1][x]&&!ch[y][x+1]){
			ch[y][x] = true;
			ch[y+1][x] = true;
			ch[y][x+1] = true; 
			temp = sum + fourth(y,x);
			backTracking(y,x+1,temp);
			ch[y][x] = false;
			ch[y+1][x] = false;
			ch[y][x+1] = false;
		}
	}
	backTracking(y,x+1,sum);
	return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	if(n==1||m==1) cout << 0 << "\n";
	else{
		backTracking(0,0,0);
		cout << ans << "\n";
	}
    return 0;
}