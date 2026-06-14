# Hospital-Patient-Queue-Management-System
Hospital Patient Queue Management System using LinkedLists and Queue
Overview:
The Hospital Patient Queue Management System is a console-based application developed in C++ that efficiently manages patient flow in a hospital setting. It implements core Data Structures and Algorithms (DSA) concepts including Queue (FIFO) for waiting lists, Linked Lists for dynamic patient records, and searching algorithms for fast patient lookup. The system supports patient registration, doctor assignment, and discharge management with priority levels (Normal/Urgent).
Problem Statement
Hospitals often struggle with managing patient waiting lists efficiently. Without a structured system, patients may face long wait times, and staff may find it difficult to locate patient records or prioritize urgent cases. There is a need for a digital solution that:
Maintains patient order using First-In-First-Out (FIFO) principle
Allows priority handling for urgent cases
Enables fast patient lookup by ID or name
Supports dynamic patient records (add, remove, search)
This project addresses these challenges using fundamental data structures.
Objectives
Implement a Queue to manage patient waiting lists (FIFO)
Use a Linked List to store and manage dynamic patient records
Apply searching algorithms for quick patient lookup
Support patient registration, doctor assignment, and discharge
Handle priority levels (Normal / Urgent)
Provide a simple, interactive console-based interface
Data Structures Used:
Data Structure	Purpose
Queue (FIFO)	Manages the waiting list — patients are served in order of arrival
Linked List — Stores dynamic patient records (supports insertion, deletion, traversal)
Searching Algorithms — Enables fast patient lookup by ID or name
Features:
1. Patient Registration
Add new patients to the system
Collect details: Name, Age, Contact, Symptoms
Assign a unique Patient ID
Set priority level: Normal or Urgent
2. Queue Management (Waiting List)
Patients join the waiting list in FIFO order
Urgent patients can be moved ahead (priority handling)
Display current waiting list
3. Doctor Assignment
Assign available doctors to patients
Track which doctor is handling which patient
4. Patient Discharge
Remove patient from the system after treatment
Maintain history or simply delete from active records
5. Fast Patient Lookup
Search patients by ID or Name using efficient searching algorithms
Display complete patient information
System Workflow:
Patient Arrives → Register Patient → Assign Priority (Normal/Urgent) → Add to Queue → Doctor Available? → Assign Doctor → Treatment → Discharge → Remove from System

OUTPUT:
<img width="331" height="179" alt="Screenshot 2026-06-14 154649" src="https://github.com/user-attachments/assets/dada5b72-f437-4b1c-8485-a4f765389032" />


