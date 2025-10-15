#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
   if (size >= capacity) {
      throw "Student list at capacity.";
   }
   size_t len = std::strlen(name);
   names[size] = new char[len+1];
   std::strcpy(names[size], name);
   gpas[size] = gpa;
   ++size;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
   if (gpaPtr != nullptr) {
      *gpaPtr = newGpa;
   }
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
   std::cout << "Name: " << name << " GPA: " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
   if (size == 0) {
      throw "No students in list.";
   }
   double sum = 0.0;
   for (int i = 0; i < size; ++i) {
      sum += gpas[i];
   }
   double avg = sum / size;
   return avg;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
	        std::string name;
		double gpa;

		std::cout << "Enter student name: " << std::endl;
		std::getline(std::cin, name);
		char tempName[100];
		std::strcpy(tempName, name.c_str());

		std::cout << "Enter GPA: " << std::endl;
		std::cin >> gpa;

		try {
		   addStudent(tempName, gpa, names, gpas, size, capacity);
		   std::cout << "Student added.\n";
		} catch (const char* msg) {
		     std::cout << "Error: " << msg << std::endl;
		}
                break;
            }
            case 2: {
                // TODO: implement menu logic
		if (size == 0) {
		   std::cout << "No students in the list.\n" << std::endl;
		   break;
		}
		int index;
		double newGpa;
		std::cout << "Enter student index: " << std::endl;
		std::cin >> index;

		if (index >= 0 && index < size) {
		   std::cout << "Enter new GPA: " << std::endl;
		   std::cin >> newGpa;
	       	   try {
		      updateGPA(&gpas[index], newGpa);
		      std::cout << "GPA updated.\n" << std::endl;
		   } catch (const char* msg) {
		       std::cout << "Error: " << msg << std::endl;
		   }
		}
                break;
            }
            case 3: {
                // TODO: implement menu logic
		if (size == 0) {
		   std::cout << "No students in the list.\n" << std::endl;
		   break;
		}
		for (int i = 0; i < size; ++i) {
		   std::cout << (i+1) << ". ";
		   printStudent(names[i], gpas[i]);
		}
                break;
            }
            case 4: {
                // TODO: implement menu logic
		try {
		   double avg = averageGPA(gpas, size);
		   std::cout << "Average GPA: " << static_cast<int>(avg) << std::endl;
		} catch (const char* msg) {
		    std::cout << "Error: " << msg << std::endl;
		}
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    delete[] names;
    delete[] gpas;

    return 0;
}

