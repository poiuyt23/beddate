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

Today is Sweetmorn Third day of Discord in the year of 3192
I have updated this for most likely the last time but it's 
a cute little reminder ot times gone by. This was originally
a BeOS program and very buggy by the look.  I have finished
noodling about for the moment and might push it up to github
Who Knows?

WHD 3/17/26
*/


#include <iostream>
#include <ctime>

void systojul(int&,int&);
void jultodis(int,int);
//``int exp (int, int);
void teens (int dayoseason);

int main()
{	

	int julday;						//Number of days into year
	int disyear;	
	systojul(julday,disyear);
	jultodis(julday,disyear);
	return 0;

}
	
void systojul(int& julday, int& disyear) {
    std::time_t now = std::time(nullptr);
    std::tm* ptr = std::localtime(&now);
    
    char buf1[6] = {0};  // Extra space for safety
    
    std::strftime(buf1, sizeof(buf1), "%j", ptr);
    julday = std::atoi(buf1);  // Much simpler than manual parsing!
    
    // Get year
    std::strftime(buf1, sizeof(buf1), "%Y", ptr);
    int year = std::atoi(buf1);
    
    disyear = year + 1166;
}

  void jultodis(int julday, int disyear) {
    bool tibsday = false;
    int dayoseason = 0, dayoweek = 0, intseason = 0, tens, ones;
    
    // Test for "leap year" (Discordian leap years end in 2)
    if ((disyear % 4 == 2)) tibsday = true;
    
    // FIXED: Check for Tib's Day BEFORE decrementing julday
    if (tibsday && julday == 59) {
        std::cout << "\nIt is St. Tib's day, " << disyear << std::endl;
        return;
    }
    
    // Account for Tib's day if past it
    if (tibsday && (julday > 59)) {
        julday--;
    }
    
    dayoweek = (julday -1)  % 5;
    std::cout << "Today is ";
    switch (dayoweek) {
        case 0: std::cout << "Sweetmorn ";
                break;
        case 1: std::cout << "Boomtime ";
                break;
        case 2: std::cout << "Pungenday ";
                break;
        case 3: std::cout << "Prickle-Prickle ";
                break;
        case 4: std::cout << "Setting Orange ";
                break;
        default: std::cout << "Application broken!!! shoot programmer!";
                 break;
    }
    
    dayoseason = (julday % 73);
    if (dayoseason == 0) dayoseason = 73;
    
    tens = dayoseason / 10;
    ones = dayoseason % 10;
    
    switch (tens) {
        case 0: 
            break;
        case 1:
            teens(dayoseason);
            break;
        case 2:
            if (ones == 0) std::cout << "the Twentieth day of ";
            else std::cout << "the Twenty-";
            break;
        case 3:
            if (ones == 0) std::cout << "the Thirtieth day of ";
            else std::cout << "the Thirty-";
            break;
        case 4:
            if (ones == 0) std::cout << "the Fortieth day of ";
            else std::cout << "the Forty-";
            break;
        case 5:
            if (ones == 0) std::cout << "the Fiftieth day of ";
            else std::cout << "the Fifty-";
            break;
        case 6:
            if (ones == 0) std::cout << "the Sixtieth day of ";
            else std::cout << "the Sixty-";
            break;
        case 7:
            if (ones == 0) std::cout << "the Seventieth day of ";
            else std::cout << "the Seventy-";
            break;
        default:
            teens(dayoseason);
            break;
    }
    
    if (tens != 1) {
        if (tens == 0) std::cout << "the ";
        switch (ones) {
            case 1: std::cout << "First day of ";
                    break;
            case 2: std::cout << "Second day of ";
                    break;
            case 3: std::cout << "Third day of ";
                    break;
            case 4: std::cout << "Fourth day of ";
                    break;
            case 5: std::cout << "Fifth day of ";
                    break;
            case 6: std::cout << "Sixth day of ";
                    break;
            case 7: std::cout << "Seventh day of ";
                    break;
            case 8: std::cout << "Eighth day of ";
                    break;
            case 9: std::cout << "Ninth day of ";
                    break;
        }
    }
    
    // FIXED: intseason was never calculated in original code
    intseason = julday / 73;
    
    switch (intseason) {
        case 0: std::cout << "Chaos ";
                break;
        case 1: std::cout << "Discord ";
                break;
        case 2: std::cout << "Confusion ";
                break;
        case 3: std::cout << "Bureaucracy ";
                break;
        default: std::cout << "The Aftermath ";
    }
    
    std::cout << "in the year of " << disyear << std::endl;
}

void teens(int dayoseason) {
    switch (dayoseason) {
        case 10: std::cout << "the Tenth day of ";
                 break;
        case 11: std::cout << "the Eleventh day of ";
                 break;
        case 12: std::cout << "the Twelfth day of ";
                 break;
        case 13: std::cout << "the Thirteenth day of ";
                 break;
        case 14: std::cout << "the Fourteenth day of ";
                 break;
        case 15: std::cout << "the Fifteenth day of ";
                 break;
        case 16: std::cout << "the Sixteenth day of ";
                 break;
        case 17: std::cout << "the Seventeenth day of ";
                 break;
        case 18: std::cout << "the Eighteenth day of ";
                 break;
        case 19: std::cout << "the Nineteenth day of ";
                 break;
    }
}
