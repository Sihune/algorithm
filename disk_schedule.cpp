#pragma GCC optimize("O3")
const int MAX = 100000;

bool disk[MAX+1];
int disk_head;
int disk_size;
int queue[MAX+1];
int front, rear;
int dir;
bool flag;
int idx;

void init(int track_size, int head){
	disk_size = track_size;
	disk_head = head;
	front = rear = 0;
	for (register int i = 0; i < disk_size; ++i){
		disk[i] = false;
	}
	dir = -1;
	flag = false;
	idx = head;
}

void request(int track){
	flag = false;
	disk[track] = true;
	queue[rear++] = track;
}

int fcfs(){
	flag = false;
	while (!disk[queue[front]]){
		++front;
	}
	disk_head = queue[front];
	disk[disk_head] = false;
	return queue[front++];
}

int sstf(){
	register int left = disk_head, right = disk_head;
	flag = false;
	if (disk[disk_head]){
		disk[disk_head] = false;
		return disk_head;
	}
	while (true){
		if (left > 0) --left;
		if (right < disk_size - 1) ++right;

		if (disk[left] || disk[right]){
			if (disk[left] && disk[right]){
				disk_head = left;
				disk[disk_head] = false;
				return disk_head;
			}
			else{
				if (disk[left]){
					disk_head = left;
					disk[disk_head] = false;
					return left;
				}
				else{
					disk_head = right;
					disk[disk_head] = false;
					return right;
				}
			}
		}
	}
	return -1;
}

int look(){
	register int cur = disk_head;
	while (cur >= 0&&cur<disk_size){
		if (disk[cur]){
			idx = disk_head;
			flag = true;
			disk[cur] = false;
			disk_head = cur;	
			return cur;
		}
		cur += dir;
	}
	dir *= -1;
	if (flag){
		cur = idx;
	}
	else{
		cur = disk_head;
	}
	while (cur >= 0 && cur<disk_size){
		if (disk[cur]){
			disk[cur] = false;
			disk_head = cur;
			return cur;
		}
		cur += dir;
	}

	return -1;
}

int clook(){
	flag = false;
	register int cur = disk_head;
	while (!disk[cur]){
		cur -= 1;
		if (cur < 0) cur += disk_size;
	}
	disk[cur] = false;
	disk_head = cur;
	return disk_head;
}



