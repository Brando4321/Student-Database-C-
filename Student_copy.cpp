//Pre Processor_Directive
/*
// This program implements a Student Registration System. It allows students to register for classes, 
search for classes in their schedule, 
and communicate with teachers.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <random>


using namespace std;

//Student Class here



class Student {
private:
    string NAME;
    string EMAIL;
    string STUDENT_ID;

public:
    // Constructors
    Student() {} // Default constructor

    Student(const string& name, const string& email, const string& student_id) : NAME(name), EMAIL(email), STUDENT_ID(student_id) {}

    // Getters
    string getName() const {
        return NAME;
    }

    string getEmail() const {
        return EMAIL;
    }

    string getStudentID() const {
        return STUDENT_ID;
    }

    // Setters
    void setName(const string& name) {
        NAME = name;
    }

    void setEmail(const string& email) {
        EMAIL = email;
    }

    void setStudentID(const string& student_id) {
        STUDENT_ID = student_id;
    }

    // Other methods

    bool LoopName() {
    for (int i = 0; i < NAME.length(); i++) {
        if (!isalpha(NAME[i]) && NAME[i] != ' ') {
            return true;
        }
    }
    return false;
    }


    void Get_Student_Input() {
        cin.ignore();

        // Input validation for name
        do {
            cout << "Enter your name: ";
            getline(cin, NAME);
            if(LoopName()){
                cout << "Invalid name. Please enter a valid name with only alphabets." << endl;
            }
            
            else if (NAME.empty()) {
                cout << "Name cannot be empty. Please enter your name again." << endl;
            }
            
         
            
        } while (NAME.empty() || LoopName());

        // Input validation for email
        do {
            cout << "Enter your email: ";
            getline(cin, EMAIL);
            if (EMAIL.find('@') == string::npos || EMAIL.find('.') == string::npos) {
                cout << "Invalid email format. Please enter a valid email address." << endl;
            }
        } while (EMAIL.find('@') == string::npos || EMAIL.find('.') == string::npos);

        // Input validation for student ID
        do {
            cout << "Enter your student ID: ";
            getline(cin, STUDENT_ID);
            if (STUDENT_ID.length() != 7 || !all_of(STUDENT_ID.begin(), STUDENT_ID.end(), ::isdigit)) {
                cout << "Student ID must be 7 digits long and contain only digits. Please enter a valid student ID." << endl;
            }
        } while (STUDENT_ID.length() != 7 || !all_of(STUDENT_ID.begin(), STUDENT_ID.end(), ::isdigit));
    }


    void display() const {
        cout << "Name: " << NAME << endl;
        cout << "Email: " << EMAIL << endl;
        cout << "Student ID: " << STUDENT_ID << endl;
    }
};

class DatabaseManager {
public:
    static bool checkAccountExists(const string& student_id, const string& email) {
        //Read from a file and if the user is at that file we return true, else false
        fstream file;
        file.open("accounts.txt", ios::in);

        //Reading from file
        if(file.is_open()){
            string line;//Storing line of text
            while(getline(file, line)){
                if(line.find(student_id) != string::npos && line.find(email) != string::npos){
                    file.close();
                    return true;
                }
                
            }
        }

        return false;
    }
};

class Classes{
    public:
    
    void display(){
        fstream file;
        file.open("classes_only.txt");
        if(file.is_open()){
            string line;
            while(getline(file, line)){
                cout<<line<<endl;
           
            }
        }
        else{
            cout<<"Error opening file"<<endl;
        }
    }   



};

class Credit_card_validator{

    public:
    Student s;
    int validate(){
    string cardNumber;
    int result=0; 
    char choice;

    do{
    cout<<"Please Enter Your Credit Card Number: ";
    cin>>cardNumber;

    cout<<"For confirmation purposes is this your number: "<<cardNumber<<" (Select y/n): "<<endl;
    cin>>choice;
    choice= tolower(choice);

    switch(choice){
        case 'y':
            result =sum_Even_Digits(cardNumber)+sum_Odd_Digits(cardNumber);

            if(result%10==0){
                cout<<"Your credit card number is valid"<<endl;
                cout<<"You have completed your registration & payment received!"<<endl;
                cout<<endl;
            
            }
            else{
                cout<<"Your number is not valid"<<endl;
                validate();
            }
            break;

        case 'n':
            cout<<"Re-Enter"<<endl;
    }
    }while(choice!='y');


return 0;
}

int get_Digit(const int number){


return number %10 +(number/10%10);
}
int sum_Odd_Digits(const string cardNumber){
    int sum=0;

   for(int i =cardNumber.size()-1; i>=0; i-=2 ){
    sum+=get_Digit((cardNumber[i]-'0'));
   }

return sum;
}


int sum_Even_Digits(const string cardNumber){
   int sum=0;

   for(int i= cardNumber.size()-2; i>=0; i-=2 ){
    sum+=get_Digit((cardNumber[i]-'0')*2);
   }

return sum;
}


};

//Registration validation
//378282246310005
class Registration {
public:
    static void registerStudent() {
        int account_choice;

        cout << "Do you have an account? (1. Yes 2. No): ";
        cin >> account_choice;

        //switch statement
        switch(account_choice){
            //Case 1 is to check if user has account and if located, registration was successful 
            //And we can send them to register for classes
            case 1: {
                Student student;
                student.Get_Student_Input();
                if (DatabaseManager::checkAccountExists(student.getStudentID(), student.getEmail())) {
                    cout<<"Found User in Database"<<endl;
                    Registration_valid_classes();
                } 
                else {
                    fstream file;
                    file.open("Accounts.txt", ios::app);
                    if(file.is_open()){
                        file<<"Name"<<", "<<"Student ID"<<", "<<"Email"<<endl;
                        file<<student.getName()<<", "<<student.getStudentID()<<", "<<student.getEmail()<<endl;
                        cout << "Login Accessed" << endl;
                        file.close();

                        //After login Accessed we will send them to class selection & implementation
                        Registration_valid_classes();
                        //SEND TO CLASSES DISPLAY AND LET THEM CHOOSE CLASSES
                    }
                else{
                        cout<<"Error opening file"<<endl;
                    }
                   
                }
                break;
            }
            case 2:{
                Student student;
                cout << "Registering new account..." << endl;

                student.Get_Student_Input();
                if (DatabaseManager::checkAccountExists(student.getStudentID(), student.getEmail())) {
                    cout << "User with this account already exists" << endl;
                } else {
                    //append to file
                    fstream file;
                    file.open("accounts.txt", ios::app);
                    if(file.is_open()){
                        file<<student.getName()<<", "<<student.getStudentID()<<", "<<student.getEmail()<<endl;
                        cout << "Account successfully registered" << endl;
                        file.close();
                    }
                    else{
                        cout<<"Error opening file"<<endl;
                    }
                }
                break;
            }
            default:{
                cout << "Invalid choice" << endl;
                break;
            }

        }
    }



   static void Registration_valid_classes() {
    // Implement registration for classes
    cout << endl;
    cout << endl;
    cout << "Displaying valid classes" << endl;
    
    Classes c;
    c.display();


    cout << endl;
    int semesters=2;
    int class_num=4;
    int credits=0;
    double tuition=0;
    string *sememster_array= new string[semesters];
    string* user_classes_array= new string[class_num];



   for (int i = 0; i < semesters; i++) {
        cout << "Enter semester #" << i + 1 << endl;
        // Grab user input
        for (int j = 0; j < class_num; j++) {
            bool valid_class = false;
            while (!valid_class) {
                cout << "Enter class " << j + 1 << ": ";
                cin >> user_classes_array[j];
                        
                fstream file;
                file.open("classes_only.txt");
                if (file.is_open()) {
                    string line;
                    while (getline(file, line)) {
                        if (line.find(user_classes_array[j]) != string::npos) {
                            valid_class = true; // Set to true if class found
                            cout << "Found class" << endl;
                            credits+=4;
                            tuition+=60;
                            
                            cout<<"Now adding to student_classes.txt";
                            fstream myfile;
                            myfile.open("student_classes.txt", ios::app);
                            myfile<<user_classes_array[j]<<endl;
                            myfile.close();
                            break; // Exit while loop once class is found
                        }

                        
                    }
                    file.close();
                    //Read and append to file passing in their classes selected
                }
                if (!valid_class) {
                    cout << "Class not found. Please enter a valid class." << endl;
                }
            } // closing brace for the while loop
        }
    }

    cout<<endl;
    //Display
    for(int i=0; i<semesters; i++){
        cout<<"Information for Semester #"<<i+1<<endl;
        cout<<endl;

        for(int j=0; j<class_num; j++){

            cout << "Class " << j+1 << ": " << user_classes_array[j] << endl;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<"Total credits for both semesters is "<<credits<<endl;

    int credits_per_semester= credits/2;
    cout<<"You are taking "<<credits_per_semester<<" units per semester!"<<endl;


    if(credits_per_semester>=15 && credits_per_semester<=20){
        cout<<"You are a full time student! "<<endl;
    }

    else if(credits_per_semester<12 && credits_per_semester >=6){
        cout<<"You are a part time student! "<<endl;
    }

    else{
        cout<<"Invalid"<<endl;
    }

    cout<<endl;


    cout<<"Your total tution for the year is $"<< static_cast<int>(tuition)<<fixed<<setprecision(2)<<endl;

    
    char pay_choice;
    
    Credit_card_validator credit;

   
    cout<<"Would you like to pay for your courses (Y/N)?: ";cin>>pay_choice;
    pay_choice= tolower(pay_choice);
    if(pay_choice=='y'){
        Student student_obj;
        credit.validate();
        fstream myfile;
    
        myfile.open("paid.txt", ios::app);
        if(myfile.is_open()){
            myfile<<student_obj.getName()<<" with ID# "<<student_obj.getStudentID()<<" paid ";
            myfile.close();
    }
    else{
        cout<<"Error opening file"<<endl;
    }
    }
    else{
        cout<<"Ok Financial Aid will check your available funds later"<<endl;
        cout<<"Registered but need to confirm with Financial Aid";
    }

    

    //Delete
    delete[] sememster_array;
    sememster_array= nullptr;

    //Delete
    delete[] user_classes_array;
    user_classes_array= nullptr;
    
}//function end


};



//Search Classes
class SearchClasses {
public:
  static void generate_random_hours(int count) {
        // Generate 'count' random hours
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> hour_dist(1, 12);
        uniform_int_distribution<> minute_dist(0, 59);

        for (int i = 0; i < count; ++i) {
            int hour = hour_dist(gen);
            int minute = minute_dist(gen);

            cout << hour << ":" << (minute < 10 ? "0" : "") << minute << endl;
        }
    }

    static void search_per_class(){
        cout<<"Which class would you like to look for?: ";
                string class_name;
                cin>>class_name;
                fstream file;
                file.open("student_classes.txt", ios::in);
                if(file.is_open()){
                    string line;
                    while(getline(file, line)){
                        if(line.find(class_name) != string::npos){
                            cout<<"You have "<<line<<" @ ";
                            generate_random_hours(1);
                            cin.ignore();
                           
                }
                }
                file.close();
                }

                
    }
    static void search() {
        // Implement class searching functionality
        cout<<"Would you like to search your class schedule? (Y/N)?: ";
        char choice;
        cin>>choice;
        choice= tolower(choice);
        
        if(choice=='y'){
            cout << "Searching for classes..." << endl;

            // Implement class searching functionality
            //Reading file
            fstream file;//Creating object
            file.open("student_classes.txt", ios::in);//opening file
            
            if(file.is_open()){
                cout<<"Here are your full classes: "<<endl;
                string line;
                while(getline(file, line)){
                    cout<<line<<endl;
                }
            }

            cout<<"Would you like to look for a specific class? (Y/N)?: ";
            char choice_class;
            cin>>choice_class;
            choice_class= tolower(choice_class);
            if(choice_class=='y'){
                search_per_class();
            }

            else{
                cout<<"Goodbye"<<endl;
            }
        }

        else{
            cout<<"Goodbye"<<endl;
        }
        
    }
   


    
};

//Talk to Teacher Class
class TalkToTeacher {
public:
    static void talk() {
        // Implement talking to teacher functionality
        cout << "Here are your teachers based on the Courses: " << endl;

        //printing teachers from external file
        fstream teacher_file;
        teacher_file.open("teachers_with_courses.txt", ios::in);
        if (teacher_file.is_open()) {
            string line;
            while (getline(teacher_file, line)) {
                cout << line << endl;
            }
            teacher_file.close();
        } else {
            cout << "Couldn't open file" << endl;
            return; // Exit the function if file couldn't be opened
        }

        //User Selection
        int teacher_choice;
        do {
            cout << "Select teacher based on number (1-8), or enter 0 to exit: ";
            cin >> teacher_choice;

            switch (teacher_choice) {
                case 1:
                    teacher_one_message();
                    break;
                case 2:
                    teacher_two_message();
                    break;
                case 3:
                    teacher_three_message();
                    break;
                case 4:
                    teacher_four_message();
                    break;
                case 5:
                    teacher_five_message();
                    break;
                case 6:
                    teacher_six_message();
                    break;
                case 7:
                    teacher_seven_message();
                    break;
                case 8:
                    teacher_eight_message();
                    break;
                case 0:
                    cout << "Exiting..." << endl;
                    return; // Exit the function
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (true);
    }

    static void teacher_one_message() {
        cout << "Hello, I'm glad you're here! Let's dive into the course material together." << endl;
        cout << "Email: garcia@example.com" << endl;
    }

    static void teacher_two_message() {
        cout << "Welcome to the AI Course! Feel free to send me emails and keep me updated on your progress." << endl;
        cout << "Email: giner@example.com" << endl;
    }

    static void teacher_three_message() {
        cout << "Hello students, I hope you're all doing well. Don't hesitate to reach out if you need assistance." << endl;
        cout << "Email: gruber@example.com" << endl;
    }

    static void teacher_four_message() {
        cout << "Greetings everyone! I'm excited to guide you through this course. Let's make it a great learning experience!" << endl;
        cout << "Email: johnson@example.com" << endl;
    }

    static void teacher_five_message() {
        cout << "Hi there! Let's work together to make this course a rewarding journey for all of us." << endl;
        cout << "Email: jerier@example.com" << endl;
    }

    static void teacher_six_message() {
        cout << "Hello students, I'm here to provide support and answer any questions you may have. Don't hesitate to ask!" << endl;
        cout << "Email: poltz@example.com" << endl;
    }

    static void teacher_seven_message() {
        cout << "Welcome to the class! My goal is to help you succeed, so feel free to reach out if you need assistance." << endl;
        cout << "Email: johnson@example.com" << endl;
    }

    static void teacher_eight_message() {
        cout << "Hello everyone! Let's make the most of this course and learn together." << endl;
        cout << "Email: lopez@example.com" << endl;
    }
};



int main() {
    int options_choice;
     cout<<endl;
    do{
   
    cout << " *****Welcome to the Student Registration System!*****" << endl;

    cout << "1. Student Registration" << endl;
    cout << "2. Search for class in your schedule" << endl;
    cout << "3. Talk to a teacher" << endl;
    cout << "4. Exit" << endl;
    cout << "Please enter your choice: ";
    cin >> options_choice;

    switch (options_choice){
        case 1:
            Registration::registerStudent();
            break;

        case 2:
            SearchClasses::search();
        
            break;

        case 3:
            TalkToTeacher::talk();
            break;

        case 4:
            exit(0);
            cout << "Exiting the Student Registration System. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
    }while(true);

    return 0;
}
