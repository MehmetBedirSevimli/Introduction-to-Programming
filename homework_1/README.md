

INTRODUCTION TO PROGRAMMING

HOMEWORK - 1

Create a struct called time.  Let 
this struct contain four variables of type **int hour**, **int minute**, **int second** and **long total\_second**. 

Enter the hours, minutes, seconds from the keyboard in the format 12:59:59 and store them in a variable of type **struct Time**. 

**NOTE: Check that the entered hour, minute, second values are greater than 60 and less than 0.** 

Store the time struct type variable entered in the main program in the variable total\_seconds by calculating the seconds according to the formula below. 

Total seconds formula: 

long totalsecs= t1.hour\*3600+t1.minute\*60+t1.second //t1 variable is considered as struct time type.

NOTE: variable names will not be a,b,c,x,y,z,t1,t2 etc.

**In order for your assignment to be evaluated, you must have made the same screen output as below. Do not try to process differently.**

Sample screen output :

Enter the time in Hours:Minutes:Seconds: 12:34:05

Values calculated in seconds: 45245

NOTE: Values not entered as Seconds:Minutes:Seconds will not be accepted. Do not enter the hour, enter the minute, enter the second.

Sample screen output :

Enter the time in Hours:Minutes:Seconds : 55:104:505

the entered time value 55 has been entered incorrectly.

the entered minute value 104 has been entered incorrectly.

the entered second value 505 was entered incorrectly.

End of PROGRAM. 
