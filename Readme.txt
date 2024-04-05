Clinic Database Management System Documentation

This document provides an overview of the clinic database management system C code,  including its functionality, usage, and structure. The code is designed to manage patient data in a small clinic, allowing for adding new patients, editing existing records, booking appointments, and viewing patient information.

The code offers the following functionalities:

User Management:
Distinguishes between admin and user roles.
Admins require a password for access.
Patient Management:
Allows admins to add new patients with details like ID, name, gender, and age.
Enables admins to edit existing patient information.
Provides functionalities for admins to view patient records.
Appointment Management:
Enables admins to reserve time slots for patients with doctors.
Offers a selection of available time slots for reservation.
Allows admins to cancel existing reservations.
User View:
Users can view existing patient records based on ID.
Users can see booked and available time slots for appointments (read-only).

Compile the C code using a C compiler (e.g., gcc).
Run the executable file.
The program will prompt you to choose a user type (admin or user).
Based on the chosen user type, you will have access to specific functionalities as described in Section 2.

The code is organized into the following sections:

Header Inclusion: Includes necessary header files for input/output operations (stdio.h).
Global Variables:
struct patient_data: Defines a structure to store patient information (ID, name, gender, age, reservation).
patient: An array of patient_data structures to hold patient data (maximum of 100 patients).
bool_reserve: An array of boolean values representing the availability of time slots (0: available, 1: booked).
num: Tracks the number of patients added to the system.
ID: Stores the ID of a patient being viewed or edited.
Sub-Program Declarations: Declares function prototypes for various functionalities.
Main Function:
The main program loop continuously prompts for user type selection.
Based on the user type, it calls appropriate functions for admin or user functionalities.
Sub-Programs:
input_password: Handles admin password input and validation.
new_patient: Allows adding a new patient with details.
print_data: Prints the information of a specific patient based on ID.
edit_data: Enables editing existing patient information.
reserve: Handles reservation of time slots for appointments.
user_view: Provides user-specific functionalities.
user_ReserveView: Displays booked and available time slots (read-only).
cancel_res: Allows admins to cancel existing reservations.

The code assumes a maximum of 100 patients can be stored in the system.
The time slots for appointments are fixed (2.00, 2.30, 3.00, 4.00, 4.30).
The code doesn't implement error handling for invalid user inputs.
