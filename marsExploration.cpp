#include <stdio.h>
#define MAX_MAP_SIZE		64
#define BLOCK_SIZE			4

struct DLL {
	struct Node {
		int mat[2][2];
		Node *prev;
		Node *next;
	};

	Node *head, *tail;
	DLL() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

	void insert(int mat[][2]) {
		Node *now = new Node;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				now->mat[i][j] = mat[i][j];
		now->next = tail;
		tail->prev->next = now;
		now->prev = tail->prev;
		tail->prev = now;
	}
};
struct dll {
	struct Node {
		int x, y;
		Node *prev;
		Node *next;
		Node(){}
		Node(int x, int y):x(x),y(y){
			prev = next = 0;
		}
	};

	Node *head, *tail;
	dll() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

	void insert(int x, int y) {
		Node *now = new Node(x,y);
		now->next = tail;
		tail->prev->next = now;
		now->prev = tail->prev;
		tail->prev = now;
	}
};

int bitMap[MAX_MAP_SIZE / 2][MAX_MAP_SIZE / 2], bitZone[BLOCK_SIZE / 2][BLOCK_SIZE / 2];
bool visit[MAX_MAP_SIZE / 2][MAX_MAP_SIZE / 2];
char brokenZone[BLOCK_SIZE][BLOCK_SIZE];

extern void brokenCamera(char zone[BLOCK_SIZE][BLOCK_SIZE]);

void makeBitMap(int N, char map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
	for (int i = 0; i < N; i += 2) {
		for (int j = 0; j < N; j += 2) {
			for (int r = i; r < i + 2; r++) {
				for (int c = j; c < j + 2; c++) {
					bitMap[i / 2][j / 2] = (bitMap[i / 2][j / 2] * 16 + map[r][c]);
				}
			}
		}
	}
}

void makeZone(char map[BLOCK_SIZE][BLOCK_SIZE]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			bitZone[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i += 2) {
		for (int j = 0; j < 4; j += 2) {
			for (int r = i; r < i + 2; r++) {
				for (int c = j; c < j + 2; c++) {
					bitZone[i / 2][j / 2] = (bitZone[i / 2][j / 2] * 16 + map[r][c]);
				}
			}
		}
	}
}

void returnMap(int N, char map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N/2; j++) {
			for (int r = 1; r >= 0; r--) {
				for (int c = 1; c >= 0; c--) {
					map[i * 2 + r][j * 2 + c] = bitMap[i][j] % 16;
					bitMap[i][j] /= 16;
				}
			}
		}
	}
}

void completeMap(int N, char map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
	DLL list, delList;
	dll loc;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			bitMap[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	makeBitMap(N, map);
	int MaxBin = (N / 2 - 2)*(N / 2 - 2);

	for (int i = 0; i < N / 2 - 1; i++) {
		loc.insert(i, 0);
		if (i != 0)loc.insert(0, i);
		loc.insert((N / 2 - 2), i);
		if (i != (N / 2 - 2))loc.insert(i, (N / 2 - 2));
		visit[i][0] = 1;
		visit[0][i] = 1;
		visit[(N / 2 - 2)][i] = 1;
		visit[i][(N / 2 - 2)] = 1;
	}

	while (MaxBin) {
		int idx = 0;
		while (idx < N*N/10) {
			idx++;
			bool iflag = 0;
			brokenCamera(brokenZone);
			makeZone(brokenZone);
			for (DLL::Node *it = delList.head->next; it != delList.tail; it = it->next) {
				int cnt = 0;
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if (bitZone[i][j] == (it->mat[i][j]))cnt++;
					}
				}
				if (cnt == 4) {
					iflag = 1;
					break;
				}
			}
			if (iflag)continue;
			if (list.head->next == list.tail) {
				list.insert(bitZone);
				continue;
			}
			for (DLL::Node *it = list.head->next; it != list.tail; it = it->next) {
				int cnt = 0;
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if (bitZone[i][j] == (it->mat[i][j]))cnt++;
					}
				}
				if (cnt == 4) {
					iflag = 1;
					break;
				}
			}
			if (iflag)continue;
			list.insert(bitZone);
		}// 곂치지 않게 리스트에 추가
		int flag = 1;
		while (flag) {


			flag = 0;
			bool updated = 0;
			for (dll::Node *iter = loc.head->next; iter != loc.tail; iter = iter->next) {
				updated = 0;
				int x = iter->x;
				int y = iter->y;
				for (DLL::Node *it = list.head->next; it != list.tail; it = it->next) {
					int cnt = 0;
					for (int r = 0; r < 2; r++) {
						for (int c = 0; c < 2; c++) {
							if (it->mat[r][c] == bitMap[r + x][c + y])cnt++;
						}
					}
					if (cnt >= 2) {
						for (int r = 0; r < 2; r++) {
							for (int c = 0; c < 2; c++) {
								if (!bitMap[x + r][y + c]) {
									MaxBin--;
									for (int p = -1; p <= 0; p++)
										for (int q = -1; q <= 0; q++) {
											int xx = x + r + p;
											int yy = y + c + q;
											if (!visit[xx][yy]) {
												visit[xx][yy] = true;
												loc.insert(xx, yy);
											}
										}
								}
								bitMap[r + x][c + y] = it->mat[r][c];
							}
						}
						delList.insert(it->mat);
						DLL::Node *temp = it;
						it->next->prev = it->prev;
						it->prev->next = it->next;
						it = it->prev;
						delete temp;
						flag = 1;
						updated = 1;
						break;
					}
				}
				if (updated) {
					dll::Node *tmp = iter;
					iter->next->prev = iter->prev;
					iter->prev->next = iter->next;
					iter = iter->prev;
					delete tmp;
				}
			}
		}
	}

	returnMap(N, map);

}

0.333s