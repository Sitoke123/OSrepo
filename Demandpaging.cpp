Simulate the following Demand Paging algorithms 
a)	FIFO Demand Paging
Code:
print("Enter the number of frames: ",end="")
capacity = int(input())
f,fault,top,pf = [],0,0,'No'
print("Enter the reference string: ",end="")
s = list(map(int,input().strip().split()))
print("\nString|Frame →\t",end='')
for i in range(capacity):
    print(i,end=' ')
print("Fault\n   ↓\n")
for i in s:
    if i not in f:
        if len(f)<capacity:
            f.append(i)
        else:
            f[top] = i
            top = (top+1)%capacity
        fault += 1
        pf = 'Yes'
    else:
        pf = 'No'
    print("   %d\t\t"%i,end='')
    for x in f:
        print(x,end=' ')
    for x in range(capacity-len(f)):
        print(' ',end=' ')
    print(" %s"%pf) 
print("\nTotal requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%"%(len(s),fault,(fault/len(s))*100))
Output:
Enter the number of frames: 3
Enter the reference string: 0 1 2 3 0 2 4 6 7 3 2
String|Frame →	0 1 2 Fault
   ↓

   0		0      Yes
   1		0 1    Yes
   2		0 1 2  Yes
   3		3 1 2  Yes
   0		3 0 2  Yes
   2		3 0 2  No
   4		3 0 4  Yes
   6		6 0 4  Yes
   7		6 7 4  Yes
   3		6 7 3  Yes
   2		2 7 3  Yes

Total requests: 11
Total Page Faults: 10
Fault Rate: 90.91%

b)	LRU Demand Paging
Code:
print("Enter the number of frames: ", end="")
capacity = int(input())
f, st, fault, pf = [], [], 0, 'No'
print("Enter the reference string: ", end="")
s = list(map(int, input().strip().split()))
print("\nString|Frame →\t", end='')
for i in range(capacity):
    print(i, end=' ')

print("Fault\n   ↓\n")
for i in s:
    if i not in f:
        if len(f) < capacity:
            f.append(i)
            st.append(len(f)-1)
        else:
            ind = st.pop(0)
            f[ind] = i
            st.append(ind)
        pf = 'Yes'
        fault += 1
    else:
        st.append(st.pop(st.index(f.index(i))))
        pf = 'No'
    print("   %d\t\t" % i, end='')
    for x in f:
        print(x, end=' ')
    for x in range(capacity-len(f)):
        print(' ', end=' ')
    print(" %s" % pf)
print("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%" %
      (len(s), fault, (fault/len(s))*100))

Output:
Enter the number of frames: 3
Enter the reference string: 5 7 6 0 7 1 7 2 0 1 7 1 0
String|Frame →	0 1 2 Fault
   ↓

   5		5      Yes
   7		5 7    Yes
   6		5 7 6  Yes
   0		0 7 6  Yes
   7		0 7 6  No
   1		0 7 1  Yes
   7		0 7 1  No
   2		2 7 1  Yes
   0		2 7 0  Yes
   1		2 1 0  Yes
   7		7 1 0  Yes
   1		7 1 0  No
   0		7 1 0  No

Total Requests: 13
Total Page Faults: 9
Fault Rate: 69.23%

c)	Optimal Page Replacement
Code:
print("Enter the number of frames: ", end="")
capacity = int(input())
f, fault, pf = [], 0, 'No'
print("Enter the reference string: ", end="")
s = list(map(int, input().strip().split()))
print("\nString|Frame →\t", end='')
for i in range(capacity):
    print(i, end=' ')
print("Fault\n   ↓\n")
occurance = [None for i in range(capacity)]
for i in range(len(s)):
    if s[i] not in f:
        if len(f) < capacity:
            f.append(s[i])
        else:
            for x in range(len(f)):
                if f[x] not in s[i+1:]:
                    f[x] = s[i]
                    break
                else:
                    occurance[x] = s[i+1:].index(f[x])
            else:
                f[occurance.index(max(occurance))] = s[i]
        fault += 1
        pf = 'Yes'
    else:
        pf = 'No'
    print("   %d\t\t" % s[i], end='')
    for x in f:
        print(x, end=' ')
    for x in range(capacity-len(f)):
        print(' ', end=' ')
    print(" %s" % pf)
print("\nTotal requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%" %
      (len(s), fault, (fault/len(s))*100))

Output:
Enter the number of frames: 3
Enter the reference string: 5 7 6 0 7 1 7 2 0 1 7 1 0
String|Frame →	0 1 2 Fault
   ↓

   5		5      Yes
   7		5 7    Yes
   6		5 7 6  Yes
   0		0 7 6  Yes
   7		0 7 6  No
   1		0 7 1  Yes
   7		0 7 1  No
   2		0 2 1  Yes
   0		0 2 1  No
   1		0 2 1  No
   7		0 7 1  Yes
   1		0 7 1  No
   0		0 7 1  No

Total requests: 13
Total Page Faults: 7
Fault Rate: 53.85%
