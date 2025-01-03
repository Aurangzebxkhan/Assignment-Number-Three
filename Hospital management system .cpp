#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store patient details
struct Patient {
    int patientID;
    string name;
    int age;
    string disease;
    int roomNumber;
};


adnnnaaaan
// Function prototypes to manage patient records
void loadPatients(vector<Patient>& patients, const string& filename);
void savePatients(const vector<Patient>& patients, const string& filename);
void addPatient(vector<Patient>& patients);
void searchPatient(const vector<Patient>& patients);
void displayPatients(const vector<Patient>& patients);

//main function to run the program
int main() {
    vector<Patient> patients;
    const string filename = "patient_records.txt";

    // Load patient records from file
    loadPatients(patients, filename);

    int choice;
    do {
        cout << "\nHospital Patient Management System" << endl;
        cout << "1. Add a new patient" << endl;
        cout << "2. Search for a patient" << endl;
        cout << "3. Display all patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
<<<<<<< Updated upstream
//using switch statment
=======
    //Using switch statment 
>>>>>>> Stashed changes
        switch (choice) {
            case 1:
                addPatient(patients);
                break;
            case 2:
                searchPatient(patients);
                break;
            case 3:
                displayPatients(patients);
                break;
            case 4:
                savePatients(patients, filename);
                cout << "Exiting... Records saved." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
// my name is xyz this if only for checking 
<<<<<<< Updated upstream
//Function to load a file to a vector
void loadPatients(vector<Patient>& patients, const string& filename) {
    ifstream file(filename);
    rtrrwqq
=======
//Funtion to Load patients from a file to a vector
void loadPatients(vector<Patient>& patients, const string& filename) {
    ifstream file(filename);
    //Open the file for reading
>>>>>>> Stashed changes
    if (!file.is_open()) {
        cout << "No existing records found. Starting fresh." << endl;
        return;
    }

    Patient patient;
    while (file >> patient.patientID) {
        file.ignore(); // Skip newline
        getline(file, patient.name);
        file >> patient.age;
        file.ignore();
        getline(file, patient.disease);
        file >> patient.roomNumber;
        patients.push_back(patient);
    }
    file.close();
}

void savePatients(const vector<Patient>& patients, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error saving records." << endl;
        return;
    }

    for (const auto& patient : patients) {
        file << patient.patientID << endl;
        file << patient.name << endl;
        file << patient.age << endl;
        file << patient.disease << endl;
        file << patient.roomNumber << endl;
    }
    file.close();
}

void addPatient(vector<Patient>& patients) {
    Patient newPatient;
    cout << "Enter Patient ID: ";
    cin >> newPatient.patientID;
    cin.ignore(); // Ignore newline
    cout << "Enter Name: ";
    getline(cin, newPatient.name);
    cout << "Enter Age: ";
    cin >> newPatient.age;
    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, newPatient.disease);
    cout << "Enter Room Number: ";
    cin >> newPatient.roomNumber;

    patients.push_back(newPatient);
    cout << "Patient added successfully!" << endl;
}

void searchPatient(const vector<Patient>& patients) {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    for (const auto& patient : patients) {
        if (patient.patientID == id) {
            cout << "\nPatient Found:\n";
            cout << "ID: " << patient.patientID << endl;
            cout << "Name: " << patient.name << endl;
            cout << "Age: " << patient.age << endl;
            cout << "Disease: " << patient.disease << endl;
            cout << "Room Number: " << patient.roomNumber << endl;
            return;
        }
    }
    cout << "Patient not found." << endl;
}

void displayPatients(const vector<Patient>& patients) {
    if (patients.empty()) {
        cout << "No patient records available." << endl;
        return;
    }

    cout << left << setw(10) << "Patient ID" << setw(20) << "Name" << setw(5) << "Age" << setw(20) << "Disease" << setw(10) << "Room No" << endl;
    cout << string(65, '-') << endl;
    for (const auto& patient : patients) {
        cout << left << setw(10) << patient.patientID << setw(20) << patient.name << setw(5) << patient.age << setw(20) << patient.disease << setw(10) << patient.roomNumber << endl;
    }
}
