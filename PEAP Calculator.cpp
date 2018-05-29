//
//  main.cpp
//  Science Project Calculator
//
//  Created by Gavin Ryderon 2/23/16.
//  Copyright © 2016 Gavin Ryder. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int x;
////////////////////////////
int moredata;
int weekChoice;
double gpm = 0;
int cwmin = 0;
////////////////////////////
int w1min = 0;
int w2min = 0;
int w3min = 0;
////////////////////////////
int cwgal = 0;
////////////////////////////
int w1gal = 0;
int w2gal = 0;
int w3gal = 0;
int day;
int controlWeekMinutes[7];
double controlWeekGallons[7];
////////////////////////////
int week1Minutes[7];
double week1Gallons[7];
int week2Minutes[7];
double week2Gallons[7];
int week3Minutes[7];
double week3Gallons[7];

void addMinutesCW()
{
    x=0;
    for(x=0;x<=6; x++)
    {
        cwmin = cwmin + controlWeekMinutes[x];
    }
};
void addGallonsCW()
{
    cwgal = gpm*cwmin;
};
void addMinutes1()
{
    x=0;
    for(x=0;x<=6; x++)
    {
        w1min = w1min + week1Minutes[x];
    }
};

void addGallons1()
{
    w1gal = gpm*w1min;
};
void addMinutes2()
{
    x=0;
    for(x=0;x<=6; x++)
    {
        w2min = w2min + week2Minutes[x];
    }
};

void addGallons2()
{
    w2gal = gpm*w2min;
};
void addMinutes3()
{
    x=0;
    for(x=0;x<=6; x++)
    {
        w3min = w3min + week3Minutes[x];
    }
};

void addGallons3()
{
    w3gal = gpm*w3min;
};

int printArrayCW()
{
    day=0;
     cout<<"You are viewing data for the Control Week"<<endl;
    for(day=0;day<=6; day++)
    {
        cout<<"On Day "<<day+1<<" you used "<<controlWeekGallons[day]<<" gallons of water and spent "<<controlWeekMinutes[day]<<" minutes in the shower"<<endl;
        cout<<" "<<endl;
    }
    cout<<"Scroll up in the console to view anymore data you would like to see"<<endl;
    return 0;
}

int printArray1()
{
    day=0;
    cout<<"You are viewing data for Week 1"<<endl;
    for(day=0;day<=6; day++)
    {
        cout<<"On Day "<<day+1<<" you used "<<week1Gallons[day]<<" gallons of water and spent "<<week1Minutes[day]<<" minutes in the shower"<<endl;
        cout<<" "<<endl;
    }
    cout<<"Scroll up in the console to view anymore data you would like to see"<<endl;
    return 0;

}

int printArray2()
{
    day=0;
    cout<<"You are viewing data for Week 2"<<endl;
    for(day=0;day<=6; day++)
    {
        cout<<"On Day "<<day+1<<" you used "<<week2Gallons[day]<<" gallons of water and spent "<<week2Minutes[day]<<" minutes in the shower"<<endl;
        cout<<" "<<endl;
    }
    cout<<"Scroll up in the console to view anymore data you would like to see"<<endl;
    return 0;

}

int printArray3()
{
    day=0;
    cout<<"You are viewing data for Week 3"<<endl;
    for(day=0;day<=6; day++)
    {
        cout<<"On Day "<<day+1<<" you used "<<week3Gallons[day]<<" gallons of water and spent "<<week3Minutes[day]<<" minutes in the shower"<<endl;
        cout<<" "<<endl;
        
    }
    cout<<"Scroll up in the console to view anymore data you would like to see"<<endl;
    return 0;
}

int chooseWeek ()
{
    cin>>weekChoice;
    int shouldStop = 1;
    
    switch (weekChoice) {
        case 0:
            shouldStop = printArrayCW();
            break;
        case 1:
            shouldStop = printArray1();
            break;
        case 2:
            shouldStop = printArray2();
            break;
        case 3:
            shouldStop = printArray3();
            break;
        default:
            shouldStop = 0;
            break;
    }
    return shouldStop;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    day = 0;
    gpm = 0;
    cout<<"How many gallons does your showerhead use in a minute?"<<endl;
    cin>>gpm;
    cout<<"You will now input data for your Control Week ONLY"<<endl;
    for(day = 0; day<=6; day++)
    {
        cout<<"How many minutes did you spend in the shower on Day "<<day+1<<", Control Week?"<<endl<<endl<<endl;
        cin>>controlWeekMinutes[day];
        controlWeekGallons[day] = controlWeekMinutes[day]*gpm;
    }
    addMinutesCW();
    addGallonsCW();
    cout<<"You spent "<<cwmin<<" total minutes in the shower during your control week"<<endl<<endl<<endl;
    cout<<"You used "<<cwgal<<" total gallons in the shower during your control week"<<endl<<endl<<endl;;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    cout<<"Do you want to continue to input data? (Type 1 to continue or 2 to exit)"<<endl;
    cin>>moredata;
    if(moredata != 1)
    {
        cout<<"Data input ended."<<endl;
        cout<<"Once again, here is your totals after the control week."<<endl;
        cout<<"Your showerhead uses "<<gpm<<" gallons of water every minute."<<endl;
        cout<<"You spent "<<cwmin<<" total minutes in the shower during your control week."<<endl<<endl<<endl;
        cout<<"You used "<<cwgal<<" total gallons in the shower during your control week."<<endl<<endl<<endl;
        cout<<"To view specific data for this week, type 0. If you do not wish to view additional data, type 4"<<endl;
        if (chooseWeek() ==0) return 0;
    }
    cout<<"Now that you have put in your data for your control week, it is time to enter data for Week 1"<<endl;
    
    day = 0;
    for(day = 0; day<=6; day++)
    {
        cout<<"How many minutes did you spend in the shower on Day "<<day+1<<", Week 1?"<<endl<<endl<<endl;
        cin>>week1Minutes[day];
        week1Gallons[day] = week1Minutes[day]*gpm;
    }
    addMinutes1();
    addGallons1();
    cout<<"You spent "<<w1min<<" total minutes in the shower during Week 1"<<endl<<endl<<endl;
    cout<<"You used "<<w1gal<<" total gallons in the shower during Week 1"<<endl<<endl<<endl;;
    cout<<"You saved "<<cwgal-w1gal<<" gallons compared to your control week"<<endl<<endl<<endl;
    cout<<"You spent "<<cwmin-w1min<<" less minutes in the shower compared to your control week"<<endl<<endl<<endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout<<"Do you want to continue to input data? (Type 1 to continue or 2 to exit)"<<endl;
    cin>>moredata;
    if(moredata != 1)
    {
        cout<<"Data input ended."<<endl;
        cout<<"Once again, here is your totals after Week 1."<<endl;
        cout<<"Your showerhead uses "<<gpm<<" gallons of water every minute."<<endl;
        cout<<"You spent "<<w1min<<" total minutes in the shower during Week 1"<<endl<<endl<<endl;
        cout<<"You used "<<w1gal<<" total gallons in the shower during Week 1"<<endl<<endl<<endl;;
        cout<<"You saved "<<cwgal-w1gal<<" gallons compared to your control week"<<endl<<endl<<endl;
        cout<<"You spent "<<cwmin-w1min<<" less minutes in the shower compared to your control week"<<endl<<endl<<endl;
        cout<<"To view specific data for a week, type its number (Control Week is 0). If you do not wish to view additional data, type 4."<<endl;
        if (chooseWeek() ==0) return 0;
    }
    cout<<"Now that you have put in your data for Week 1, it is time to enter data for Week 2"<<endl;
    
    day = 0;
    for(day = 0; day<=6; day++)
    {
        cout<<"How many minutes did you spend in the shower on Day "<<day+1<<", Week 2?"<<endl<<endl<<endl;
        cin>>week2Minutes[day];
        week2Gallons[day] = week2Minutes[day]*gpm;
    }
    addMinutes2();
    addGallons2();
    cout<<"You spent "<<w2min<<" total minutes in the shower during Week 2"<<endl<<endl<<endl;
    cout<<"You used "<<w2gal<<" total gallons in the shower during Week 2"<<endl<<endl<<endl;;
    cout<<"You saved "<<cwgal-w2gal<<" gallons compared to your control week"<<endl<<endl<<endl;
    cout<<"You spent "<<cwmin-w2min<<" less minutes in the shower compared to your control week"<<endl<<endl<<endl;
    cout<<"You saved "<<w1gal-w2gal<<" gallons compared to Week 1"<<endl<<endl<<endl;
    cout<<"You spent "<<w1min-w2min<<" less minutes in  the shower compared to Week 1"<<endl<<endl<<endl;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    cout<<"Do you want to continue to input data? (Type 1 to continue or 2 to exit)"<<endl;
    cin>>moredata;
    if(moredata != 1)
    {
        cout<<"Data input ended."<<endl;
        cout<<"Once again, here is your totals after Week 2."<<endl;
        cout<<"Your showerhead uses "<<gpm<<" gallons of water every minute."<<endl;
        cout<<"You spent "<<w2min<<" total minutes in the shower during Week 2"<<endl<<endl<<endl;
        cout<<"You used "<<w2gal<<" total gallons in the shower during Week 2"<<endl<<endl<<endl;;
        cout<<"You saved "<<cwgal-w2gal<<" gallons compared to your control week"<<endl<<endl<<endl;
        cout<<"You spent "<<cwmin-w2min<<" less minutes in the shower compared to your control week"<<endl<<endl<<endl;
        cout<<"You saved "<<w1gal-w2gal<<" gallons compared to Week 1"<<endl<<endl<<endl;
        cout<<"You spent "<<w1min-w2min<<" less minutes in  the shower compared to Week 1"<<endl<<endl<<endl;
        cout<<"To view specific data for a week, type its number (Control Week is 0). If you do not wish to view additional data, type 4."<<endl;
        if (chooseWeek() ==0) return 0;
    }
    
    cout<<"Now that you have put in your data for your Week 2, it is time to enter data for Week 3"<<endl;
    
    day = 0;
    for(day = 0; day<=6; day++)
    {
        cout<<"How many minutes did you spend in the shower on Day "<<day+1<<", Week 3?"<<endl<<endl<<endl;
        cin>>week3Minutes[day];
        week3Gallons[day] = week3Minutes[day]*gpm;
    }
    addMinutes3();
    addGallons3();
    cout<<"Your showerhead uses "<<gpm<<" gallons of water every minute."<<endl;
    cout<<"You spent "<<w3min<<" total minutes in the shower during Week 3"<<endl<<endl<<endl;
    cout<<"You used "<<w3gal<<" total gallons in the shower during Week 3"<<endl<<endl<<endl;;
    cout<<"You saved "<<cwgal-w3gal<<" gallons compared to your control week"<<endl<<endl<<endl;
    cout<<"You spent "<<cwmin-w3min<<" less minutes in the shower compared to your control week"<<endl<<endl<<endl;
    cout<<"You saved "<<w2gal-w3gal<<" gallons compared to Week 2"<<endl<<endl<<endl;
    cout<<"You spent "<<w2min-w3min<<" less minutes in  the shower compared to Week 2"<<endl<<endl<<endl;
    cout<<"You saved "<<w1gal-w3gal<<" gallons compared to Week 1"<<endl<<endl<<endl;
    cout<<"You spent "<<w1min-w3min<<" less minutes in  the shower compared to Week 1"<<endl<<endl<<endl;
    
    cout<<"This should conclude your data."<<endl;
    
    cout<<"To view specific data for a week, type its number (Control Week is 0). If you do not wish to view additional data, type 4."<<endl;
    if (chooseWeek() ==0) return 0;
}
