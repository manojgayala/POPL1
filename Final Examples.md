### Example 1
The program is based on matrix multiplication and related tag suggestions.
```
$matrix_mul(int n,int a[][n], int b[][n], int c[][n])	<< void
	for i : (0,n-1)
		for j : (0,n-1)
			c[i][j] = 0;
			for k : (0,n-1)
				c[i][j] += a[i][k]*b[k][j];	///
%

$main() << void
	int n;
	read(@n);
	int a[n][n],b[n][n];
	for i : (0,n-1)
		for j : (0,n-1)
			read(@a[i][j]);	//
	for i : (0,n-1)
		for j : (0,n-1)
			read(@b[i][j]);	//
	
	int c[n][n];
	matrix_mul(n,a,b,c);
	for i : (0,n-1)
		for j : (0,n-1)
			write(c[i]+" ");	/
		write("\n");			/
	return 0;
%
```
The code after compilation would give the suggestion
```
Tip : forAsync i : (0,n-1)
		forAsync j : (0,n-1)
				=> in line 
```

### Example 2
This small piece of code finds a power b and tags help optimize it.
```
$main() << void
	int a,b;
	read(@a,@b);
#number_theory
#exponentiation
int ans = 1;
for i : (0,b)					~ calculation of a power b
	ans= ans*a; /
write(ans);
	return 0;
%
```
The code after compilation would give the following results
```
Tip: {while b>0
	if b&1 ans = ans*a;/
	a = a*a; 
	b=b/2; 	/} in line 2 =>
O(lg(n)) method possible using binary exponentiation
```

### Example 3:
Binary Search Algorithm is implemented in the following example. Given a sorted list of n elements, it prints the index of element we are looking for on finding; else indicates 
that the element is not found.
```
$binarySearch(List elements, int n, int i, int j) << int
    ~ binarySearch function given a number returns its index in the list on existance, else returns -1
    if j >= i
        int mid = i + (j - i) / 2;
        if elements[mid] == n   ~ element n found at index number mid in the list
            return mid;     /
        if elements[mid] > n    ~ element n if exists can be found only in the left part of the list
            ~ recursive call to binarySearch function with diminished range to check for the element
            return binarySearch(elements, n, i, mid - 1);    /
        return binarySearch(elements, n, mid + 1, j); ~ element n if exists can be found only in the right part of the list
    return -1;  ~ element not found: so return -1
%

$main << int
    List>> int elements = [ 1, 6, 11, 17, 23, 76, 134, 219 ]; 
    int i, n = memsize(elements) / memsize(elements[0]);
    write("Enter any element from whose position you want to find: ");
    read(@i);
    int result = binarySearch(elements, i, 0, n - 1);
    ~ if result = -1, string "Element not found" is printed on the console; else prints ""Element found at index: _index_"
    (result == -1) ? write("Element not found") : write("Element found at index: " + result); 
    return 0;
%
```

### Example 4:
This program calculates binomial scan n<sub>C<sub>r </sub></sub> using the formula n<sub>C<sub>r </sub></sub> = n-1<sub>C<sub>r </sub></sub> + n-1<sub>C<sub>r-1 </sub></sub> illustrating the concept of optimization in Tureasy using Tags
```
~ This function calculates binomial coefficient for a given n and r
$findbincoeff(int n, int r) << int
	~ using a tag *checkhere* to optimize the code
	#checkhere
		int result = 0;
		if n<r
			return result;
		/
		else if n==r || r==0
			return result+1;
		/
		else
			return findbincoeff(n-1,r) + findbincoeff(n-1,r-1);	~recursive step
		/
	#!checkhere ~end the tag *checkhere*
%

$main() << void
	int n,r,result;
	write("Enter the values of n and r: ");
	read(@n,@r);
	result = findbinceoff(n,r);
	write("The value of "+n+"C"+r+" = "+result);
%
```
After compiling this code, the suggestions would be like
```
tip: checkhere has result variable unchanged - can be replaced by 0
```

### Example 5:
This program illustrates the Quick Sort algorithm
```
~ This function swaps two elements 
$swap(int a, int b) << void 
	int temp = a; 
	a = b; 
	b = temp; 
%

`` 
This function takes last element as pivot, places the pivot element at its
correct position in sorted array, and places all smaller (smaller than
pivot) to left of pivot and all greater elements to right of pivot 
``
$partition (int arr[], int low, int high) << int
	int pivot = arr[high]; ~ pivot 
	int i = (low - 1); ~ Index of smaller element 
	int j = low;
	while j <= high- 1 
		~ if current element is smaller than the pivot 
		if arr[j] < pivot 
			i++; ~ increment index of smaller element 
			swap(@arr[i], @arr[j]); 
		/
		j++; 
	/
	swap(@arr[i + 1], @arr[high]); 
	return i + 1; 
%

``
The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index
``
$quickSort(int arr[], int low, int high) << void 
	if low < high
		~ pi is partitioning index, arr[p] is now at right place 
		int pi = partition(arr, low, high); 
		~ Separately sort elements before 
		~ partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	/
%

$main() << int 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = 6; 
	quickSort(arr, 0, n-1); 
	write("The sorted array is: "); 
	printArray(arr, n); 
	return 0; 
} 
```

### Example 6:
This example, given a list of words prints them in the Lexicographical Order.
```
$main() << int
    List>> string words;                      ~ List which stores words
    string name, temp;
    int i,n;
    write("Enter the number of words: ");     ~ prompts user to enter number of words 
    read(@n);                                 ~ reads input n from the user
    for i: (1,n)
        write("Enter word " + i + ": ");      ~ prompts user to enter ith word
        read(@name);
        words.append(name);    /              ~ appends the input read from user to the words List
    for i: (0,n-1)
        for j : (i+1,n-1)
            if words[i].cmp(words[j]) > 0     ~ if words[i] > words[j]
                temp = words[i];              ~ string temp holds content of words[i]  
                words[i] = words[j];          ~ words[i] gets content of words[j]   
                words[j] = temp;   /          ~ string words[j] finally holds content of temp 
        /
    /
    write("Lexicographical order of given words: \n");
    for i: (0,n-1)                            ~ print all the elements of List, each on a new line  
        write(words[i] + "\n"); /
    return 0;
%
```

### Example 7:
The following code, given a list of numbers, finds the average, variance and standard deviation.
```
$computeVarAndSD(List << int numbers, float avg, int n) << void
    float sum = 0, variance, std_deviation;
    for i:(0,n-1)
        sum = sum + pow((numbers[i] - avg), 2);   /    
    ~ variable sum stores sum of squares of difference of all numbers from mean(or average)
    variance = sum / (float)n;
    write("\nVariance = " + variance);
    std_deviation = sqrt(variance);
    write("\nStandard Deviation = " + std_deviation);
    return;
%

$main() << int      ~ main function starts here
    int  i, j, n;
    float average, sum = 0;
    List>> int numbers;
    write("Enter the value of N: ");
    read(@n);
    write("Enter all " + n + " integers:\n");
    for i: (0,n-1)      ~ reads all numbers from the user
        read(@j);
        numbers.append(j);   ~ numbers read are appended to the list   
    /
    for i: (0,n-1)
        sum = sum + numbers[i];   /
    ~ at the end of this loop variable sum stores sum of all the numbers
    average = sum / (float) n;
    write("Average of all elements = " + average);  ~ prints average of the number
    computeVarAndSD(numbers,average,n);     ~ function call to compute variance and standard deviation
    return 0;
%
```

### Example 8:
This program adds elements of two arrays which illustrates the concept of local functions

```
$main() << void
	int a[5] = {1,2,3,4,5}
	int b[5] = {6,7,8,9,10}

	~ This local function adds two arrays
	func add = [@] $() << void    ~ @ is for reference and no name is given to function since we have reference
		int c[5];
		for i:(0,4)
			c[i] = a[i]+b[i];
		/
		
		~This local function prints an array
		func print = [@] $(int c[]) << void 
			for i:(0,4)
				write(c[i]+" ");
			/
			write("\n");
		%
		print(c);
	%
	write("The first array is: ");
	print(a);
	write("The second array is: ");
	print(b);
	write("The sum of the two arrays is: ");
	add(a,b);
%
```
The output of this program is 
```
The first array is: 1 2 3 4 5
The second array is: 6 7 8 9 10
The sum of the two arrays is: 7 9 11 13 15
```
The functions **add** and **print** are called local functions. Parameters need not to be passed into local functions due to which a lot of memory can be reserved. *print* can access the variables in the scope of both *main* and *add*. *add* can access the variables in the scope of *main* only.

### Example 9:
This example, given a date, prints its week day if it is valid otherwise informs the user that the date entered is invalid.
```
~ validateDate function returns 1 if given date is valid, otherwise returns 0
$validateDate(int d,int m,int y) << int
    if y>=1800 && y<=2999           ~ check year validity
        if m>=1 && m<=12            ~ check month validity
            if d>=1 && d<=31        ~ check day validity
                if (d!=31) && (m==4 || m==6 || m==9 || m==11)
                    return 1;   /
                else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10|| m==12)
                    return 1;   /
                else if (d>=1 && d<=28) && (m==2)
                    return 1;   /
                else if (d==29) && (m==2) && ((y%400==0) || (y%4==0 && y%100!=0))
                    return 1;   /
                else
                    return 0;   /   ~ invalid day
            /
            else                    ~ invalid day
                return 0;   /
	/	
        else
            return 0;   /           ~ invalid month
    /
    else
        return 0;   /               ~ invalid year
%

$weekDay(int d, int m, int y) << int
    ~ weekDay function given a date, returns a number from 0 to 6, corresponding to Sun, Mon, Tue, Wed, Thurs, Fri, Sat
    int temp = (d+=m<3?(y=y-1):y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
    return temp;
%

$main() << int
    int day, month, year, weekDayNum = 0;
    List>> string dayName = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    ~ dayName is a list containing all weekDays 
    write("Input date (DD MM YYYY): ");         ~ prompts user to enter a day, month and year
    read(@day,@month,@year);
    if validateDate(day,month,year) == 1        ~ checks if the given date is valid
        write("Valid Date: " + day + "-" month + "-" + year);
        weekDayNum = weekDay(day,month,year);   ~ function call to find week day of given date
        write("\nWeek day is: " + dayName[weekDayNum]);
    /
    else
        write("\nInvalid Date");  /
    return 0;
%
```
For input: day = 16, month = 12, year = 2020, the output is:
```
Valid Date: 16-12-2020
Week day is: Wednesday
```

### Example 10:
This program find distance between two points based on the input i.e., if the no of coordinates given are two, the coordinated of the second point are taken to be origin and of two points are given the distance between those two points are calculated illustrating the concept of constructor overloading or multiple constructors
```
*Distance         						  ~ beginning the class
	mem:
		int x1;
		int x2;
		int y1;
		int y2;
	met:
		$pointToOrigin() << int				~ This method calculates the distance between the given point and origin
			return sqrt(pow(x1,2)+pow(y1,2));
		%
		$point1Topoint2() << int			~ This method calculates the distance between the given two points
			return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		%
	con:
		(int x1, int y1, int x2, int y2)  		~constructor with four arguments
			here.x1 = x1;
			here.y1 = y1;
			here.x2 = x2;
			here.y2 = y2;
		%
		(int x1, int y1)				 ~ constructor with two arguments
			here.x1 = x1;
			here.y1 = y1;
		%
*%								 ~ end the class *Distance*

$main()
	int x1,y1,x2,y2;
	write("Count of number of points you want to enter: ");
	int count;
	read(@count);
	if count == 2
		write("Enter the coordinates in the order x,y: ");
		read(@x1,@y1);
		Distance dist = new Distance(x1,y1);
		write("The distance of the given point from origin is: "+ dist.pointToOrigin());
	/
	else if count == 4
		write("Enter the coordinates in the order x1,y1,x2,y2: ");
		read(@x1,@y1,@x2,@y2);
		Distance dist = new Distance(x1,y1,x2,y2);
		write("The distance between the given points is: "+ dist.point1Topoint2());
	/
	else
		write("Enter a valid count!!");
	/
%
```
### Example 11:
This example gives a little sneak-peek into how OOPs can be used to create a user & group management of a system.
This code defines the user and group classes and when root is logged in, creates a admin user who owns system files 
```
*User                       ~ User Class
mem:           
_string name;               ~ name of the user
_int uid;                   ~ user id
_Group primGroup;           ~ primary group of the user,which also owns the same list of files.
_string password;          ~ password for the login.
_List << string ownedfiles;  ~ list of files owned by the user. 

met:
$addToGroup(Group group)
if(System.login.getuid()==0) ~ only when the current user is root.
	group.addUser(here); \
else
	write("not allowed\n"); \	
%
$ownfile(string filename)   ~ to own a new file.
if(System.login.getuid()==0)
	ownedfiles.append(filename);
	primGroup.addfile(filename); \
else
	write("not allowed\n");  \	
%
$changeprimGroup(Group group)   ~ to change primary group 
if(System.login.getuid()==0)
	here.primgroup = primGroup;
	for f : here.files
		primeGroup.addfile(f); \
\		
else
	write("not allowed\n"); \
%
$setpasswd(string password) ~ to set the password for the user.
if(System.login.getuid==0)
	here.password = password; \
else
	write("not allowed\n"); \

con:
(string name,int uid,Group primGroup)
here.name = name;
if(!Userids.isPresent(uid))
	here.uid = uid; \
else
	here.uid = Userids.next(); \	
here.primGroup = primGroup;
for f : here.files
	primeGroup.addfile(f); \
%

(string name)
here.name = name;
here.primGroup = new Group(name);
primGroup.adduser(here);
for f : here.files
	primeGroup.addfile(f); \
here.id = Userids.next();
%

*%

*Superuser inherit User ~ this class is for the root user.
con:
():()
parent.User("root");
uid = 0;
ownedfiles.append(System.files.ALL());
%
*%


*Group    ~ Group Class
mem:
_string groupname;
_List<< User users;
_List<< string files;
_int gid;
met:
$addUser(User user);
if(System.login.getuid()==0);
	users.append(user);   \
else
	write("not allowed\n"); \	
%
$addfile(string file)
if(System.login.getuid()==0)
	files.append(file); \
else
	write("not allowed\n"); \
%
con:
(string groupname,int gid)
here.groupname = groupname;
if(!Groupids.ispresent(gid))
	here.gid = gid; \
else
	here.gid = Groupids.next();	\
%
(string groupname)
here.groupname = groupname;
here.gid = Groupids.next();
%
*%


$main() << void
Superuser root = new Superuser();
System.setlogin(root);
User admin = new User("admin");
Group gsys = new User("sys_group");
admin.addToGroup(gsys);
for file : System.files.get("/home/sys")
	admin.ownfile(file.getname());
admin.changeprimGroup(gsys);

System.setlogin(admin);
admin.setpasswd();          ~ this prints not allowed as the current login is not root.
admin.getname();
admin.getownedfiles()
```
Output :
```
not allowed
admin
/home/sys/file1 
...
```
`...` ->remaining files in the list.

### Example 12:
This example reads a file containing email in complete text form. The program uses file handling and string operations to output a file containing names of pepele you recieved mails from and another file containing the name of organizations from which you recieved mail.
```
$main() << void
	FILE fptr1,fptr2,fptr3;
	string path, lineData, temp;
	int Pos;
	List>> string info;
	read(@path); 	~inputs name of file containg emails data
	
	fptr1.open(path,"r");
	fptr2.open("NameID.txt","w");
	fptr3.open("Org.txt","w");
	
	while((lineData = fptr1.readLine()) != EOF)	~readline the file line by line till end of file
		Pos = lineData.Find("From");
		if Pos==0
			~lineData will be in the form From: abcd@iith.ac.in  "Hi ...."
			info = lineData[1].split("@");
			~ the list in info will be of the form ["UserID","Org.domain"]
			write(info[0],fptr2);	~UserID will bw written into this file.
			
			temp = info[1].split(".");
			write(temp[0],fptr3);	~Domain name will be written into this file
			
			info.clear()	~removes all items in the list
			
		/	 	
	/
	fptr3.close();
	fptr2.close();
	fptr1.close();
%
```


### Example 13:
This is a program which calculates roots of a quadratic equation, but can be easily extended to larger polynomials
```
$main() << void
	
	string line[20];  
	double  root1,root2;

	write("Enter the quadratic equation in the form of a0*x*x + a1*x + a2 \n");  
	read(@line);

	List>> string data = line.split("*x");
	~ above actions gives ["a0"," + a1"," + a2"]
	
	                                                              
	for i: data.WordCount()	~this iterates throught size of data list
		int (a+str(i)) = (int) data[i].igonre({" ","+"});	/
	
	int discriminant  =  a1*a1  -  4*a0*a2;

	if d  <  0    
	~complex roots, i is for iota (√-1, square root of -1)  
	write("First root = " +  -b/(double)(2*a) + "+ i" + sqrt(-d)/(2*a));  
	write("First root = " +  -b/(double)(2*a) + "- i" + sqrt(-d)/(2*a)); 
	/  
	else   ~real roots  
		root1  =  (-b  +  sqrt(d))/(2*a);  
		root2  =  (-b  -  sqrt(d))/(2*a);

		write("First root = " + root1);  
		write("Second root = " + root2); 
	/
	 
}
%
```

### Example 14:
Using tags to find mistakes or to improve the efficiency of code.

```
# DijkstraPath
# MinPriorityQueue
$ dijkstra(Graph G, int start, int end, int n) << void			~ Graph class is taken for granted
	PriorityQueue >> Pair >> (int,int) q;	~it is declared in this way so that weight is given first preference then vertex number
	int vis[n],dist[n],close[n];
	
	for i : (0,n) 
		vis[i]=0;
		close[i]=0;
		dist[i] = INT_MAX; /
	
	dist[start] = 0;
	q.enqueue((0,start));	
	close[start]=1;
	 					
	List >> Pair >> (int,int) neighbors;
	
	while !q.empty()
		Pair >> (int,int) p = q.dequeue();
		vis[current] = 1;
		
		neighbors = G[p.value];	~neighbors will be a pair with key=weight and value=vertex
		
		for (i,j) : neighbors
			int newWeight = i + dist[j];
			
			if !vis[i] && newWeight < dist[j]
				dist[j] = newWeight;		~line 23
				visited[j] = 1;
				
				if !close[j]					
					q.enque(newWeight,j);/	
				else
					q.update((i,j),(newWeight,j));		/
					/
					/
					/

	write("Shortest distance is: ",dist[end]);
			
%
#! MinPriorityQueue
#! DijkstraPath
``
Tip: In line 23, the declaration could be done outside loop to save more stack memory
Criticl: In line 24, in for loop vertices shoul not be marked as visited / does not meet Dijkstra's Algorithm.
``
```


### Example 15
Program for merge sort
```
merge(int arr[], int l, int m, int r) << void
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2]; ~ create temp arrays 
    ~ Copy data to temp arrays L[] and R[] 
    for i:(0,n1)
        L[i] = arr[l + i]; /
    for j:(0,
        R[j] = arr[m + 1 + j]; /
 
    ~Merge the temp arrays back into arr[l..r]
    i = 0; ~ Initial index of first subarray
    j = 0; ~ Initial index of second subarray
    k = l; ~ Initial index of merged subarray
    while i < n1 && j < n2 
        if (L[i] <= R[j]) 
            arr[k] = L[i];
            i++;  /
       /
        else 
            arr[k] = R[j];
            j++;  /
        k++;
      /
    while i < n1        ~Copy the remaining elements of L[], if there are any 
        arr[k] = L[i];
        i++;
        k++;
       /
    while j < n2          ~Copy the remaining elements of R[], if there are any 
        arr[k] = R[j];
        j++;
        k++;
       /
 %
~ l is for left index and r is right index of the sub-array of arr to be sorted 
# divide and conquer
$mergeSort(int arr[], int l, int r) << void
    if l < r                 ~ Same as (l+r)/2, but avoids overflow for
                             ~ large l and h
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
    /
 %
 #divide and conquer
~UTILITY FUNCTIONS 
~Function to print an array 
printArray(int A[], int size)<< void
    int i;
    for i:(0,size) 
        write(A[i]+" "); /
    write("\n");
%
~ Driver code 
%main()<< int
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size =6;
 
    write("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);
 
    write("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
%
```
After compiling the code, suggestions will be like
```
Tip : Parallel function call can be done at lines 640 and 641. 
```

### Example 16:
Tiling problem using divide and conquer
 ```
int size_of_grid, b, a, cnt = 0;

$place(int @a[][],int x1, int y1, int x2,int y2, int x3, int y3) << void	~ Placing tile at the given coordinates
    cnt++;
    a[x1][y1] = cnt;
    a[x2][y2] = cnt;
    a[x3][y3] = cnt;
%

$tile(int @a[][],int n, int x, int y)<< int
    int r,i,j, c;
    if n == 2
        cnt++;
        for i: (0,n)
            for j: (0,n)
                if a[x + i][y + j] == 0
                    a[x + i][y + j] = cnt; /
            /
        /
    /
    return 0;
   	i=j=0;
    ~ finding hole location
    for i:(x,n+x) 
        for j:(y,y+n) 
            if a[i][j] != 0
                r = i;
                c = j; / 
        /	/
    if r < x + n / 2 && c < y + n / 2				~ If missing tile is in first quadrant
        place(a,x + n / 2, y + (n / 2) - 1, x + n / 2,y + n / 2, x + n / 2 - 1, y + n / 2);	/
  
    else if r >= x + n / 2 && c < y + n / 2			~ If missing Tile is in 2st quadrant
        place(a,x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1);	/
 
    else if r < x + n / 2 && c >= y + n / 2			~ If missing Tile is in 3st quadrant
        place(a,x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);	/
 
    else if r >= x + n / 2 && c >= y + n / 	~ If missing Tile is in 4st quadrant
        place(a,x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1);	/    
    tile(n / 2, x, y + n / 2);			~ diving it again in 4 quadrants
    tile(n / 2, x, y);
    tile(n / 2, x + n / 2, y);
    tile(n / 2, x + n / 2, y + n / 2);
    return 0;
%

$main() <<void
    int x;
    read(x);
    size_of_grid = x;
    int a[x][x];
    for (0,x)
	for j:(0,x)
            a[x][x]=0;	/
		/
    a = 0, b = 0;     ~Here tile can not be placed
    a[a][b] = -1;
    tile(@a,size_of_grid, 0, 0);
    for i: (0,size_of_grid)
        for j:[0,size_of_grid]
            write(a[i][j] + "\t");		~printing output
        /
        write("\n"),
    /
%
```


### Example 17
This example takes in scores after each over in a cricket match and calculates the probabilty of winning for the team playing in the second inning.
```
static int runWeight =1, wicketWeight = -15;	~assumed weights

CalculateProb(int RunDiff, int wickets, int total1, int total2) << float

	int cutoff = RunDiff*runWeight + wickets*wicketWeight;
	int avg = (total1 + toatal2)/2;
	
	float prob = 50 + math.ln( (total1 + (cutoff/avg))/total2 );
	~math is a built in library, ln is natural logarithm
	
	write("chance of winnig for second team is" + prob);
%

$main() << void
	FILE fptr1,fptr2;
	int total1 = 0, total2 = 0, over, runs, wickets = 0;
	string line;
	List>> int data;
	
	int runWeight =1, wicketWeight = -15;	~assumed weights
	
	fptr1 = fptr1.open("firstInning.txt","r");
	fptr2 = fptr2.open("secondInning.txt","w");
	
	while( (line = fptr.readline()) != EOF)
		data = (int) line.split(" ");
		~data will be of the form ["OverNumber", "Runs in that over", Wicket in that over"]
		total2 += data[1];
		
		~we wait for user input for 2nd inning in that over
		
		read(@over,@runs,@wickets);
		total1 += runs;
		
		write(over,runs,wickets,fptr2);	~writes into "secondInnings"

		CalculateProb(runs-data[1],wicket,total1,total2);
		
	/
	fptr1.close();
	fptr2.close();
	
%
``` 

### Example 18
Program to find edit distance of two strings using dynamic programming

```
$min(int a, int b, int c) << int           ~to find min of three numbers
	if a>b
		a=b;  /
	if a>c
		a=c;  /
	return a;
%
#dynamic_programming
$editDistDP(string @str1, string @str2, int m, int n) <<int     ~edit distance function
    int dp[m + 1][n + 1]; 
    for i:(0,m)
        for j:(0,n) 
            if i == 0
                dp[i][j] = j; / 
            else if j == 0
                dp[i][j] = i; /

            else if str1[i - 1] == str2[j - 1] 
                dp[i][j] = dp[i - 1][j - 1];    /
  
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j],dp[i - 1][j - 1]);   /
        /
    /
    return dp[m][n]; 
%
#!dynamic_programming

$main()<< void
	string s1, s2;
	read(s1);
	read( s2);
	int n1=strlen(s1);
	int n2=strlen(s2);
	write(editDistDP(s1,s2,n1,n2));
%

```
