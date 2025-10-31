# Student-Academic-Record-Management-System

📌 Project Overview



      Maintaining student academic records is a critical task in every educational institution.
      As the volume of data grows and changes frequently, static storage methods such as spreadsheets become inefficient.

      This project implements a dynamic Student Academic Record Management System using Doubly Linked Lists in C.
      It allows efficient insertion, deletion, searching, displaying, reversing, cloning, and calculating the average GPA of students.

      The goal of this system is to demonstrate the use of dynamic data structures for handling frequently changing data.


 🚀 Features


      ✔️ Insert new student records dynamically.
      
      ✔️ Delete a student by their ID.
      
      ✔️ Search for students by ID or Name.
      
      ✔️ Display all student records in order of entry.
      
      ✔️ Reverse display of student records (using doubly linked list).
      
      ✔️ Clone the list to create a backup copy.
      
      ✔️ Calculate the average GPA of all students.     


🧱 Data Structure Used


 🔹 Doubly Linked List
 
          typedef struct Student {
             int id;
             char name[50];
             char dept[30];
             float gpa;
             struct Student *prev, *next;
          } Student;

          

 Each student record is a node in the doubly linked list.

      * prev pointer points to the previous record.
      * next pointer points to the next record.  



🧩 Functions Explained 

    1. createNode()

          Creates a new student node using dynamic memory (malloc) and returns it.

                  Student* createNode(int id, char *name, char *dept, float gpa);
                  

    2. insertStudent()
    
          Adds a new student record at the end of the linked list.
          If the list is empty, the new node becomes the head.
          

    3. display()
    
          Traverses from the head to the end and prints all student records.
          If no records exist, it shows a message.
          

    4. deleteStudent(int id)
    
          Finds a student by ID and deletes the corresponding node.
          It correctly adjusts the prev and next links to maintain the DLL structure.
          

    5. searchByID(int id)

          Searches for a student by ID and displays their details if found.
          

    6. reverseDisplay()
    
          Starts from the last node and traverses backwards, showing the list in reverse order.
          

    7. averageGPA()
    
        Calculates and prints the average GPA of all students by summing all GPA values and dividing by the count.
        

    8. cloneList()

       Creates a duplicate copy of the entire linked list (node by node) and returns the new list’s head.

      

      



🧠 Main Function



    int main() {

    insertStudent(101, "Alice", "CSE", 8.5);
    
    insertStudent(102, "Bob", "ECE", 9.0);
    
    insertStudent(103, "Carol", "IT", 7.8);
    

    display();             // Show all records
    
    deleteStudent(102);    // Delete Bob
    
    display();             // Display again after deletion
    
    searchByID(103);       // Search for Carol
    
    reverseDisplay();      // Show records in reverse
    
    averageGPA();          // Show average GPA

    Student *backup = cloneList(); // Clone the list
    
    // Display cloned list
    
    ...
    }

