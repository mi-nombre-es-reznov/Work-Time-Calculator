// Nicholas Perez-Aguilar
// Start Date: 21 March 2019
/* 
    Description: This will be a program that will compute times to display how many hours/minutes you worked, with time on/off. The program
    will ask the user if for their start and end times, seperating a space between hours and minutes. The prgram will display an option for the
    user to enter breaks in and have those calculated in the time off from working. Depending on the data that the system holds, only certain
    information will be displayed, to avoid redundancy.
*/

#include <iostream>
#include <string>
using namespace std;

// Call functions
void store_break_times(int, int, int, int, int);
int get_time_period(int);
string get_time_end_adjust(bool, int);

// Global variables
int out_break_hr_s, out_break_min_s, out_break_hr_e, out_break_min_e;
int arr_times_hr_s[5] = {0, 0, 0, 0, 0};
int arr_times_min_s[5] = {0, 0, 0, 0, 0};
int arr_times_hr_e[5] = {0, 0, 0, 0, 0};
int arr_times_min_e[5] = {0, 0, 0, 0, 0};
char am_pm_array[5];
char am_pm_start_val, am_pm_end_val;
string start_am_pm, end_am_pm, bs1, bs2, bs3, bs4, bs5, be1, be2, be3, be4, be5;
int breaks_start[5] = {0, 0, 0, 0, 0};
int breaks_end[5] = {0, 0, 0, 0, 0};
bool array_type = false;
string array_types_times_s[5];
string array_types_times_e[5];

int main()
{
    string name;
    int start_hr, end_hr, breaks_hr_start, breaks_hr_end, break_count = 0, breaks_temp_start = 0, breaks_temp_end = 0, total_time = 0;
    int start_min, end_min, breaks_min_start, breaks_min_end, sub_time;
    int breaks_range[5] = {0, 0, 0, 0, 0};
    int tot_num_hr = 0, tot_num_min = 0, tot_sub_hr = 0, tot_sub_min = 0;
    char again, ask_break;
    bool flag = false, asked_already = false, am_pm_bool = false;
    
    // Get name for now, for a more personal experience throughout the program.
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << endl << endl;
    system("CLS");
    
    // For later use of rerunning program and correctly reassigning variables
    am_pm_bool = false;
    
    // Give format for time at top
    cout << "\t\t\t\t\tif (8:20), then enter -> 8 20" << endl << endl << endl;
    
    // Ask for start hour, 24 hr format.
    do
    {
        cout << "Please enter your start time: ";
        cin >> start_hr >> start_min;

    } while(start_hr < 0 || start_hr > 12 || start_min < 0 || start_min > 59);
    
    start_hr = get_time_period(start_hr);
    
    // Ask for ending hour, 24 hr format.
    do
    {
        cout << "Please enter your end time: ";
        cin >> end_hr >> end_min;
        cout << endl;
        
    } while(end_hr < 0 || end_hr > 12 || end_min < 0 || end_min > 59);
    
    end_hr = get_time_period(end_hr);
    
    // Begin loop for breaks. Ask for number of breaks during work day, not to exceed 5. Place in 2 arrays (hr and min).
    do
    {
        // Ask if there are any breaks that want to be recorded
        if(asked_already == false)
        {
            cout << "Did you take any breaks that you want to record? (y/n) ";
            cin >> ask_break;
            ask_break = tolower(ask_break);
            asked_already = true;
            cout << endl << endl;
        }
        
        // If user wants to ask break, allow for it.
        if(ask_break == 'y')
        {
            // Change bool for array usage
            am_pm_bool = true;
            
            // Ask for lunch hour start, 24 hr format.
            do
            {
                cout << "Started break " << (break_count + 1) << ": ";
                cin >> breaks_hr_start >> breaks_min_start;
                cout << endl;
                
            } while(breaks_hr_start < 0 || breaks_hr_start > 12 || breaks_min_start < 0 || breaks_min_start > 59);
            
            breaks_hr_start = get_time_period(breaks_hr_start);
            
            // Ask for lunch hour end, 24 hr format.
            do
            {
                cout << "Ended break " << (break_count + 1) << ": ";
                cin >> breaks_hr_end >> breaks_min_end;
                
                cout << endl << endl;
            } while(breaks_hr_end < 0 || breaks_hr_end > 12 || breaks_min_end < 0 || breaks_min_end > 59);
            
            breaks_hr_end = get_time_period(breaks_hr_end);
            
            // Push break times into an array for pulling later
            store_break_times(breaks_hr_start, breaks_min_start, breaks_hr_end, breaks_min_end, break_count);
            
            // Convert breaks and add time for start
            breaks_temp_start = ((breaks_hr_start * 60) + breaks_min_start);
            
            // Convert breaks and add time for start
            breaks_temp_end = ((breaks_hr_end * 60) + breaks_min_end);
            
            // Place data in array
            breaks_start[break_count] = breaks_temp_start;
            breaks_end[break_count] = breaks_temp_end;
            
            // Increase counter
            break_count = (break_count + 1);
            
            // Ask for adding new break
            if(break_count < 5)
            {
                cout << "Would you like to add a new break (y/n)? ";
                cin >> again;
                cout << endl << endl;
            }
            else
            {
                system("CLS");
                cout << "You have reached the maximum limit for break entry!\n" <<
                "You will be routed to the calculations." << endl;
                again = 'n';
                system("pause");
            }
            
            if(isalpha(again))
            {
                again = tolower(again);
            }
            else
            {
                again = 'n';
            }
        }
    }while((again == 'y') && (break_count <= 5));
    // End loop for breaks.
    
    // Convert all times over to minutes.
    total_time = (((end_hr * 60) + end_min) - ((start_hr * 60) + start_min));
    sub_time = total_time;
    
    // Convert breaks into minutes. Add hr[i] with time[i] together. Place result in mins. in new array.
    for(int index = 0; index < 5; index++)
    {
        breaks_range[index] = (breaks_end[index] - breaks_start[index]);
    }
    
    // Subtract all values of new array (breaks) from total time.
    for(int iterate = 0; iterate < 5; iterate++)
    {
        sub_time -= breaks_range[iterate];
    }
    
// Convert back to hours and minutes of total working time.
    // For total time
    while(sub_time > 0)
    {
        if(sub_time >= 60)
        {
            tot_sub_hr += 1;
            sub_time -= 60;
        }
        else
        {
            tot_sub_min = sub_time;
            sub_time -= sub_time;
        }
    }
    
    // For total work time
    while(total_time > 0)
    {
        if(total_time >= 60)
        {
            tot_num_hr += 1;
            total_time -= 60;
        }
        else
        {
            tot_num_min = total_time;
            total_time -= total_time;
        }
    }
    
    // Convert times back over to 12-hr format
    if(start_hr > 12)
    {
        start_hr -= 12;
        start_am_pm = "p.m.";
    }
    else if(start_hr == 12)
    {
        start_am_pm = "p.m.";
    }
    else
    {
        start_am_pm = "a.m.";
    }
    
    if(end_hr > 12)
    {
        end_hr -= 12;
        end_am_pm = "p.m.";
    }
    else if(end_hr == 12)
    {
        end_am_pm = "p.m.";
    }
    else
    {
        end_am_pm = "a.m.";
    }
    
    // Get correct hours for array of breaks
    bs1 = get_time_end_adjust(false, 0);
    bs2 = get_time_end_adjust(false, 1);
    bs3 = get_time_end_adjust(false, 2);
    bs4 = get_time_end_adjust(false, 3);
    bs5 = get_time_end_adjust(false, 4);
    be1 = get_time_end_adjust(true, 0);
    be2 = get_time_end_adjust(true, 1);
    be3 = get_time_end_adjust(true, 2);
    be4 = get_time_end_adjust(true, 3);
    be5 = get_time_end_adjust(true, 4);
    
    // Push values into an array for usage later
    array_types_times_s[0] = bs1;
    array_types_times_s[1] = bs2;
    array_types_times_s[2] = bs3;
    array_types_times_s[3] = bs4;
    array_types_times_s[4] = bs5;
    array_types_times_e[0] = be1;
    array_types_times_e[1] = be2;
    array_types_times_e[2] = be3;
    array_types_times_e[3] = be4;
    array_types_times_e[4] = be5;
    
    // Output data. Give range (full working day) and then each break (above 0). Below that, give total time worked in hours and minutes. 
    system("CLS");
    cout << name << ", you have worked a total range of: " << tot_num_hr << " hrs. and " << tot_num_min << " mins." << endl << endl;
    
    // Created for the possibility of multiple double 0's for output
    if(start_min == 0 && end_min == 0)
    {
        cout << "Start Time - " << start_hr << ":00" << "\t" << start_am_pm << endl;
        cout << "End Time - " << end_hr << ":00" << "\t\t" << end_am_pm << endl << endl;
    }
    else if(start_min == 0)
    {
        cout << "Start Time - " << start_hr << ":00" << "\t" << start_am_pm << endl;
        cout << "End Time - " << end_hr << ":" << end_min << "\t\t" << end_am_pm << endl << endl;
    }
    else if(end_min == 0)
    {
        cout << "Start Time - " << start_hr << ":" << start_min << "\t" << start_am_pm << endl;
        cout << "End Time - " << end_hr << ":00" << "\t\t" << end_am_pm << endl << endl;
    }
    else
    {
        cout << "Start Time - " << start_hr << ":" << start_min << "\t" << start_am_pm << endl;
        cout << "End Time - " << end_hr << ":" << end_min << "\t\t" << end_am_pm << endl << endl;
    }
    
    // To determine if there are any non-zero values in the array
    for(int count = 0; count < 5; count++)
    {
        if((breaks_range[count] > 0) && (flag == false))
        {
            cout << "Your breaks are as follows: \n\n";
            flag = true;
        }
        
        // Traverse through the breaks
        if(flag == true)
        {
            if(breaks_range[count] > 0)
            {   // 00:00 - 00:00
                if((arr_times_hr_s[count] == 0) && (arr_times_min_s[count] == 0) && (arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:00 " << array_types_times_s[count] << " - " << "00:00 " << array_types_times_e[count] << endl;
                } // 00:00 - 00:x
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_s[count] == 0) && (arr_times_hr_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:00 " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
                } // 00:00 - x:00
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_s[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
                } // 00:00 - x:x
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_s[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
                } // 00:x - 00:00
                else if((arr_times_hr_s[count] == 0) && (arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:00 " << array_types_times_e[count] << endl;
                } // 00:x - 00:x
                else if((arr_times_hr_s[count] == 0) && (arr_times_hr_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
                } // 00:x - x:00
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
                } // 00:x - x:x
                else if(arr_times_hr_s[count] == 0)
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] <<  " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
                } // x:00 - 00:00
                else if((arr_times_min_s[count] == 0) && (arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - 00:00 " << array_types_times_e[count] << endl;
                } // x:00 - 00:x
                else if((arr_times_min_s[count] == 0) && (arr_times_hr_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
                } // x:00 - x:00
                else if((arr_times_min_s[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
                } // x:00 - x:x
                else if(arr_times_min_s[count] == 0)
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
                } // x:x - 00:00
                else if((arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:00 " << array_types_times_e[count] << endl;
                } // x:x - 00:x
                else if(arr_times_hr_e[count] == 0)
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl; 
                } // x:x - x:00
                else if(arr_times_min_e[count] == 0)
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl; 
                }
                else // x:x - x:x
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;   
                }
            }
        }
    }
    
    if(flag == true)
    {
        cout << "\n\n\nYou have worked a total time (including breaks): " << tot_sub_hr << " hrs. and " << tot_sub_min << " mins." << endl;
    }

    system("pause");
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n\nThank you for using NCompEng Technologies!\n\n\n\n\n\n\n\n\n\n\n";
    
    system("pause");
    return 0;
}

void store_break_times(int break_hr_s, int break_min_s, int break_hr_e, int break_min_e, int pos)
{
    out_break_hr_s = break_hr_s;
    out_break_min_s = break_min_s;
    out_break_hr_e = break_hr_e;
    out_break_min_e = break_min_e;
    
    arr_times_hr_s[pos] = out_break_hr_s;
    arr_times_min_s[pos] = out_break_min_s;
    arr_times_hr_e[pos] = out_break_hr_e;
    arr_times_min_e[pos] = out_break_min_e;
}

int get_time_period(int var)
{
    char choice;
    
    do
    {
        cout << "Please select a time period." << endl << endl << endl << endl;
        cout << "a) a.m." << endl;
        cout << "p) p.m." << endl << endl;
        cout << "Choice: ";
        cin >> choice;
        
        choice = tolower(choice);
    } while((choice != 'a') && (choice != 'p'));

    
    if(choice == 'p')
    {
        if(var != 12)
        {
            return (var += 12);
        }
        else if(var == 12)
        {
            return var;
        }
    }
    else if(choice == 'a')
    {
        return var;
    }
    else
    {
        cout << "There is an error!!!" << endl << endl;
    }
}

string get_time_end_adjust(bool type, int position)
{
    string ret; // Use as temp values for return
    
    switch(type)
    {
        case false:
        {
            if(arr_times_hr_s[position] > 12)
            {
                arr_times_hr_s[position] -= 12;
                ret = "p.m.";
            }
            else if(arr_times_hr_s[position] == 12)
            {
                ret = "p.m.";
            }
            else
            {
                ret = "a.m.";
            }
            
            break;
        }
        case true:
        {
            if(arr_times_hr_e[position] > 12)
            {
                arr_times_hr_e[position] -= 12;
                ret = "p.m.";
            }
            else if(arr_times_hr_e[position] == 12)
            {
                ret = "p.m.";
            }
            else
            {
                ret = "a.m.";
            }
            
            break;
        }
    }
    
    return ret;
}