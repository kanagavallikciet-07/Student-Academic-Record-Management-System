#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student node
typedef struct Student {
    int id;
    char name[50];
    char dept[30];
    float gpa;
    struct Student *prev, *next;
} Student;

// Head pointer for the linked list
Student *head = NULL;

// Create new student node
Student* createNode(int id, const char *name, const char *dept, float gpa) {
    Student *newNode = (Student*)malloc(sizeof(Student));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->dept, dept);
    newNode->gpa = gpa;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert a new student at the end
void insertStudent(int id, const char *name, const char *dept, float gpa) {
    Student *newNode = createNode(id, name, dept, gpa);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Student *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display all student records
void display() {
    if (head == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    Student *temp = head;
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Dept: %s | GPA: %.2f\n",
               temp->id, temp->name, temp->dept, temp->gpa);
        temp = temp->next;
    }
}

// Delete a student by ID
void deleteStudent(int id) {
    if (head == NULL) {
        printf("No records to delete.\n");
        return;
    }

    Student *temp = head;

    // Find the node with the given ID
    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Student with ID %d not found!\n", id);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Student with ID %d deleted successfully.\n", id);
}

// Search by ID
void searchByID(int id) {
    Student *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nFound: ID: %d | Name: %s | Dept: %s | GPA: %.2f\n",
                   temp->id, temp->name, temp->dept, temp->gpa);
            return;
        }
        temp = temp->next;
    }
    printf("\nNo record found for ID %d\n", id);
}

// Reverse display of student records
void reverseDisplay() {
    if (head == NULL) {
        printf("\nNo student records to display in reverse.\n");
        return;
    }

    Student *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("\n--- Reverse Student Records ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Dept: %s | GPA: %.2f\n",
               temp->id, temp->name, temp->dept, temp->gpa);
        temp = temp->prev;
    }
}

// Calculate average GPA
void averageGPA() {
    if (head == NULL) {
        printf("\nNo records available to calculate average GPA.\n");
        return;
    }

    float total = 0.0f;
    int count = 0;
    Student *temp = head;

    while (temp != NULL) {
        total += temp->gpa;
        count++;
        temp = temp->next;
    }

    printf("\nAverage GPA of all students: %.2f\n", total / count);
}

// Clone the student list
Student* cloneList() {
    if (head == NULL) {
        printf("\nNo records to clone.\n");
        return NULL;
    }

    Student *cloneHead = NULL, *cloneTail = NULL;
    Student *temp = head;

    while (temp != NULL) {
        Student *newNode = createNode(temp->id, temp->name, temp->dept, temp->gpa);
        if (cloneHead == NULL) {
            cloneHead = cloneTail = newNode;
        } else {
            cloneTail->next = newNode;
            newNode->prev = cloneTail;
            cloneTail = newNode;
        }
        temp = temp->next;
    }

    printf("\nList cloned successfully!\n");
    return cloneHead;
}

int main() {
    insertStudent(101, "Alice", "CSE", 8.5);
    insertStudent(102, "Bob", "ECE", 9.0);
    insertStudent(103, "Carol", "IT", 7.8);

    display();

    deleteStudent(102);
    display();

    searchByID(103);
    reverseDisplay();
    averageGPA();

    Student *backup = cloneList();

    printf("\n--- Displaying Cloned List ---\n");
    Student *temp = backup;
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Dept: %s | GPA: %.2f\n",
               temp->id, temp->name, temp->dept, temp->gpa);
        temp = temp->next;
    }

    return 0;
}
