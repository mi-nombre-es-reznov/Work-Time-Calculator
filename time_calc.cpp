// Nicholas Perez-Aguilar
// Start Date: 21 March 2019
// Description: This will be a program that will compute times to display how many hours/minutes you worked, with time on/off.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int start_hr, end_hr, breaks_hr_start, breaks_hr_end, break_count = 0, breaks_temp_start = 0, breaks_temp_end = 0, total_time = 0, count = 0;
    int start_min, end_min, breaks_min_start, breaks_min_end, sub_time;
    int breaks_start[5] = {0, 0, 0, 0, 0};
    int breaks_end[5] = {0, 0, 0, 0, 0};
    int breaks_range[5] = {0, 0, 0, 0, 0};
    int tot_num_hr = 0, tot_num_min = 0, tot_sub_hr = 0, tot_sub_min = 0;
    char again;
    
    // Get name for now, for a more personal experience throughout the program.
    cout << "Please enter your name: ";
    getline(cin, name);
    
    // Testing for name. Delete later.
    cout << "Your name is: " << name << "!" << endl << endl;
    
    // Ask for start hour, 24 hr format.
    do
    {
        cout << "Please enter the hour in which you started work (use the 24-hr format): ";
        cin >> start_hr;
        
        cout << endl << endl;
    } while(start_hr < 0 || start_hr > 23);
    
    // Ask for start minute.
    do
    {
        cout << "Please enter the minute in which you started work: ";
        cin >> start_min;
        
        cout << endl << endl;
    } while(start_min < 0 || start_min > 59);
    
    // Ask for ending hour, 24 hr format.
    do
    {
        cout << "Please enter the hour in which you ended work (use the 24-hr format): ";
        cin >> end_hr;
        
        cout << endl << endl;
    } while(end_hr < 0 || end_hr > 23);
    
    // Ask for ending minute.
    do
    {
        cout << "Please enter the minute in which you ended work: ";
        cin >> end_min;
        
        cout << endl << endl;
    } while(end_min < 0 || end_min > 59);
    
    // Begin loop for breaks. Ask for number of breaks during work day, not to exceed 5. Place in 2 arrays (hr and min).
    do
    {
        // Ask for lunch hour start, 24 hr format.
        do
        {
            cout << "Please enter the hour in which you had break " << (break_count + 1) << " (use the 24-hr format): ";
            cin >> breaks_hr_start;
            
            cout << endl << endl;
        } while(breaks_hr_start < 0 || breaks_hr_start > 23);
        
        // Ask for lunch hour end minute.
        do
        {
            cout << "Please enter the starting minute for break " << (break_count + 1) << ": ";
            cin >> breaks_min_start;
            
            cout << endl << endl;
        } while(breaks_min_start < 0 || breaks_min_start > 59);
        
        // Ask for lunch hour end, 24 hr format.
        do
        {
            cout << "Please enter the hour in which you had break " << (break_count + 1) << " (use the 24-hr format): ";
            cin >> breaks_hr_end;
            
            cout << endl << endl;
        } while(breaks_hr_end < 0 || breaks_hr_end > 23);
        
        // Ask for lunch minute end, 24 hr format.
        do
        {
            cout << "Please enter the ending minute for break " << (break_count + 1) << ": ";
            cin >> breaks_min_start;
            
            cout << endl << endl;
        } while(breaks_min_start < 0 || breaks_min_start > 59);
        
        // Increase counter
        count = (count + 1);
        
        // Convert breaks and add time for start
        breaks_temp_start = ((breaks_hr_start * 60) + breaks_min_start);
        
        // Convert breaks and add time for start
        breaks_temp_end = ((breaks_hr_end * 60) + breaks_min_end);
        
        // Place data in array
        breaks_start[break_count] = breaks_temp_start;
        breaks_end[break_count] = breaks_temp_end;
        
        // Ask for adding new break
        cout << "Would you like to add a new break (y/n)? ";
        cin >> again;
        
        if(isalpha(again))
        {
            again = tolower(again);
        }
        else
        {
            again = 'n';
        }
        
    }while(again == 'y');
    // End loop for breaks.
    
    // Convert all times over to minutes.
    total_time = (((end_hr * 60) + end_min) - (start_hr * 60) + start_min);
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
        if(sub_time > 60)
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
        if(total_time > 60)
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
    
    // Output data. Give range (full working day) and then each break (above 0). Below that, give total time worked in hours and minutes. 
    system("CLS");
    cout << "You have worked a total range of: " << tot_num_hr << " hrs. and " << tot_num_min << " mins." << endl << endl;
    cout << "Your breaks are as follows: \n";
    for(int disp = 0; disp < 5; disp++)
    {
        if(breaks_range[disp] > 0)
        {
            cout << "Break " << (disp + 1) << ": " << breaks_range[disp] << " minutes" << endl;
        }
    }
    cout << "You have worked a total time (including breaks): " << tot_sub_hr << " hrs. and " << tot_sub_min << " mins." << endl;
    system("pause");
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n\nThank you for using NCompEng Technologies!\n\n\n\n\n\n\n\n\n\n\n";
    
    system("pause");
    return 0;
}