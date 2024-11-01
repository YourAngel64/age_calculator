#ifndef BUTTONFUNCTIONS
#define BUTTONFUNCTIONS

#include <chrono>
#include "main.hpp"


//This fucntion here is just to test the std::function arguments i used for the bottons
void testFunction(std::string_view name){
    cout << "This is just a test\n" << " " << name;
}

/*
stringToDate will take 3 arguments, 
- std::string_view dob - a string view to the dob
- int iterStart - First char we want to extract
- int iterEnd- Last char we want to stract

and it will return those char converted into int
Chars should be numbers 
*/
int stringToDate(std::string_view dob, int iterStart, int iterEnd){
    std::string string;
    for(int i = iterStart; i < iterEnd; ++i){
        string.push_back(dob[i]);
    }
    return std::stoi(string);
}


/*
Converts chrono year_month_day type into int year, int month, int day
It returns a tuple with the values in the same order
*/
std::tuple<int, int, int> chronoDateToInt(std::chrono::year_month_day today){
    int year = static_cast<int>(today.year());  
    int month = static_cast<unsigned>(today.month());
    int day = static_cast<unsigned>(today.day());

    std::tuple<int, int, int> myTuple(year, month, day);
    return myTuple;
}


/*
getAgeFromYYYY will calculate the age.
It will return the calculated age
Arguments:
- std::String_view dob - a string view to the dob of the user
- std::tuple<int, int, int> tuple_today - a tuple with y, m, d of the PRESENT DATE (get it from chronoDateToInt func)
- bool isYYYY - if true date has to be YYYY/MM/DD. If false then date should be MM/DD/YYYY
*/
int getAgeFromYYYY(std::string_view dob, std::tuple<int, int, int> tuple_today, bool isYYYY){
    
    int year, month, day;

    if(isYYYY){
        year = stringToDate(dob, 0, 4);
        month = stringToDate(dob, 5, 7);
        day = stringToDate(dob, 8, 10);
    }
    else{
        //"08/04/2006"
        month = stringToDate(dob, 0, 2);
        day = stringToDate(dob, 3, 5);
        year = stringToDate(dob, 6, 10);
    }

    int year_today, month_today, day_today;
    std::tie(year_today, month_today, day_today) = tuple_today;
   
    //age that we will return
    int age{year_today - year};
    
    //difference gonna be used to see if we need to change age
    int month_difference{month_today - month};

    if(month_difference < 0){
        --age;
    }
    else if(month_difference == 0){
        int day_difference{day_today - day};

        if(day_difference < 0){
            --age;
        }
    }

    return age;
}

int calculateAge(std::string_view dob){
    std::chrono::time_point now = std::chrono::system_clock::now();
    std::chrono::time_point date = std::chrono::time_point_cast<std::chrono::days>(now);
    std::chrono::year_month_day ymd = std::chrono::year_month_day(date);


    //converts ymd date into three different variables with int
    std::tuple<int, int, int> tuple_today;
    tuple_today = chronoDateToInt(ymd);

    //checks if is YYYY/MM/DD or MM/DD/YYYY
    int i = 0;
    for(char character: dob){
        if(character == '/')
            break;
        ++i;
    }

    int age;

    switch(i){
        case 4:
            age = getAgeFromYYYY(dob, tuple_today, true);
            return age;
            break;
        case 2:
            age = getAgeFromYYYY(dob, tuple_today, false);
            return age;
            break;
        default:
            return -1;
            break;
    } 
}


/*
Function will take
- std::string_view dob - a string view to the user's dob to do all the calculations above funct
- sf::RenderWindow *app - a pointer to the RenderWindow in order to render the results into the screen
*/
std::string renderAge(std::string_view dob){
    int age = calculateAge(dob);
    std::string age_string = std::to_string(age);
    return age_string;
}


#endif