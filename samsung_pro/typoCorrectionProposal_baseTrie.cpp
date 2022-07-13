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
#define ABS(X) (X)>0?(X):-(X)
#define MAX 20007
#define MAXPOOL 26

struct Trie {
	int /*cnt,*/ hash;
	bool finish;
	Trie* next[MAXPOOL];
	Trie(){}
};

struct node {
	int key[5], cnt[5];
};

int mcnt, trieIdx, prevH;
Trie triePool[MAX], *root;
node mainTable[MAX];
char hashTable[MAX][11];
char prev[11];

void TrieInit() {
	root = nullptr;
	trieIdx = 0;
	mcnt = 0;
}

Trie* alloc() {
	for (int i = 0; i < MAXPOOL; i++)
		triePool[trieIdx].next[i] = nullptr;

	triePool[trieIdx].finish = /*triePool[trieIdx].cnt =*/ 0;
	triePool[trieIdx].hash = -1;

	return &triePool[trieIdx++];
}

void insert(int buffer_size, char* buf) {
	if (root == nullptr) 
		root = alloc();

	Trie* cur = root;

	for (int i = 0; i < buffer_size; i++) {
		int ch = buf[i] - 'a';
		if (cur->next[ch] == nullptr) 
			cur->next[ch] = alloc();
			
		cur = cur->next[ch];
		//cur->cnt++;
	}
	if (cur->hash == -1) {
		
		mstrcpy(buf, hashTable[mcnt]);
		cur->hash = mcnt++;
	}
	cur->finish = true;
}

int query(int buffer_size, char* buf) {
	if (root == nullptr)return -1;

	Trie* cur = root;

	for (int i = 0; i < buffer_size; i++) {
		int ch = buf[i] - 'a';
		if (cur->next[ch] == nullptr) 
			return -1;
		
		cur = cur->next[ch];
	}

	return cur->hash;
}


bool checkWrongWord(char word[11]) {
	int prevlen = mstrlen(prev);
	int wordlen = mstrlen(word);

	if (prevlen == wordlen) {
		int cnt = 0;
		for (int i = 0; i < prevlen; i++) {
			if (word[i] != prev[i])cnt++;
			if (cnt > 1)return false;
		}
	}
	else {
		int sub = ABS(prevlen - wordlen);
		if (sub != 1) {
			return false;
		}
		int cnt = 0;
		int p = 0, w = 0;
		while (prev[p] != 0 || word[w] != 0) {
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
	}
	return true;
}

void init(int n) {
	TrieInit();
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 5; j++) {
			mainTable[i].cnt[j] = 0;
			mainTable[i].key[j] = -1;
		}
	}
}

int input(char word[11], char correct[5][11]) {
	int len = mstrlen(word);
	insert(len, word);
	int h = query(len, word), ret = 0;

	//printf("%s %d\n", word, h);

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