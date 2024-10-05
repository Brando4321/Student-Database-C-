# Student-Database-C-

Here’s a description of the Student Registration System based on the code you provided:

Student Registration System

This is a C++ program that implements a Student Registration System. The system provides functionalities for students to register for classes, search for classes in their schedule, and communicate with teachers. Additionally, the program includes features for validating student information, credit card payments, and managing class schedules.

Key Features:

	1.	Student Registration:
	•	Allows students to register by providing their name, email, and student ID.
	•	The program checks if the student’s account already exists using an external file for account storage.
	•	New students can create an account, and their information is saved for future access.
	2.	Class Registration:
	•	After registering, students can view and select classes from a predefined list stored in a file.
	•	The system ensures that the chosen classes are valid, assigns credits, and calculates tuition based on the selected courses.
	•	Students are categorized as full-time or part-time based on their total credit load.
	3.	Payment System:
	•	The program includes a credit card validator that checks if a student’s card number is valid using the Luhn algorithm.
	•	Upon successful validation, the payment is processed, and registration is confirmed.
	4.	Class Schedule Search:
	•	Students can search for classes in their schedule.
	•	The program allows students to search for specific classes or view the entire class schedule, along with randomly generated class times.
	5.	Teacher Communication:
	•	Students can view a list of teachers for their registered classes.
	•	They can select a teacher to contact, and the teacher’s email is displayed.
	6.	File Management:
	•	The program utilizes external files (accounts.txt, classes_only.txt, student_classes.txt, and teachers_with_courses.txt) to store and retrieve data for student accounts, classes, and teacher information.

How It Works:

	1.	When the program starts, students are presented with a menu where they can:
	•	Register for an account and classes.
	•	Search for their classes.
	•	Talk to a teacher.
	2.	During registration, the student enters their details, and the program validates the input, such as checking the format of the email and ensuring the student ID is valid.
	3.	Once the student is registered, they can select their classes from a predefined list, and the system calculates the total tuition based on the number of credits.
	4.	The program also allows students to pay their tuition using a credit card, ensuring the card is valid before processing the payment.
	5.	Students can search for classes in their schedule or talk to teachers based on the courses they have registered for.

This program offers a comprehensive solution for managing student registrations and class schedules, using C++ features such as classes, file handling, and input validation to create an interactive user experience.
