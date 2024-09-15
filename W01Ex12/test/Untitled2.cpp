#include <iostream>
#include <string>
using namespace std;


struct AdministrativeUnit {
    int id;
    string name;
    string type; 
    AdministrativeUnit* next; 
};


class AdministrativeList {
private:
    AdministrativeUnit* head;

public:
    AdministrativeList() {
        head = NULL; 
    }

    
    void addAdministrativeUnit(int id, const string& name, const string& type) {
        AdministrativeUnit* newUnit = new AdministrativeUnit;
        newUnit->id = id;
        newUnit->name = name;
        newUnit->type = type;
        newUnit->next = head;
        head = newUnit;
    }

    
    void displayAdministrativeUnits() {
        AdministrativeUnit* current = head;
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name << ", Type: " << current->type << endl;
            current = current->next;
        }
    }

    
    AdministrativeUnit* findAdministrativeUnit(int id) {
        AdministrativeUnit* current = head;
        while (current != NULL) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return NULL; 
    }

    
    void deleteAdministrativeUnit(int id) {
        AdministrativeUnit* current = head;
        AdministrativeUnit* prev = NULL;

        while (current != NULL) {
            if (current->id == id) {
                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};
