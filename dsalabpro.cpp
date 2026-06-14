#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------
//  PATIENT CLASS
// -----------------------------------------
class Patient {
public:
    int    id;
    string name;
    int    age;
    string disease;
    string priority;
    Patient* next;

    Patient(int id, string name, int age, string disease, string priority) {
        this->id       = id;
        this->name     = name;
        this->age      = age;
        this->disease  = disease;
        this->priority = priority;
        next           = nullptr;
    }

    void displayInfo() {
        cout << "  ID       : " << id       << "\n";
        cout << "  Name     : " << name     << "\n";
        cout << "  Age      : " << age      << "\n";
        cout << "  Disease  : " << disease  << "\n";
        cout << "  Priority : " << priority << "\n";
    }
};

// -----------------------------------------
//  QUEUE CLASS (FIFO)
// -----------------------------------------
class PatientQueue {
private:
    Patient* front;
    Patient* rear;

public:
    PatientQueue() {
        front = nullptr;
        rear  = nullptr;
    }

    void enqueue(Patient* p) {
        p->next = nullptr;
        if (rear == nullptr) {
            front = rear = p;
        } else {
            rear->next = p;
            rear = p;
        }
        cout << "  [+] " << p->name << " added to waiting queue.\n";
    }

    Patient* dequeue() {
        if (front == nullptr) {
            cout << "  Queue is empty. No patients waiting.\n";
            return nullptr;
        }
        Patient* called = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        called->next = nullptr;
        return called;
    }

    void viewQueue() {
        if (front == nullptr) {
            cout << "  No patients in the queue.\n";
            return;
        }
        Patient* temp = front;
        int pos = 1;
        cout << "  Position | ID   | Name             | Priority\n";
        cout << "  ---------+------+------------------+---------\n";
        while (temp != nullptr) {
            cout << "     " << pos++ << "      | "
                 << temp->id << "   | "
                 << temp->name;
            for (int i = temp->name.length(); i < 18; i++) cout << " ";
            cout << "| " << temp->priority << "\n";
            temp = temp->next;
        }
    }
};

// -----------------------------------------
//  HOSPITAL SYSTEM CLASS
// -----------------------------------------
class HospitalSystem {
private:
    Patient* patients[100];
    int      totalPatients;
    int      nextID;
    PatientQueue waitingQueue;

public:
    HospitalSystem() {
        totalPatients = 0;
        nextID        = 1001;
        for (int i = 0; i < 100; i++) patients[i] = nullptr;
    }

    void registerPatient() {
        string name, disease, priority;
        int    age;

        cout << "\n  Enter Name     : "; cin.ignore(); getline(cin, name);
        cout << "  Enter Age      : "; cin >> age;
        cin.ignore();
        cout << "  Enter Disease  : "; getline(cin, disease);
        cout << "  Priority (Normal / Urgent): "; getline(cin, priority);

        if (priority != "Urgent" && priority != "Normal")
            priority = "Normal";

        Patient* p = new Patient(nextID++, name, age, disease, priority);
        patients[totalPatients++] = p;

        cout << "\n  [OK] Patient registered. ID: " << p->id << "\n";
        waitingQueue.enqueue(p);
    }

    Patient* searchByID(int id) {
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i] != nullptr && patients[i]->id == id)
                return patients[i];
        }
        return nullptr;
    }

    Patient* searchByName(string name) {
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i] != nullptr && patients[i]->name == name)
                return patients[i];
        }
        return nullptr;
    }

    void searchPatient() {
        int choice;
        cout << "\n  Search by:\n  1. ID\n  2. Name\n  Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "  Enter Patient ID: "; cin >> id;
            Patient* p = searchByID(id);
            if (p) { cout << "\n  Patient Found:\n"; p->displayInfo(); }
            else     cout << "  Patient not found.\n";
        } else {
            string name;
            cout << "  Enter Patient Name: "; cin.ignore(); getline(cin, name);
            Patient* p = searchByName(name);
            if (p) { cout << "\n  Patient Found:\n"; p->displayInfo(); }
            else     cout << "  Patient not found.\n";
        }
    }

    void updatePatient() {
        int id;
        cout << "\n  Enter Patient ID to update: "; cin >> id;
        Patient* p = searchByID(id);
        if (!p) { cout << "  Patient not found.\n"; return; }

        cout << "  Current Disease : " << p->disease  << "\n";
        cout << "  New Disease     : "; cin.ignore(); getline(cin, p->disease);
        cout << "  Current Priority: " << p->priority << "\n";
        cout << "  New Priority (Normal / Urgent): "; getline(cin, p->priority);
        cout << "  [OK] Patient record updated.\n";
    }

    void dischargePatient() {
        int id;
        cout << "\n  Enter Patient ID to discharge: "; cin >> id;
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i] != nullptr && patients[i]->id == id) {
                cout << "  [OK] Patient " << patients[i]->name << " discharged.\n";
                delete patients[i];
                patients[i] = nullptr;
                return;
            }
        }
        cout << "  Patient not found.\n";
    }

    void callNextPatient() {
        cout << "\n  Calling next patient...\n";
        Patient* p = waitingQueue.dequeue();
        if (p) {
            cout << "  [->] Now serving: " << p->name
                 << " (ID: " << p->id << ", Priority: " << p->priority << ")\n";
        }
    }

    void viewWaitingQueue() {
        cout << "\n  -- Current Waiting List --\n";
        waitingQueue.viewQueue();
    }

    ~HospitalSystem() {
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i] != nullptr) delete patients[i];
        }
    }
};

// -----------------------------------------
//  MAIN MENU
// -----------------------------------------
int main() {
    HospitalSystem hospital;
    int choice;

    cout << "\n  ============================================\n";
    cout << "    Hospital Patient Queue Management System \n";
    cout << "  ============================================\n";

    do {
        cout << "\n  -- MAIN MENU --\n";
        cout << "  1.  Register New Patient\n";
        cout << "  2.  Search Patient\n";
        cout << "  3.  Update Patient Record\n";
        cout << "  4.  Discharge Patient\n";
        cout << "  5.  View Waiting Queue\n";
        cout << "  6.  Call Next Patient\n";
        cout << "  0.  Exit\n";
        cout << "\n  Enter choice: ";
        cin >> choice;

        cout << "\n";
        switch (choice) {
            case 1: hospital.registerPatient();  break;
            case 2: hospital.searchPatient();    break;
            case 3: hospital.updatePatient();    break;
            case 4: hospital.dischargePatient(); break;
            case 5: hospital.viewWaitingQueue(); break;
            case 6: hospital.callNextPatient();  break;
            case 0: cout << "  Goodbye!\n"; break;
            default: cout << "  Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}