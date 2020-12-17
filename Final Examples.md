### Example 1:
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
        else
            return 0;   /           ~ invalid month
    else
        return 0;   /               ~ invalid year
%

$weekDay(int d, int m, int y) << int
    ~ weekDay function given a date, returns a number from 0 to 6, corresponding to Sun, Mon, Tue, Wed, Thurs, Fri, Sat
    int temp = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
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
### Example 2:
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
### Example 3:
The following code, given a list of numbers, find the average, variance and standard deviation.
```
$computeVarAndSD(List numbers, float avg, int n) << void
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
### Example 4:
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
    int i, n = sizeof(elements) / sizeof(elements[0]);
    write("Enter any element from whose position you want to find: ");
    read(@i);
    int result = binarySearch(elements, i, 0, n - 1);
    ~ if result = -1, string "Element not found" is printed on the console; else prints ""Element found at index: _index_"
    (result == -1) ? write("Element not found") : write("Element found at index: " + result); 
    return 0;
%
```
