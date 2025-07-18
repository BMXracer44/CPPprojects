# include <iostream>
# include <fstream>
# include <vector>
using namespace std;

vector<Contacts> contacts;
void addContact(string firstName, string lastName, string phoneNumber);
Contacts searchContact(string search, vector<Contacts> contacts);
void displayContacts(vector<Contacts> contacts);


int main(){
    
    int function;
    string firstName;
    string lastName;
    string phoneNumber;
    cout << "Select a function:\n\t1. Add contact\n\t2. Search for existing contacts\n\t3. Display all contacts\n\t4. Quit";
    cin >> function;

    switch (function){
    case 1:
        cout << "Input first name: ";
        cin >> firstName;
        cout << "Input last name: ";
        cin >> lastName;
        cout << "Input phone number: ";
        cin >> phoneNumber;
        addContact(firstName, lastName, phoneNumber);
        break;

    case 2:
        searchContact(string search, vector<Contacts> contacts);
        break;

    case 3:
        displayContacts(contacts);
        break;

    case 4:
        return 0;

    default:
        cout << "Invalid function";
        break;
    }
}

void addContact(string firstName, string lastName, string phoneNumber){
    //Add to txt file and object to 'contacts'
    Contacts contact;
    contact.firstName = firstName;
    contact.lastName = lastName;
    contact.phoneNumber = phoneNumber;
    auto index = find(contacts.begin(), contacts.end(), contact);
    if(index != contacts.end()){
        cout << "Contact already exists";
    }
    else{
        contacts.push_back(contact); 
        ofstream outputFile;
        outputFile.open("contacts.txt", ios::app);
        if(outputFile.is_open()){
            outputFile << contacts.size() << ". " << contact.firstName << 
            contact.lastName << "/n/t" << contact.phoneNumber << endl;
        }
        else{
            cout << "Error saving contact";
        }
    }
}

Contacts searchContact(string search, vector<Contacts> contact){
    for(int i = 0; i < contacts.size(); i++){
        if(contacts[i].firstName == search || contacts[i].lastName == search || contacts[i].phoneNumber == search){
            contacts[i].print;
        }
        else{
            cout << "Contact not found";
        }
    }
}

void displayContacts(vector<Contacts> contacts){
    for(int i = 0; i < contacts.size(); i++){
        cout << i << ". " << contacts[i].firstName << 
            contacts[i].lastName << "/n/t" << contacts[i].phoneNumber << endl;
    }
}

class Contacts{
    public:
        string firstName;
        string lastName;
        string phoneNumber;
};