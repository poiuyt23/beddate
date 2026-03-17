/* Discordian calender for BeOS done 9.3.99 
(Sweetmorn the 27th day of the season of Bureaucracy 3165)
WHD source Released 9.13.99
Revised (programmer's brain borken) 9.17.99
(Sweetmorn the 37th day of the season of Bureaucracy 3165)
It is gregorian y2k compliant (if you are) but it is not
gregorian y2k1c compliant (unless you are).  Try 
alert "`ddate`" from the command line for fun.  
Revised 10.21.99
(Setting Orange Second day of Chaos in the year of 3165)
Rewrote the Season Day part of the program so it can spit
out lots of words instead of numbers. Also fixed a 0 day bug
(see above)  This is in preparation for a GUI version. 
*/


#include <iostream.h>
#include <time.h>

void systojul(int&,int&);
void jultodis(int,int);
int exp (int, int);
void teens (int dayoseason);

int main()
{	

	int julday;						//Number of days into year
	int disyear;	
	systojul(julday,disyear);
	jultodis(julday,disyear);
	return 0;

}
	
void systojul(int& julday, int& disyear)	//returns julian day and discordian year
{											//from system BIOS
	unsigned long now=0 ,year=0;				//Julian calender
	struct tm *ptr;
	char *c, buf1 [5] = "0000";
	int i,j=0, test;					//counters, test to see if number is 0
	time (&now);						// record current time
	ptr = localtime (&now);				// 
	c=asctime(ptr);
	strftime(buf1,5,"%j",ptr);			// Put Julian days in Buf1 Buf(one)
	for (i = 4 ; i > -1 ; i--) 			// Get Julian day into int julday
	{
		test = int (buf1[i]);
		if (test != 0) 
		{
			julday += int ((buf1[i]-48)*(exp (10,j)));
			j++;
		}
	}
	strftime(buf1,5,"%Y",ptr);
	j=0;
	for (i = 4; i > -1; i--)			//Get bios year into year
	{
		test = int (buf1[i]);
		if (test !=0)
		{
			year += int (buf1[i]-48)*(exp (10,j));
			j++;
		}
	}
	disyear = year + 1166;				// translate year to dis year
}
	
inline int exp (int number, int exponent)		// a simple exponentiator
/* this was written to avoid including math.h.  Seemed like a lot to add
for a relatively simple expression*/ 
{
	int result = number;
	if (exponent == 0) return 1;
	if (exponent == 1) return number;
	while (exponent > 1)
	{
		result *= number;
		exponent --;
	}
	return result;
}
		

	
void jultodis (int julday, int disyear)	// makes julian days into discordian info and prints out.
{	
	bool tibsday = false;
	int dayoseason=0 ,dayoweek=0 ,intseason=0, tens, ones;
	if ((disyear%4 == 2)) tibsday = true;		// test for "leap year"
	if (tibsday && (julday > 59)) 				// Account for Tib's day
	{
		julday--;
		if (julday==59) 						// test for Tib's day
		{
			cout << "\nIt is St. Tib's day, " << disyear << endl;
			return;
		}
		
	}
	dayoweek = julday % 5;
	cout << "Today is ";
	switch (dayoweek)
	{
		case 0:	cout << "Sweetmorn ";
				break;
		case 1: cout << "Boomtime ";
				break;
		case 2:	cout << "Pungenday ";
				break;
		case 3: cout << "Prickle-Pickle ";
				break;
		case 4: cout << "Setting Orange ";
				break;
		default : cout << "Application broken!!! shoot programmer!";
				break;
	}
	dayoseason = (julday%73);
	if (dayoseason == 0) dayoseason = 73; 
	tens = dayoseason /10;
	ones = dayoseason % 10;
	switch (tens)
	{
		case 0: 
			break;
		case 2:
			if (ones == 0) cout <<"the Twentieth day of ";
			else cout << "the Twenty-";
			break;
		case 3:
			if (ones == 0) cout <<"the Thirtieth day of ";
			else cout << "the Thirty-";
			break;
		case 4:
			if (ones == 0) cout <<"the Fortieth day of ";
			else cout << "the Fourty-";
			break;
		case 5:
			if (ones == 0) cout <<"the Fiftieth day of ";
			else cout << "the Fifty-";
			break;
		case 6:
			if (ones == 0) cout <<"the Sixtieth day of ";
			else cout << "the Sixty-";
			break;
		case 7:
			if (ones == 0) cout <<"the Seventieth day of ";
			else cout << "the Seventy-";
			break;
		default:
			teens(dayoseason);	
			break;
	}
	if (tens !=1)
	{
		switch (ones)
		{
			case 1:
				cout << "First day of ";
				break;
			case 2:
				cout << "Second day of ";
				break;
			case 3:
				cout << "Third day of ";
				break;
			case 4:
				cout << "Fourth day of ";
				break;
			case 5:
				cout << "Fifth day of ";
				break;
			case 6:
				cout << "Sixth day of ";
				break;
			case 7:
				cout << "Seventh day of ";
				break;
			case 8:
				cout << "Eigth day of ";
				break;
			case 9:
				cout << "Ninth day of ";
				break;
		}
	}
	switch (intseason)
	{
		case 0: cout <<  "Chaos ";
			break;
		case 1: cout <<  "Dischord ";
			break;
		case 2: cout <<  "Confusion ";
			break;
		case 3: cout <<  "Bureaucracy ";
			break;	
		default : cout <<  "The Aftermath ";
	}

	cout << "in the year of " << disyear;
	cout << endl;
}

void teens (int dayoseason)
{
	switch (dayoseason)
	{
		case 10:
			cout << "Tenth day of ";
			break;
		case 11:
			cout << "Eleventh day of ";
			break;
		case 12:
			cout << "Twelth day of ";
			break;
		case 13:
			cout << "Thirteenth day of ";
			break;
		case 14:
			cout << "Fourteenth day of ";
			break;
		case 15:
			cout << "Fifteenth day of ";
			break;
		case 16:
			cout << "Sixteenth day of ";
			break;
		case 17:
			cout << "Seventeenth day of ";
			break;
		case 18:
			cout << "Eithteenth day of ";
			break;
		case 19:
			cout << "Ninteenth day of ";
			break;
	}
}
		
