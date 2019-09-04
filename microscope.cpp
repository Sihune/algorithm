#define MAX 100
typedef struct {
	int x, y;
}Point;
typedef struct {
	int count;
	Point pointList[10];
}RESULT;

int mainMap[MAX][MAX], n,Size;

extern int observe(int left, int top, int size);
extern void init(int arr[MAX][MAX], int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mainMap[i][j] = arr[i][j];
		}
	}
	n = 1;
	while (n < size) {
		n *= 2;
	}
	Size = size;
}

bool isPoss(int x, int y) {
	return x < 0 || y < 0 || x >= Size || y >= Size;
}

void sol(int left, int top, int size, RESULT& r) {
	if (isPoss(left, top))return;
	if (size == 1) {
		if (mainMap[top][left] != observe(left, top, size)) {
			r.pointList[r.count].x = left;
			r.pointList[r.count].y = top;
			r.count++;
		}
		return;
	}

	int nsize = size / 2;
	int nleft = left + nsize, ntop = top + nsize;
	if (size % 2 == 1) {
		nleft++, ntop++, nsize++;
	}

	int cnt = 0;
	for (int i = top; i < top + size; i++)
		for (int j = left; j < left + size; j++) {
			if (isPoss(i, j))continue;
			if (mainMap[i][j])cnt++;
		}

	if (observe(left, top, size) != cnt) {
		sol(left, top, nsize, r);
		sol(nleft, top, nsize, r);
		sol(left, ntop, nsize, r);
		sol(nleft, ntop, nsize, r);
	}
}

extern RESULT infect()
{
	RESULT r;
	r.count = 0;
	sol(0, 0, n, r);
	for (int i = 0; i < r.count; i++) {
		mainMap[r.pointList[i].y][r.pointList[i].x] = 1;
	}

	return r;
}


extern RESULT restore() {
	RESULT r;
	r.count = 0;
	sol(0, 0, n, r);
	for (int i = 0; i < r.count; i++) {
		mainMap[r.pointList[i].y][r.pointList[i].x] = 0;
	}
	
	return r;
}