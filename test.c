#include <iostream>
#include <memory.h>
#include <cstdlib>
using namespace std;
#define MAX_SIZE 410
char _map[MAX_SIZE][MAX_SIZE];


// 이번 별찍기는 별을 다 채우고 빈칸을 뚫는게 패턴화가 편하다.
// n:1 // 별도 작업 x
// n:2 {상좌:4, 하우:2 }
// n:3 {상좌:8, 하우:6, f(n-2) }
// n의 가로세로크기: n-1+4 (단, n>1) n=2일때 가로:5, 세로7
// a_n을 가로, b_n을 세로로 두면, a_n1=5, b_n1=7. 일반화하면 a_n+1 = a_n+4, b_n+1 = b_n+4
// 등차수열 항의 공식: a_n = a_i + (n-i)*d (i는 i번쨰 항, d는 공차)
// 가로세로 max는 410 정도면 충분
//
void init_map(const int n) {
	const int alloc_size_x = 4*(n-1) + 1;
	const int alloc_size_y = 4*(n-1) + 3;

	for(int i=1; i<=alloc_size_y; i++){
		memset(_map[i]+1, '*', sizeof(char)*alloc_size_x);
	}
}

void print_map(const int n) {
	const int alloc_size_x = 4*(n-1) + 1;
	const int alloc_size_y = 4*(n-1) + 3;

	for(int i=1; i<=alloc_size_y; i++){
		for(int j=1; j<=alloc_size_x; j++){
			cout << _map[i][j];
		}
		cout << '\n';
	}
}

void setup(int n) {
	// 중앙에서 밖으로 공백채워나가기
	int start_x = 1, start_y = 1;
	start_x += (n-1)*2;
	start_y += (n-1)*2;
	start_x += 1;
	start_y += 1;

	int d[444];
	int cnt = 2;
	for(int i = 1; i <= 4*(n-1); i++) {
		d[i] = cnt;
		if(i%2==0) cnt+=2;
	}

	/*
	for(int i=1; i<=4*(n-1); i++){
		cout << i << ": " << d[i] << endl;
	}
	*/

	int loop = n-1;
	int idx=1;
	while(loop--){
		//아래
		for(int i=0; i<d[idx]; i++){
			_map[start_y++][start_x] = ' ';
		}
		idx++;

		//왼쪽
		for(int i=0; i<d[idx]; i++){
			_map[start_y][start_x--] = ' ';
		}
		idx++;

		//위
		for(int i=0; i<d[idx]; i++){
			_map[start_y--][start_x] = ' ';
		}
		idx++;

		//오른쪽
		if(loop){
			for(int i=0; i<d[idx]; i++){
				_map[start_y][start_x++] = ' ';
			}
		}
		else {
			for(int i=0; i<d[idx]; i++){
				_map[start_y][start_x++] = '\0';
			}
		}
		idx++;
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	if(n==1) cout << '*';
	else {
		init_map(n);
		setup(n);
		print_map(n);
	}

	return 0;
}