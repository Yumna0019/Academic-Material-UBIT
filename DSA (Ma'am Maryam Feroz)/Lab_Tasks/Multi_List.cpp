#include <iostream>
#include <stdlib.h>

// Forward declarations of Course and Student structures.
struct Course;
struct Student;

// Course structure definition.
struct Course
{
    int c_no;
    Course *next;    // Pointer to the next course in the list.
    Course *cprev;   // Unused in this code.
    Student *sstart; // Pointer to the list of students enrolled in this course.
} *cstart = NULL;    // Pointer to the start of the course list.

// Student structure definition.
struct Student
{
    int std_id;
    int course_no;
    Student *next_std; // Pointer to the next student in the same course.
    Student *sprev;    // Unused in this code.
} *sstart = NULL;      // Pointer to the start of the student list.

// Function to insert a new Course.
void insert_Course()
{
    struct Course *ctemp = (struct Course *)malloc(sizeof(struct Course)); // Allocate memory for a new Course node.

    std::cout << "Enter Course number: ";
    std::cin >> ctemp->c_no;

    ctemp->next = NULL;   // Initialize the next pointer to NULL.
    ctemp->sstart = NULL; // Initialize the student list pointer to NULL.

    struct Course *ccurr = cstart; // Create a pointer to traverse the course list.
    if (cstart == NULL)
    {
        cstart = ctemp; // If the course list is empty, set the new course as the start.
        return;
    }
    else
    {
        // Traverse the course list to find the last course and append the new course.
        while (ccurr->next != NULL)
        {
            ccurr = ccurr->next;
        }
        ccurr->next = ctemp; // Append the new course to the end of the list.
    }
}

// Function to print the list of courses.
void print_Course()
{
    if (cstart == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }
    struct Course *ccurr = cstart; // Create a pointer to traverse the course list.
    std::cout << "Total Courses: " << std::endl;

    while (ccurr != NULL)
    {
        std::cout << ccurr->c_no << " , "; // Print the course number.
        ccurr = ccurr->next;               // Move to the next course in the list.
    }
    std::cout << "null" << std::endl;
}

// Function to insert a new Student into a Course.
void insert_Student()
{
    struct Student *stemp = new Student; // Allocate memory for a new Student node.

    std::cout << "Enter Student ID: ";
    std::cin >> stemp->std_id;
    std::cout << "Enter Course number you want to enroll in: ";
    std::cin >> stemp->course_no;

    stemp->next_std = NULL; // Initialize the next student pointer to NULL.

    Course *ccurr = cstart; // Create a pointer to traverse the course list.

    // Find the course where the student wants to enroll.
    while (ccurr != NULL && ccurr->c_no != stemp->course_no)
    {
        ccurr = ccurr->next;
    }

    if (ccurr == NULL)
    {
        std::cout << "No course available !!!" << std::endl;
        delete (stemp); // Delete the allocated Student node if the course is not found.
        return;
    }

    if (ccurr->sstart == NULL)
    {
        ccurr->sstart = stemp; // If the student list in the course is empty, set the new student as the start.
    }
    else
    {
        Student *scurr = ccurr->sstart; // Create a pointer to traverse the student list in the course.

        // Traverse the student list in the course to find the last student and append the new student.
        while (scurr->next_std != NULL)
        {
            scurr = scurr->next_std;
        }
        scurr->next_std = stemp; // Append the new student to the end of the list.
    }
}

// Function to print the list of courses and students enrolled in each course.
void print_courses_and_student()
{
    Course *ccurr = cstart; // Create a pointer to traverse the course list.
    int course_Count = 0;   // Initialize a counter for the number of courses.

    // Iterate through the course list.
    while (ccurr != NULL)
    {
        std::cout << "Course " << ccurr->c_no << " Students: ";

        Student *scurr = ccurr->sstart; // Create a pointer to traverse the student list in the current course.

        // Iterate through the student list in the current course.
        while (scurr != NULL)
        {
            std::cout << scurr->std_id << " , "; // Print the student ID.
            scurr = scurr->next_std;             // Move to the next student in the course.
        }

        std::cout << std::endl;
        ccurr = ccurr->next; // Move to the next course in the list.
        course_Count++;      // Increment the course count.
    }
    std::cout << "Total Courses: " << course_Count << std::endl;
}

// Function to delete a specific course.
int delete_Course()
{
    int todelete;
    std::cout << "Enter Course number which you want to delete: " << std::endl;
    std::cin >> todelete;

    Course *ccurr = cstart; // Initialize a pointer to traverse the course list.
    Course *cprev = NULL;   // Initialize a pointer to keep track of the previous course.

    while (ccurr != NULL)
    {
        // Check if the current course matches the course to be deleted.
        if (ccurr->c_no == todelete)
        {
            if (cprev == NULL)
            {
                cstart = ccurr->next; // If the course to delete is the first course in the list, update the start pointer.
            }
            else
            {
                cprev->next = ccurr->next; // Update the previous course's next pointer to skip the current course.
            }
            delete (ccurr); // Delete the current course to free memory.
            std::cout << "The Course Number " << todelete << " is deleted." << std::endl;
            return 1; // Indicate success.
        }
        cprev = ccurr;       // Update the previous course pointer.
        ccurr = ccurr->next; // Move to the next course in the list.
    }
    std::cout << "The Course Number " << todelete << " was not found." << std::endl;
    return 0; // Return 0 if the course to delete was not found in the list.
}

// Function to delete a specific student from a specific course.
int delete_Student_From_Course()
{
    int search_ID, c_No;
    std::cout << "Enter the student ID to be deleted from a specific Course. ";
    std::cin >> search_ID;

    std::cout << "Enter the Course No.: ";
    std::cin >> c_No;

    // Start by traversing the list of courses.
    Course *ccurr = cstart;
    while (ccurr != NULL)
    {
        // Check if the current course matches the specified course number.
        if (ccurr->c_no == c_No)
        {
            Student *scurr = ccurr->sstart; // Initialize a pointer to traverse the list of students within the current course.
            Student *sprev = NULL;          // A pointer to keep track of the previous student node.

            while (scurr != NULL)
            {
                // Check if the current student's ID matches the specified SearchID.
                if (scurr->std_id == search_ID)
                {
                    if (sprev == NULL)
                    {
                        ccurr->sstart = scurr->next_std; // If the student to delete is the first in the course, update the course's start pointer.
                    }
                    else
                    {
                        sprev->next_std = scurr->next_std; // If the student to delete is not the first in the course, update the previous student's next pointer.
                    }

                    delete (scurr); // Delete the student node to free up memory.
                    std::cout << "The student of ID " << search_ID << " is deleted from Course No. " << c_No << std::endl;
                    return 1; // Indicate successful deletion.
                }
                // Move to the next student in the course.
                sprev = scurr;
                scurr = scurr->next_std;
            }
            std::cout << "Student with ID " << search_ID << " not found in Course No. " << c_No << std::endl;
            return 0;
        }
        ccurr = ccurr->next; // Move to the next course in the list.
    }
    std::cout << "Course No. " << c_No << " not found." << std::endl;
    return 0; // If the specified student was not found in any course, return 0 to indicate failure.
}

// Function to delete all the students from a specific course.
int delete_All_Students_From_Course()
{
    int search_Course;
    std::cout << "Enter the Course Number from which you want to delete the students: ";
    std::cin >> search_Course;

    Course *ccurr = cstart; // Initialize a pointer to traverse the course list.
    while (ccurr != NULL)
    {
        if (ccurr->c_no == search_Course)
        {
            Student *scurr = ccurr->sstart; // Initialize a pointer to traverse the list of students within the current course.
            while (scurr != NULL)
            {
                Student *stemp = scurr;  // Store the current student node in stemp.
                scurr = scurr->next_std; // Move to the next student in the course.
                delete (stemp);          // Delete the student node stored in stemp to free up memory.
            }
            ccurr->sstart = NULL; // Set the course's start pointer to NULL to indicate no students in that course.
        }
        ccurr = ccurr->next; // Move to the next course in the list.
    }
    return 0;
}

int main()
{
    int i;
    std::string input = "y"; // Initialize input to "y"

    while (input == "y")
    {
        std::cout << "Choose an operation: \n 1. Insert a Course. \n 2. Delete a Course. \n 3. Add a student to a Course. \n 4. Delete a student from a Course. \n 5. Delete a student's ID from all Courses. \n 6. Print Courses and Students enrolled." << std::endl;
        std::cin >> i;

        switch (i)
        {
        case 1:
            insert_Course();
            print_Course();
            std::cout << std::endl;
            break;
        case 2:
            delete_Course();
            break;
        case 3:
            insert_Student();
            break;
        case 4:
            delete_Student_From_Course();
            break;
        case 5:
            delete_All_Students_From_Course();
            break;
        case 6:
            print_courses_and_student();
            break;
        default:
            std::cout << "Invalid number. Try again." << std::endl;
        }
        std::cout << "Do you want to continue? y/n: ";
        std::cin >> input;
    }

    return 0;
}
