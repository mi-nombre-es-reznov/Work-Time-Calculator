# Work Time Calculator
<p>
    Description: <br>
    
    This will be a program that will compute times to display how many 
    hours/minutes you worked, with time on/off. The program will ask the user 
    if for their start and end times, seperating a space between hours and 
    minutes. The prgram will display an option for the user to enter breaks in 
    and have those calculated in the time off from working. Depending on the 
    data that the system holds, only certain information will be displayed, to 
    avoid redundancy.
    
    This program shows the start and end time after the original calculation. 
    The program also displays your break times, with the times you went on 
    break, next to them.
    
    This program will now have the capability to enter times and define them as
    am/pm times. The system will auto correct the numbers to give accurate
    numbers.
    
    Update (26 March 19): The program now will display a.m./p.m. next the
    starting/ending time as well as for every breaks starting/ending time. All
    of the times have been converted from their 24-hr equivalent back to their
    12-hr equivalent with their a.m./p.m. value for displaying.
    
    Update (27 March 19): The program now will allow for the user to pick a time
    increment they want to get a specific time version. Current versions that
    are selectable: 10-min, 15-min, and 20-min.

	Update (6 April 19): This update now correctly prepends a '0' to any value 
	that is less than 10. The picture that didn't showcase this in Example 1 has
	now been updated, too.
    
    Below, you will find five sections.
    
    Section 1: Overview and General idea of the program with possible scenerios
    
    Section 2-5: Examples 1 - 4. Each example tests real times from an 
    undisclosed place of employment from a non-mentioned person. The person is
    okay to have their times published below.
    
    Each example tests a different Time Increments on adjusted times.
    
    The results are as follows:
</p>

<h2>General Overview of Program and Screens</h2>

<!-- Demo Overview - Name Request -->
<p>
    When starting the program, a prompt will ask for a name. It 
    doesn't matter if the name that is entered is the users first or full name. 
    The point of this is to make the program feel a little more personal to the
    user at the end during the displayed output.
</p>

<!-- All images will not show up for the preview in Cloud 9, it is trusted they are in order by letter and the src link is correct -->
<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/wtc_a_ask_for_name_screen.png" title="Name Request" alt="Picture of screen that requests name">

<!-- Demo Overview - Time Entry Description -->
<p>
Once a name has been input into the program, the next screen will show how to
input a time in the format the program requires. It is okay to enter the hour, 
then enter a minute and press 'enter' again. However, it is more aesthetically 
pleasing to enter both hour and minute on the same line (seperated by a space).
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_b_Description_of_how_to_enter_time.PNG" title="Time Entry Description" alt="Image of how to input time into system">

<!-- Demo Overview - am/pm choice -->
<p>
This image showcases the 12-hr format as the option you have to choose from. 
This means that you may no longer put your time in a 24-hr format (ex. 5:00 p.m.
--> 1700), but rather in the 12-hr format (1700 --> 5 00, choice p.m.) and the
program will do all the necessary conversions.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_c_am_pm_choice.PNG" title="a.m./p.m. choice selection" alt="Image of a.m./p.m. choice selection">

<!-- Demo Overview - End Time -->
<p>
At this point, the user will now be asked to insert an end time to their day.
This will have the same format as the start time. After input, the
program will now have appropriate values to find a range, assuming your end 
time is later than your start time.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_d_End_time_input.PNG" title="End time" alt="Image of End time screen">

<!-- Demo Overview - Break Insertion -->
<p>
The user will be asked whether or not if they want to include (non-paid) breaks 
in their calculation of their workday. It will sum all breaks, then subtract the
total time from your calculated day's range.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_e_ask_about_breaks_screen.PNG" title="Asking user if there are non-paid breaks that need to be calculated" alt="Image of program asking for (non-paid) break entry">

<!-- Demo Overview - Break Entry -->
<p>
The user will be prompted to begin inserting their breaks. The program will 
calculate the summation of time of all, up to 5, entries.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_f_break_screen_with_counter.PNG" title="Break Entry" alt="Image of break entries">

<!-- Demo Overview - Break Entry Max -->
<p>
If the user tries to enter more than 5 breaks at once, the program will display
a capping message and continue automatically to the next screen.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_g_break_screen_max_inputs.PNG" title="Break entry maximum" alt="Image of program message stating max break entries has been reached">

<!-- Demo Overview - Asking of Time Increments -->
<p>
The user will be asked after their break entries if they want to see their 
times also put into a time increment format. Current time formats include:
10, 15, and 20 minute time increments. (ex 4hr 20min in 15-min inc. == 4.25 hrs)
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_h_Ask_Time_Increments_screen.PNG" title="Asking of user if they want time increment adjustments" alt="Image of Time increment adjustment question to user">

<!-- Demo Overview - Time Increments options -->
<p>
If the user opts for time adjustments to their work time after all calculations,
they will be given options to select which adjustment best suits their needs.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_i_Time_Increment_screen_choices.PNG" title="Allowing user to select between options of time adjustments" alt="Image of Time increment options">

<!-- Demo Overview - Displaying results -->
<p>
Once that final step is complete, the user will then be able to see their 
calculated values, along with all times inserted and calculated breaks.

As of now, if there is a time that is less than 10 minutes, the user will not
see x:0x, but rather x:x, where x is an integer.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_j_Output_Screen.PNG" title="Results displayed" alt="Image of results">

<!-- Demo Overview - End program -->
<p>
This will be the final screen that the user will see before the program shuts down.
</p>

<img src = "/work_time_calculator_pictures/demo_of_what_screens_exist/WTC_k_End_screen.PNG" title="Final screen before shutdown" alt="Image of final screen before shutdown">

<!-- Begin Example 1 -->
<h1>Example 1 - No Time Increments</h1>

<!-- Begin letter - a -->
<p>Name Entry: Becca</p>
<img src="/work_time_calculator_pictures/Example_1/E1_a.PNG" title="Name Entry: Becca" alt="Image of Name Entry">

<!-- Begin letter - b -->
<p>Start Time: 8:15 -> 8 15</p>
<img src="/work_time_calculator_pictures/Example_1/E1_b.PNG" title="Start Time: 8:15 -> 8 15" alt="Image of Start Time">

<!-- Begin letter - c -->
<p>a.m./p.m. select 8:15 am -> 8 15 a.m.</p>
<img src="/work_time_calculator_pictures/Example_1/E1_c.PNG" title="a.m./p.m. select 8:15 am -> 8 15 a.m." alt="Image of a.m./p.m. select">

<!-- Begin letter - d -->
<p>End Time: 3:05 -> 3 05 or 3 5</p>
<img src="/work_time_calculator_pictures/Example_1/E1_d.PNG" title="End Time: 3:05 -> 3 05 or 3 5" alt="Image of End Time">

<!-- Begin letter - e -->
<p>End Time: 3:05pm -> 3 05 or 3 5, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_1/E1_e.PNG" title="a.m./p.m. select 3:05 p.m. -> 3 05 p.m." alt="Image of a.m./p.m. select">

<!-- Begin letter - f -->
<p>Break Question: yes 'y'</p>
<img src="/work_time_calculator_pictures/Example_1/E1_f.PNG" title="Break Question: yes 'y'" alt="Image of break question">

<!-- Begin letter - g -->
<p>Insert break 1 start: 12:25 p.m. -> 12 25, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_1/E1_g.PNG" title="Insert break 1 start: 12:25 p.m. -> 12 25, choice p.m." alt="Image of break entry 1 start">

<!-- Begin letter - h -->
<p>Insert break 1 end: 1:14 p.m. -> 1 14, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_1/E1_h.PNG" title="Insert break 1 end: 1:14 p.m. -> 1 14, choice p.m." alt="Image of break entry 1 end">

<!-- Begin letter - i -->
<p>Add new break?: No 'n'</p>
<img src="/work_time_calculator_pictures/Example_1/E1_i.PNG" title="Add new break?: No 'n'" alt="Image of new break entry">

<!-- Begin letter - j -->
<p>Time Increment?: No 'n'</p>
<img src="/work_time_calculator_pictures/Example_1/E1_j.PNG" title="Time Increment?: No 'n'" alt="Image of Time Increment question">

<!-- Begin letter - k -->
<p>Displaying Results</p>
<img src="/work_time_calculator_pictures/Example_1/E1_k.PNG" title="Displaying Results" alt="Image of Displayed Results">

<!-- Begin Example 2 -->
<h1>Example 2 - 20-min Time Increments</h1>

<!-- Begin letter - a -->
<p>Name Entry: Mariam</p>
<img src="/work_time_calculator_pictures/Example_2/E2_a.PNG" title="Name Entry: Mariam" alt="Image of Name Entry">

<!-- Begin letter - b -->
<p>Start Time: 11:25 a.m. -> 11 25, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_2/E2_b.PNG" title="Start Time: 11:25 a.m. -> 11 25, choice a.m." alt="Image of Start Time">

<!-- Begin letter - c -->
<p>End Time: 12:46 p.m. -> 12 46, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_2/E2_c.PNG" title="End Time: 12:46 p.m. -> 12 46, choice p.m." alt="Image of End Time">

<!-- Begin letter - d -->
<p>Break Question: No 'n'</p>
<img src="/work_time_calculator_pictures/Example_2/E2_d.PNG" title="Break Question: No 'n'" alt="Image of break question">

<!-- Begin letter - e -->
<p>Time Increment?: Yes 'y'</p>
<img src="/work_time_calculator_pictures/Example_2/E2_e.PNG" title="Time Increment?: Yes 'y'" alt="Image of Time Increment question">

<!-- Begin letter - f -->
<p>Displaying Results</p>
<img src="/work_time_calculator_pictures/Example_2/E2_f.PNG" title="Displaying Results" alt="Image of Displayed Results">

<!-- Begin Example 3 -->
<h1>Example 3 - 10-min Time Increments</h1>

<!-- Begin letter - a -->
<p>Name Entry: Samantha</p>
<img src="/work_time_calculator_pictures/Example_3/E3_a.PNG" title="Name Entry: Samantha" alt="Image of Name Entry">

<!-- Begin letter - b -->
<p>Start Time: 7:30 a.m. -> 7 30, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_3/E3_b.PNG" title="Start Time: 7:30 a.m. -> 7 30, choice a.m." alt="Image of Start Time">

<!-- Begin letter - c -->
<p>End Time: 3:30 p.m. -> 3 30, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_3/E3_c.PNG" title="End Time: 3:30 p.m. -> 3 30, choice p.m." alt="Image of End Time">

<!-- Begin letter - d -->
<p>Break Question: Yes 'y' -> break 1 start: 11:30 a.m. -> 11 30, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_3/E3_d.PNG" title="Break Question: Yes 'y' -> break 1 start: 11:30 a.m. -> 11 30, choice a.m." alt="Image of break entry 1 start">

<!-- Begin letter - e -->
<p>Insert break 1 end: 12:30 p.m. -> 12 30, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_3/E3_e.PNG" title="Insert break 1 end: 12:30 p.m. -> 12 30, choice p.m." alt="Image of break entry 1 end">

<!-- Begin letter - f -->
<p>Add new break?: No 'n'</p>
<img src="/work_time_calculator_pictures/Example_3/E3_f.PNG" title="Add new break?: No 'n'" alt="Image of new break entry">

<!-- Begin letter - g -->
<p>Time Increment?: Yes 'y'</p>
<img src="/work_time_calculator_pictures/Example_3/E3_g.PNG" title="Time Increment?: Yes 'y'" alt="Image of Time Increment question">

<!-- Begin letter - h -->
<p>Displaying Results</p>
<img src="/work_time_calculator_pictures/Example_3/E3_h.PNG" title="Displaying Results" alt="Image of Displayed Results">

<!-- Begin Example 4 -->
<h1>Example 4 - 15-min Time Increments</h1>

<!-- Begin letter - a -->
<p>Name Entry: Lola</p>
<img src="/work_time_calculator_pictures/Example_4/E4_a.PNG" title="Name Entry: Lola" alt="Image of Name Entry">

<!-- Begin letter - b -->
<p>Start Time: 7:40 a.m. -> 7 40, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_4/E4_b.PNG" title="Start Time: 7:40 a.m. -> 7 40, choice a.m." alt="Image of Start Time">

<!-- Begin letter - c -->
<p>End Time: 3:00 p.m. -> 3 00, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_4/E4_c.PNG" title="End Time: 3:00 p.m. -> 3 00, choice p.m." alt="Image of End Time">

<!-- Begin letter - d -->
<p>Break Question: Yes 'y' -> break 1 start: 9:51 p.m. -> 9 51, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_4/E4_d.PNG" title="Break Question: Yes 'y' -> break 1 start: 11:30 p.m. -> 11 30, choice p.m." alt="Image of break entry 1 start">

<!-- Begin letter - e -->
<p>Insert break 1 end: 10:00 a.m. -> 10 00, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_4/E4_e.PNG" title="Insert break 1 end: 10:00 a.m. -> 10 00, choice a.m." alt="Image of break entry 1 end">

<!-- Begin letter - f -->
<p>Add new break?: Yes 'y' -> Break 2 Start: 11:30 a.m. -> 11 30, choice a.m.</p>
<img src="/work_time_calculator_pictures/Example_4/E4_f.PNG" title="Add new break?: Yes 'y' -> Break 2 Start: 11:30 a.m. -> 11 30, choice a.m." alt="Image of new break entry">

<!-- Begin letter - g -->
<p>Insert break 2 end: 12:10 p.m. -> 12 10, choice p.m.</p>
<img src="/work_time_calculator_pictures/Example_4/E4_g.PNG" title="Insert break 2 end: 12:10 p.m. -> 12 10, choice p.m." alt="Image of break entry 2 end">

<!-- Begin letter - h -->
<p>Add new break?: No 'n'</p>
<img src="/work_time_calculator_pictures/Example_4/E4_h.PNG" title="Add new break?: No 'n'" alt="Image of new break entry">

<!-- Begin letter - i -->
<p>Time Increment?: Yes 'y'</p>
<img src="/work_time_calculator_pictures/Example_4/E4_i.PNG" title="Time Increment?: Yes 'y'" alt="Image of Time Increment question">

<!-- Begin letter - j -->
<p>Displaying Results</p>
<img src="/work_time_calculator_pictures/Example_4/E4_j.PNG" title="Displaying Results" alt="Image of Displayed Results">

<!-- Fin -->
<h2>Thank you for viewing my project. Feel free to message me if you have any questions.</h2>
<img src="/work_time_calculator_pictures/Example_4/E4_end.PNG" title="End Screen" alt="Image of Program End Screen">