```
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
    int temp = 0;
    temp = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
    return temp;
%

$main() << int
    int day, month, year, weekDayNum = 0;
    List>>string dayName = ["Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    write("Input date (DD MM YYYY): ");
    read(@day,@month,@year);
    if validateDate(day,month,year) == 1
        write("Valid Date: " + day + "-" month + "-" + year);
        weekDayNum = weekDay(day,month,year);
        write("\nWeek day is: " + dayName[weekDayNum]);   /
    else
        write("\nInvalid Date");  /
    return 0;
%
```

```
$main() << int
    List>>string words;
    string name, temp;
    int i,n;
    write("Enter the number of strings: ");
    read(@n);
    for i: (1,n)
        write("Enter word " + i + ": ");
        read(@name);
        words.append(name);    /
    for i: (0,n-1)
        for j : (i+1,n-1)
            if words[i].strcmp(words[j]) > 0
                temp.strcpy(words[i]);
                words[i].strcpy(words[j]);
                words[j].strcpy(temp);   /
        /
    /
    write("Lexicographical order of given words: \n");
    for i: (0,n-1)
        write(words[i] + "\n"); /
    return 0;
%
```
