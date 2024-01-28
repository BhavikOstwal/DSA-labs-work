#include<iostream>
using namespace std;

bool check_leap(int year){
    if ((year%100 ==0) && (year%400)==0){
        return true;
    }
    else if ((year%4==0)&&(year%100!=0)){
        return true;
    }
    else{
        return false;
    }
}

void get_day_pd(int& day, int& month, int& year, int& daysInp){
    int month_days;
    int month_arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while (daysInp>0){
        if ((check_leap(year)==1)&&(month==2)){
            month_days = 29;
        }
        else {
            month_days = month_arr[month-1];
        }

        // cout<<month_days<<endl;
        if (daysInp < (month_days-day+1)){    //+1 beacuse when take of 20 jan 2000 and add 11 days it will go to 1 feb instead of 31 jan
            day+=daysInp;
            daysInp=0;
        }
        else {
            daysInp-=month_days-day+1;    //+1 beacuse when 20 jan 2000 and add 12 days it will go to 2 feb instead of 1 feb
            day = 1;
            month++;
            if (month>12){
                month=1;
                year++;
            }
        }
    }
}


int main() {
    int day, month, year, days_inp;
    cout<<"Enter the date "<<endl;
    cin>>day>>month>>year;
    cout<<"Enter the number of days ";
    cin>>days_inp;
    get_day_pd(day, month, year, days_inp);
    cout<<day<<" "<<month<<" "<<year<<endl;
    
    return 0;
}