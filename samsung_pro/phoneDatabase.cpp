#define HMAX 270007

int mstrlen(char* a) {
	int ret = 0;
	while (a[ret++] != 0) {}
	return ret;
}

void mstrcpy(char* src, char* dist) {
	int len = mstrlen(src);
	for (int i = 0; i < len; i++) {
		dist[i] = src[i];
	}
	dist[len] = 0;
}

int mstrcmp(char* src, char* dest) {
	int i = 0;
	while (src[i] == dest[i]) {
		if (src[i] == 0 || dest[i] == 0)break;
		i++;
	}
	return src[i] - dest[i];
}

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[21];
} RESULT;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct Main {
	int name, num, birth, email, memo;
	char Name[21];
	char Num[21];
	char Birth[21];
	char Email[21];
	char Memo[21];
};

struct node {
	int index;
	node* prev;
	node* next;
	node(){}
	node(int index):index(index){}
};


struct DLL {
	node* head, * tail;
	DLL() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
	}

	void insert(int val) {
		node* now = new node(val);
		now->next = tail;
		tail->prev->next = now;
		now->prev = tail->prev;
		tail->prev = now;
	}

	void clear() {
		for (node* it = head->next; it != tail; ) {
			node* temp = it;
			it = it->next;
			delete temp;
		}
		head->next = tail;
		tail->prev = head;
	}
};

int mainIdx = 0;
Main mainDB[50005];
char nameHash[HMAX][21], numHash[HMAX][21], birthHash[HMAX][21], emailHash[HMAX][21], memoHash[HMAX][21];
DLL nameList[HMAX], numList[HMAX], birthList[HMAX], emailList[HMAX], memoList[HMAX];

int hashing(char* str, char hashMap[HMAX][21]) {
	int len = mstrlen(str);
	int h = 0;
	for (int i = 0; i < len; i++) {
		h = (h * 26 + str[i]) % HMAX;
	}
	while (hashMap[h][0] != 0 && mstrcmp(str, hashMap[h])) {
		h = (h + 1) % HMAX;
	}
	mstrcpy(str, hashMap[h]);
	return h;
}

void InitDB()
{
	//midx = 
	mainIdx = 0;
	for (int i = 0; i < HMAX; i++) {
		nameList[i].clear();
		numList[i].clear();
		birthList[i].clear();
		emailList[i].clear();
		memoList[i].clear();

		nameHash[i][0] = 0;
		numHash[i][0] = 0;
		birthHash[i][0] = 0;
		emailHash[i][0] = 0;
		memoHash[i][0] = 0;
	}
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	mstrcpy(name, mainDB[mainIdx].Name);
	mstrcpy(number, mainDB[mainIdx].Num);
	mstrcpy(birthday, mainDB[mainIdx].Birth);
	mstrcpy(email, mainDB[mainIdx].Email);
	mstrcpy(memo, mainDB[mainIdx].Memo);

	int nameH = hashing(name, nameHash);
	int numH = hashing(number, numHash);
	int birthH = hashing(birthday, birthHash);
	int emailH = hashing(email, emailHash);
	int memoH = hashing(memo, memoHash);
	nameList[nameH].insert(mainIdx);	mainDB[mainIdx].name = nameH;
	numList[numH].insert(mainIdx);		mainDB[mainIdx].num = numH;
	birthList[birthH].insert(mainIdx);	mainDB[mainIdx].birth = birthH;
	emailList[emailH].insert(mainIdx);	mainDB[mainIdx].email = emailH;
	memoList[memoH].insert(mainIdx);	mainDB[mainIdx].memo = memoH;
	//printf("%s %s %s %s %s\n", name, number, birthday, email, memo);
	//printf("%d %d %d %d %d\n", nameH, numH, birthH, emailH, memoH);
	mainIdx++;
}

int makeArr(char* str, int* arr, char Hash[HMAX][21], DLL List[]) {
	int idx = 0;
	int hash = hashing(str, Hash);
	//printf("%s %d\n", str, hash);
	for (node* it = List[hash].head->next; it != List[hash].tail; it = it->next) {
		arr[idx++] = it->index;
	}
	return idx;
}

void sepField(FIELD field,int *idx, int *arr, char* str) {
	if (field == NAME) *idx = makeArr(str, arr, nameHash, nameList);
	else if (field == NUMBER) *idx = makeArr(str, arr, numHash, numList);
	else if (field == BIRTHDAY) *idx = makeArr(str, arr, birthHash, birthList);
	else if (field == EMAIL) *idx = makeArr(str, arr, emailHash, emailList);
	else if (field == MEMO) *idx = makeArr(str, arr, memoHash, memoList);
}

void eraseStr(int cur, DLL hash) {
	for (node* it = hash.head->next; it != hash.tail; it = it->next) {
		if (it->index == cur) {
			it->next->prev = it->prev;
			it->prev->next = it->next;
			it->index = -1;
			break;
		}
	}
}

int Delete(FIELD field, char* str)
{
	int idx = 0, arr[100];
	sepField(field, &idx, arr, str);

	for (int i = 0; i < idx; i++) {
		int cur = arr[i];

		int nameh = mainDB[cur].name;
		int numh = mainDB[cur].num;
		int birthh = mainDB[cur].birth;
		int emailh = mainDB[cur].email;
		int memoh = mainDB[cur].memo;

		eraseStr(cur, nameList[nameh]);
		eraseStr(cur, numList[numh]);
		eraseStr(cur, birthList[birthh]);
		eraseStr(cur, emailList[emailh]);
		eraseStr(cur, memoList[memoh]);
	}

	return idx;
}



int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	int idx = 0, arr[100];
	sepField(field, &idx, arr, str);

	for (int i = 0; i < idx; i++) {
		int cur = arr[i];
		if (changefield == NAME) {
			int h = mainDB[cur].name;
			eraseStr(cur, nameList[h]);
			mstrcpy(changestr, mainDB[cur].Name);
			h = hashing(changestr, nameHash);
			nameList[h].insert(cur);
			mainDB[cur].name = h;
		}
		else if (changefield == NUMBER) {
			int h = mainDB[cur].num;
			eraseStr(cur, numList[h]);
			mstrcpy(changestr, mainDB[cur].Num);
			h = hashing(changestr, numHash);
			numList[h].insert(cur);
			mainDB[cur].num = h;
		}
		else if (changefield == BIRTHDAY) {
			int h = mainDB[cur].birth;
			eraseStr(cur, birthList[h]);
			mstrcpy(changestr, mainDB[cur].Birth);
			h = hashing(changestr, birthHash);
			birthList[h].insert(cur);
			mainDB[cur].birth = h;
		}
		else if (changefield == EMAIL) {
			int h = mainDB[cur].email;
			eraseStr(cur, emailList[h]);
			mstrcpy(changestr, mainDB[cur].Email);
			h = hashing(changestr, emailHash);
			emailList[h].insert(cur);
			mainDB[cur].email = h;
		}
		else if (changefield == MEMO) {
			int h = mainDB[cur].memo;
			eraseStr(cur, memoList[h]);
			mstrcpy(changestr, mainDB[cur].Memo);
			h = hashing(changestr, memoHash);
			memoList[h].insert(cur);
			mainDB[cur].memo= h;
		}
	}

	return idx;
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	RESULT result;
	int idx = 0, arr[100];
	sepField(field, &idx, arr, str);

	result.count = idx;
	if (idx == 1) {
		if (ret_field == NAME)mstrcpy(mainDB[arr[0]].Name, result.str);
		else if (ret_field == NUMBER)mstrcpy(mainDB[arr[0]].Num, result.str);
		else if (ret_field == BIRTHDAY)mstrcpy(mainDB[arr[0]].Birth, result.str);
		else if (ret_field == EMAIL)mstrcpy(mainDB[arr[0]].Email, result.str);
		else if (ret_field == MEMO)mstrcpy(mainDB[arr[0]].Memo, result.str);
	}

	return result;
}