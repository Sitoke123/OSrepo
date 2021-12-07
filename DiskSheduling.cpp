a)	FIFO disk Scheduling
Code:
size = 8
def FCFS(arr, head):
	seek_count = 0
	distance, cur_track = 0, 0
	for i in range(size):
		cur_track = arr[i]
		distance = abs(cur_track - head)
		seek_count += distance
		head = cur_track
	print("Total number of seek operations = ",seek_count)
	print("Seek Sequence is")
	for i in range(size):
		print(arr[i])
if __name__ == '__main__':
	arr = [ 176, 79, 34, 60,92, 11, 41, 114 ]
	head = 50;
	FCFS(arr, head)

Output:
Total number of seek operations =  510
Seek Sequence is
176
79
34
60
92
11
41
114

b)	SSTF disk Scheduling
Code:
def calculateDifference(queue, head, diff):
	for i in range(len(diff)):
		diff[i][0] = abs(queue[i] - head)
def findMin(diff):
	index = -1
	minimum = 999999999
	for i in range(len(diff)):
		if (not diff[i][1] and
				minimum > diff[i][0]):
			minimum = diff[i][0]
			index = i
	return index
def shortestSeekTimeFirst(request, head):			
		if (len(request) == 0):
			return		
		l = len(request)
		diff = [0] * l
		for i in range(l):
			diff[i] = [0, 0]
		seek_count = 0
		seek_sequence = [0] * (l + 1)		
		for i in range(l):
			seek_sequence[i] = head
			calculateDifference(request, head, diff)
			index = findMin(diff)			
			diff[index][1] = True
			seek_count += diff[index][0]
			head = request[index]
		seek_sequence[len(seek_sequence) - 1] = head		
		print("Total number of seek operations =",seek_count)						
		print("Seek Sequence is")
		for i in range(l + 1):
			print(seek_sequence[i])

if __name__ =="__main__":
	proc = [176, 79, 34, 60,92, 11, 41, 114]
	shortestSeekTimeFirst(proc, 50)

Output:
Total number of seek operations = 204
Seek Sequence is
50
41
34
11
60
79
92
114
176

c)	Scan disk Scheduling
Code:
size = 8
disk_size = 200
def SCAN(arr, head, direction):
	seek_count = 0
	distance, cur_track = 0, 0
	left = []
	right = []
	seek_sequence = []
	if (direction == "left"):
		left.append(0)
	elif (direction == "right"):
		right.append(disk_size - 1)
	for i in range(size):
		if (arr[i] < head):
			left.append(arr[i])
		if (arr[i] > head):
			right.append(arr[i])
	left.sort()
	right.sort()
	run = 2
	while (run != 0):
		if (direction == "left"):
			for i in range(len(left) - 1, -1, -1):
				cur_track = left[i]
				seek_sequence.append(cur_track)
				distance = abs(cur_track - head)
				seek_count += distance
				head = cur_track		
			direction = "right"	
		elif (direction == "right"):
			for i in range(len(right)):
				cur_track = right[i]
				seek_sequence.append(cur_track)
				distance = abs(cur_track - head)
				seek_count += distance
				head = cur_track			
			direction = "left"		
		run -= 1
	print("Total number of seek operations =",seek_count)
	print("Seek Sequence is")
	for i in range(len(seek_sequence)):
		print(seek_sequence[i])
arr = [ 176, 79, 34, 60,92, 11, 41, 114 ]
head = 50
direction = "left"
SCAN(arr, head, direction)

Output:
Total number of seek operations = 226
Seek Sequence is
41
34
11
0
60
79
92
114
176

d)	Look disk Scheduling 
Code:
size = 8
disk_size = 200
def LOOK(arr, head, direction):
    seek_count = 0
    distance = 0
    cur_track = 0
    left = []
    right = []
    seek_sequence = []
    for i in range(size):
        if (arr[i] < head):
            left.append(arr[i])
        if (arr[i] > head):
            right.append(arr[i])
    left.sort()
    right.sort()
    run = 2
    while (run):
        if (direction == "left"):
            for i in range(len(left) - 1, -1, -1):
                cur_track = left[i]
                seek_sequence.append(cur_track)
                distance = abs(cur_track - head)
                seek_count += distance
                head = cur_track
            direction = "right"
        elif (direction == "right"):
            for i in range(len(right)):
                cur_track = right[i]
                seek_sequence.append(cur_track)
                distance = abs(cur_track - head)
                seek_count += distance
                head = cur_track
            direction = "left"
        run -= 1
    print("Total number of seek operations =",seek_count)
    print("Seek Sequence is")
    for i in range(len(seek_sequence)):
        print(seek_sequence[i])
arr = [176, 79, 34, 60, 92, 11, 41, 114]
head = 50
direction = "right"
print("Initial position of head:", head)
LOOK(arr, head, direction)

Output:
Initial position of head: 50
Total number of seek operations = 291
Seek Sequence is
60
79
92
114
176
41
34
11

e)	C-Scan disk Scheduling
Code:
size = 8
disk_size = 200
def CSCAN(arr, head):
	seek_count = 0
	distance = 0
	cur_track = 0
	left = []
	right = []
	seek_sequence = []
	left.append(0)
	right.append(disk_size - 1)
	for i in range(size):
		if (arr[i] < head):
			left.append(arr[i])
		if (arr[i] > head):
			right.append(arr[i])
	left.sort()
	right.sort()
	for i in range(len(right)):
		cur_track = right[i]
		seek_sequence.append(cur_track)

		distance = abs(cur_track - head)
		seek_count += distance
		head = cur_track
	head = 0
	seek_count += (disk_size - 1)
	for i in range(len(left)):
		cur_track = left[i]
		seek_sequence.append(cur_track)
		distance = abs(cur_track - head)
		seek_count += distance
		head = cur_track
	print("Total number of seek operations =",
		seek_count)
	print("Seek Sequence is")
	print(*seek_sequence, sep="\n")
arr = [176, 79, 34, 60,92, 11, 41, 114]
head = 50
print("Initial position of head:", head)
CSCAN(arr, head)

Output:
Initial position of head: 50
Total number of seek operations = 389
Seek Sequence is
60
79
92
114
176
199
0
11
34
41

f)	C-Look disk Scheduling 
Code:
size = 8
disk_size = 200
def CLOOK(arr, head):
    seek_count = 0
    distance = 0
    cur_track = 0
    left = []
    right = []
    seek_sequence = []
    for i in range(size):
        if (arr[i] < head):
            left.append(arr[i])
        if (arr[i] > head):
            right.append(arr[i])
    left.sort()
    right.sort()
    for i in range(len(right)):
        cur_track = right[i]
        seek_sequence.append(cur_track)
        distance = abs(cur_track - head)
        seek_count += distance
        head = cur_track
    seek_count += abs(head - left[0])
    head = left[0]
    for i in range(len(left)):
        cur_track = left[i]
        seek_sequence.append(cur_track)
        distance = abs(cur_track - head)
        seek_count += distance
        head = cur_track
    print("Total number of seek operations =",seek_count)
    print("Seek Sequence is")
    for i in range(len(seek_sequence)):
        print(seek_sequence[i])
arr = [176, 79, 34, 60,92, 11, 41, 114]
head = 50
print("Initial position of head:", head)
CLOOK(arr, head)

Output:
Initial position of head: 50
Total number of seek operations = 321
Seek Sequence is
60
79
92
114
176
11
34
41
