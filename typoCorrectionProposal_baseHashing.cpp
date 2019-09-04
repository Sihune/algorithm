static void mstrncpy(char* src, char* dest, int n) {
	for (int i = 0; i < n; ++i) dest[i] = src[i];
}
static int mstrcmp(const char* a, const char* b) {
	while (*a != 0 && *a == *b) ++a, ++b;
	return *a - *b;
}
static void mstrcpy(char* src, char* dest) {
	int i = 0;
	while (1) {
		dest[i] = src[i];
		if (dest[i] == 0) return;
		++i;
	}
}

static int mstrlen(char* a) {
	int len = 0;
	while (a[len]) ++len;
	return len;
}
#include <stdio.h>
#define MAX 100007
#define ABS(X) (X)>0?(X):-(X)

struct Node {
	int key[5], cnt[5];
	
};

char hashTable[MAX][11];
Node mainTable[MAX];

int hashing(char* str) {
	int len = mstrlen(str);
	int h = 0;
	for (int i = 0; i < len; i++)
		h = (h * 29 + str[i])%MAX;
	
	while (hashTable[h][0] != 0 && mstrcmp(hashTable[h], str)) {
		h = (h + 1) % MAX;
	}
	mstrcpy(str, hashTable[h]);
	return h;
}

void init(int n) {
	for (int i = 0; i < MAX; i++) {
		hashTable[i][0] = 0;
		for (int j = 0; j < 5; j++) {
			mainTable[i].cnt[j] = 0;
			mainTable[i].key[j] = -1;
		}
	}
}

int prevH;
char prev[11];

bool checkWrongWord(char word[11]) {
	int prevlen = mstrlen(prev);
	int wordlen = mstrlen(word);

	if (prevlen == wordlen) {
		int cnt = 0;
		for (int i = 0; i < prevlen; i++) {
			if (word[i] != prev[i])cnt++;
			if (cnt > 1)return false;
		}
		return true;
	}
	else {
		int sub = ABS(prevlen - wordlen);
		if (sub != 1) {
			return false;
		}
		int cnt = 0;
		int p = 0,w = 0, tc ;
		while (prev[p] != 0 || word[w]!=0) {
			if (prev[p] != word[w]) {
				if (cnt > 1) {
					return false;
				}

				if (prevlen > wordlen)p++;
				else w++;
				cnt++;
				continue;
			}
			p++, w++;
		}
		return true;
	}
}

int input(char word[11], char correct[5][11]) {
	int h = hashing(word);
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		if (mainTable[h].key[i] == -1)break;
		if (mainTable[h].cnt[i] >= 2) {
			mstrcpy(hashTable[mainTable[h].key[i]], correct[ret++]);
		}
	}

	bool flag = checkWrongWord(word);
	if (flag) {	
		for (int i = 0; i < 5; i++) {
			if (h == mainTable[prevH].key[i]) {
				mainTable[prevH].cnt[i]++;
				break;
			}
			if (mainTable[prevH].key[i] == -1) {
				mainTable[prevH].key[i] = h;
				mainTable[prevH].cnt[i]++;
				break;
			}
		}

	}
	mstrcpy(word, prev);
	prevH = h;
	return ret;
}