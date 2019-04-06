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
#include <cmath>
using namespace std;

// Call functions
void store_break_times(int, int, int, int, int);
int get_time_period(int);
string get_time_end_adjust(bool, int);
char time_choice_letter();
double time_adjustment(char, double);
void display_selected_convert_hours(char, int, double);

// Global variables
int out_break_hr_s, out_break_min_s, out_break_hr_e, out_break_min_e, tot_sub_min = 0;
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
double time_adjusted_value;


int main()
{
    string name;
    int start_hr, end_hr, breaks_hr_start, breaks_hr_end, break_count = 0, breaks_temp_start = 0, breaks_temp_end = 0, total_time = 0;
    int start_min, end_min, breaks_min_start, breaks_min_end;
    double sub_time,  tot_num_min = 0;
    int breaks_range[5] = {0, 0, 0, 0, 0};
    int tot_num_hr = 0, tot_sub_hr = 0;
    char again, ask_break;
    bool flag = false, asked_already = false, am_pm_bool = false;
    char time_choice;
    
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
    system("CLS");
    
    // Ask for ending hour, 24 hr format.
    do
    {
        cout << "Please enter your end time: ";
        cin >> end_hr >> end_min;
        cout << endl;
        
    } while(end_hr < 0 || end_hr > 12 || end_min < 0 || end_min > 59);
    
    end_hr = get_time_period(end_hr);
    system("CLS");
    
    // Begin loop for breaks. Ask for number of breaks during work day, not to exceed 5. Place in 2 arrays (hr and min).
    do
    {
        // Ask if there are any breaks that want to be recorded
        if(asked_already == false)
        {
            cout << "Did you take any NON-PAID breaks that you want to record? (y/n) ";
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
            system("CLS");
            
            // Ask for lunch hour end, 24 hr format.
            do
            {
                cout << "Ended break " << (break_count + 1) << ": ";
                cin >> breaks_hr_end >> breaks_min_end;
                
                cout << endl << endl;
            } while(breaks_hr_end < 0 || breaks_hr_end > 12 || breaks_min_end < 0 || breaks_min_end > 59);
            
            breaks_hr_end = get_time_period(breaks_hr_end);
            system("CLS");
            
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

    // Call function to get what option the user wants to convert time to.
    time_choice = time_choice_letter();

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
    
    // Start using the value of the subraracted break times.
    time_adjusted_value = time_adjustment(time_choice, tot_sub_min);
    
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
    
    // Push values into an array for usage later a.m./p.m.
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
		if (end_min < 10)
		{
			cout << "Start Time - " << start_hr << ":00" << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":0" << end_min << "\t\t" << end_am_pm << endl << endl;
		}
		else
		{
			cout << "Start Time - " << start_hr << ":00" << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":" << end_min << "\t\t" << end_am_pm << endl << endl;
		}
    }
    else if(end_min == 0)
    {
		if (start_min < 10)
		{
			cout << "Start Time - " << start_hr << ":0" << start_min << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":00" << "\t\t" << end_am_pm << endl << endl;
		}
		else
		{
			cout << "Start Time - " << start_hr << ":" << start_min << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":00" << "\t\t" << end_am_pm << endl << endl;
		}
    }
    else
    {
		if ((start_min < 10) && (end_min < 10))
		{
			cout << "Start Time - " << start_hr << ":0" << start_min << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":0" << end_min << "\t\t" << end_am_pm << endl << endl;
		}
		else if (start_min < 10)
		{
			cout << "Start Time - " << start_hr << ":0" << start_min << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":" << end_min << "\t\t" << end_am_pm << endl << endl;
		}
		else if (end_min < 10)
		{
			cout << "Start Time - " << start_hr << ":" << start_min << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":0" << end_min << "\t\t" << end_am_pm << endl << endl;
		}
		else
		{
			cout << "Start Time - " << start_hr << ":" << start_min << "\t" << start_am_pm << endl;
			cout << "End Time - " << end_hr << ":" << end_min << "\t\t" << end_am_pm << endl << endl;
		}
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
					if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:00 " << array_types_times_s[count] << " - " << "00:0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:00 " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // 00:00 - x:00
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_s[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << "00:00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
                } // 00:00 - x:x
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_s[count] == 0))
                {
					if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
							<< "00:00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // 00:x - 00:00
                else if((arr_times_hr_s[count] == 0) && (arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
					if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:00 " << array_types_times_e[count] << endl;
					}
                } // 00:x - 00:x
                else if((arr_times_hr_s[count] == 0) && (arr_times_hr_e[count] == 0))
                {
					if ((arr_times_min_s[count] < 10) && (arr_times_min_e[count] < 10))
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // 00:x - x:00
                else if((arr_times_hr_s[count] == 0) && (arr_times_min_e[count] == 0))
                {
					if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
					}
                } // 00:x - x:x
                else if(arr_times_hr_s[count] == 0)
                {
					if ((arr_times_min_e[count] < 10) && (arr_times_min_s[count] < 10))
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< "00:" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // x:00 - 00:00
                else if((arr_times_min_s[count] == 0) && (arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - 00:00 " << array_types_times_e[count] << endl;
                } // x:00 - 00:x
                else if((arr_times_min_s[count] == 0) && (arr_times_hr_e[count] == 0))
                {
					if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << "00:0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << "00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // x:00 - x:00
                else if((arr_times_min_s[count] == 0) && (arr_times_min_e[count] == 0))
                {
                    cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t" 
                    << arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
                } // x:00 - x:x
                else if(arr_times_min_s[count] == 0)
                {
					if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":00 " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // x:x - 00:00
                else if((arr_times_hr_e[count] == 0) && (arr_times_min_e[count] == 0))
                {
					if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:00 " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:00 " << array_types_times_e[count] << endl;
					}
                } // x:x - 00:x
                else if(arr_times_hr_e[count] == 0)
                {
					if((arr_times_min_s[count] < 10) && (arr_times_min_e[count] < 10))
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - 00:" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                } // x:x - x:00
                else if(arr_times_min_e[count] == 0)
                {
					if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":00 " << array_types_times_e[count] << endl;
					}
                }
                else // x:x - x:x
                {
					if ((arr_times_min_s[count] < 10) && (arr_times_min_e[count] < 10))
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_s[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":0" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else if (arr_times_min_e[count] < 10)
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":0" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
					else
					{
						cout << "Break " << (count + 1) << ": " << breaks_range[count] << " minutes" << "\t\t"
						<< arr_times_hr_s[count] << ":" << arr_times_min_s[count] << " " << array_types_times_s[count] << " - " << arr_times_hr_e[count] << ":" << arr_times_min_e[count] << " " << array_types_times_e[count] << endl;
					}
                }
            }
        }
    }
    
    if(flag == true)
    {
        cout << "\n\n\nYou have worked a total time (including breaks): " << tot_sub_hr << " hrs. and " << tot_sub_min << " mins." << endl;
    }

    display_selected_convert_hours(time_choice, tot_sub_hr, time_adjusted_value);

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

char time_choice_letter()
{
    char choice, ret_val, pick_choice;
    
    system("CLS");
    
    do
    {
        cout << "Would you like to display your time using specific time increments? - [y/n] ";
        cin >> choice;
        choice = tolower(choice);
    } while(choice != 'y' && choice != 'n');
    
    switch(choice)
    {
        case 'y':
        {
            do
            {
                cout << "Please select a time increment to use as measurement. (i.e. 3.25 hrs, using 15-min increments)" << endl << endl;
                cout << "a) 10-min increments" << endl;
                cout << "b) 15-min increments" << endl;
                cout << "c) 20-min increments" << endl << endl;
                
                cout << "Choice: ";
                cin >> pick_choice;
            } while((pick_choice != 'a') && (pick_choice != 'b') && (pick_choice != 'c'));
            
            ret_val = pick_choice;
            break;
        }
        case 'n':
        {
            cout << "No time increments have been used." << endl;
            ret_val = 'd';
            break;
        }
        default:
        {
            cout << "An error has occurred." << endl;
            break;
        }
    }
    
    return ret_val;
}

double time_adjustment(char letter, double calc)
{
    double return_val, temp;
    
    switch(letter)
    {
        case 'a':
        {
            // Test to see if the current minutes is a mod of 10 for even calculations.
            calc = fmod(calc, 60.0);
            
            // Check for (< 10) and (< 5)
            if((calc < 10) && (calc < 5))
            {
                calc = 0;
                temp = 0;
            }
            // Check for (< 10) AND (>= 5)
            else if((calc < 10) && (calc >= 5))
            {
                calc = 10;
                temp = (calc / 60);
            }
            // Check for (< 20) AND (< 15)
            else if((calc < 20) && (calc < 15))
            {
                calc = 10;
                temp = (calc / 60);
            }
            // Check for (< 20) AND (>= 15)
            else if((calc < 20) && (calc >= 15))
            {
                calc = 20;
                temp = (calc / 60);
            }
            // Check for (< 30) AND (< 25)
            else if((calc < 30) && (calc < 25))
            {
                calc = 20;
                temp = (calc / 60);
            }
            // Check for (< 30) AND (>= 25)
            else if((calc < 30) && (calc >= 25))
            {
                calc = 30;
                temp = (calc / 60);
            }
            // Check for (< 40) AND (< 35)
            else if((calc < 40) && (calc < 35))
            {
                calc = 30;
                temp = (calc / 60);
            }
            // Check for (< 40) AND (>= 35)
            else if((calc < 40) && (calc >= 35))
            {
                calc = 40;
                temp = (calc / 60);
            }
            // Check for (< 50) AND (< 45)
            else if((calc < 50) && (calc < 45))
            {
                calc = 40;
                temp = (calc / 60);
            }
            // Check for (< 50) AND (>= 45)
            else if((calc < 50) && (calc >= 45))
            {
                calc = 50;
                temp = (calc / 60);
            }
            // Check for (< 60) AND (< 55)
            else if((calc < 60) && (calc < 55))
            {
                calc = 50;
                temp = (calc / 60);
            }
            // Check for (< 60) AND (>= 55)
            else if((calc < 60) && (calc >= 55))
            {
                calc = 60;
                temp = (calc / 60);
            }
            
            return_val = temp;
            
            break;
        }
        case 'b':
        {
            // Test to see if the current minutes is a mod of 10 for even calculations.
            calc = fmod(calc, 60.0);

            // Check for (< 15) and (< 7)
            if((calc < 15) && (calc < 7))
            {
                calc = 0;
                temp = 0;
            }
            // Check for (< 15) AND (>= 7)
            else if((calc < 15) && (calc >= 7))
            {
                calc = 15;
                temp = (calc / 60);
            }
            // Check for (< 30) AND (< 15)
            else if((calc < 30) && (calc < 23))
            {
                calc = 15;
                temp = (calc / 60);
            }
            // Check for (< 30) AND (>= 15)
            else if((calc < 30) && (calc >= 23))
            {
                calc = 30;
                temp = (calc / 60);
            }
            // Check for (< 45) AND (< 22)
            else if((calc < 45) && (calc < 38))
            {
                calc = 30;
                temp = (calc / 60);
            }
            // Check for (< 45) AND (>= 22)
            else if((calc < 45) && (calc >= 38))
            {
                calc = 45;
                temp = (calc / 60);
            }
            // Check for (< 40) AND (< 35)
            else if((calc < 60) && (calc < 53))
            {
                calc = 45;
                temp = (calc / 60);
            }
            // Check for (< 60) AND (>= 30)
            else if((calc < 60) && (calc >= 53))
            {
                calc = 60;
                temp = (calc / 60);
            }
            else
            {
                cout << "Error: " << endl;
            }
            
            return_val = temp;
            
            break;
        }
        case 'c':
        {
            // Test to see if the current minutes is a mod of 10 for even calculations.
            calc = fmod(calc, 60.0);

            // Check for (< 15) and (< 7)
            if((calc < 20) && (calc < 10))
            {
                calc = 0;
                temp = 0;
            }
            // Check for (< 15) AND (>= 7)
            else if((calc < 20) && (calc >= 10))
            {
                calc = 20;
                temp = (calc / 60);
            }
            // Check for (< 30) AND (< 15)
            else if((calc < 40) && (calc < 30))
            {
                calc = 20;
                temp = (calc / 60);
            }
            // Check for (< 30) AND (>= 15)
            else if((calc < 40) && (calc >= 30))
            {
                calc = 40;
                temp = (calc / 60);
            }
            // Check for (< 45) AND (< 22)
            else if((calc < 60) && (calc < 50))
            {
                calc = 40;
                temp = (calc / 60);
            }
            // Check for (< 45) AND (>= 22)
            else if((calc < 60) && (calc >= 50))
            {
                calc = 60;
                temp = (calc / 60);
            }
            
            return_val = temp;
            
            break;
        }
        case 'd':
        {
            return_val = 0;
            break;
        }
        default:
        {
            cout << "Invalid choice." << endl << endl;
            break;
        }
    }
    
    return return_val;
}

void display_selected_convert_hours(char choice, int tot_sub_hr, double time_adjusted_value)
{
    switch(choice)
    {
        case 'a':
        {
            if(time_adjusted_value > 0.0)
            {
                cout << "Your adjusted time at 10-min increments: " << (tot_sub_hr + time_adjusted_value) << endl;
            }
            else
            {
                cout << "Your adjusted time at 10-min increments: " << tot_sub_hr << ".0" << endl;
            }
            
            break;
        }
        case 'b':
        {
            if(time_adjusted_value > 0.0)
            {
                cout << "Your adjusted time at 15-min increments: " << (tot_sub_hr + time_adjusted_value) << endl;
            }
            else
            {
                cout << "Your adjusted time at 15-min increments: " << tot_sub_hr << ".0" << endl;
            }
            
            break;
        }
        case 'c':
        {
            if(time_adjusted_value > 0.0)
            {
                cout << "Your adjusted time at 20-min increments: " << (tot_sub_hr + time_adjusted_value) << endl;
            }
            else
            {
                cout << "Your adjusted time at 20-min increments: " << tot_sub_hr << ".0" << endl;
            }
            
            break;
        }
        case 'd':
        {
            cout << " ";
            
            break;
        }
        default:
        {
            cout << "\n\n\nError!!!!\n\n\n";
            
            break;
        }
    }
}