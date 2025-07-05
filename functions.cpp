#include "header.h"

// Cedar Manning -- cedarman@pdx.edu
// PROGRAM #2 - CS302

// FUNCTIONS.CPP
// Function file for Core Hierarchy implementation

// Error code declaration
// ----------------------
errorCode::errorCode(const string & message)    :   description(message)
{}

// Base Class Declarations
// ----------------------
Client::Client()
{
    clientName = nullptr;
    contactEmail = "";
    domainCount = 0;
}

Client::~Client()
{
    clientName = nullptr;
    contactEmail = "";
    domainCount = 0;
}

Client::Client(const Client & other)  :   contactEmail(other.contactEmail) , domainCount(other.domainCount)
{
    if(!other.clientName) clientName = nullptr;
    clientName = new char[strlen(other.clientName) + 1];
    strcpy(clientName, other.clientName);
}

int Client::display() const
{
    if(!clientName)
    {
        throw errorCode("Attempted to Display Empty Client");
        return 0;
    }
    cout << "Client Name: " << clientName << endl;
    cout << "Email: " << contactEmail << endl;
    cout << "Num Domains: " << domainCount << endl;
    return 1;
}

int Client::input()
{
    if(clientName)
    {
        throw errorCode("Attempted to Overwrite Full Client");
        return 0;
    }
    char nme[30];

    cout << "Enter your name: ";
    cin.get(nme, 30, '\n');
    cin.ignore(100, '\n');

    cout << "Contact Email: ";
    cin >> contactEmail;
    cin.ignore(100, '\n');

    cout << "Domain Count: ";
    cin >> domainCount;
    cin.ignore(100, '\n');

    // allocate

    clientName = new char[strlen(nme) + 1];
    strcpy(clientName,nme);

    return 1;
}

int Client::copy(const Client & other)
{
    if(!other.clientName || !strcmp(clientName, other.clientName)) return 0;

    if(clientName) delete [] clientName;
    clientName = new char[strlen(other.clientName) + 1];
    strcpy(clientName, other.clientName);

    contactEmail = other.contactEmail;
    domainCount = other.domainCount;

    return 1;
}

Client & Client::operator = (const Client& other)
{
    if(*this == other) return *this;

    if(!other.clientName) 
    {
        clientName = nullptr;
        throw errorCode("Null 'other' client name when attempting to assign");
    }

    copy(other);
    return *this;
}

bool Client::operator == (const Client& other) const
{
    return !strcmp(clientName, other.clientName);
}

bool Client::operator != (const Client& other) const
{
    return strcmp(clientName, other.clientName);
}

bool Client::operator < (const Client& other) const
{
    if(strcmp(clientName, other.clientName) < 0) return true;
    return false;

}

bool Client::operator <= (const Client& other) const
{
    if(strcmp(clientName, other.clientName) <= 0) return true;
    return false;
}

bool Client::operator > (const Client& other) const
{
    if(strcmp(clientName, other.clientName) > 0) return true;
    return false;
}

bool Client::operator >= (const Client& other) const
{
    if(strcmp(clientName, other.clientName) >= 0) return true;
    return false;
}

ostream & operator << (ostream& out, const Client& client)
{   
    client.display();

    return out;
}

istream & operator >> (istream& in, Client& client)
{
    client.input();

    return in;
}

// ----------------------
// Derived Implementation Below
// ----------------------

// Personal
// ----------------------
Personal::Personal()
{
    preferredDomain = "";
    emailAccountCount = 0;
}

Personal::~Personal()
{
    preferredDomain = "";
    emailAccountCount = 0;
}

Personal::Personal(const Personal & other)  :   preferredDomain(other.preferredDomain), emailAccountCount(other.emailAccountCount)
{}

int Personal::display() const
{
    Client::display();
    cout << "Preferred Domain: " << preferredDomain << endl;
    cout << "Email Account Count: " << emailAccountCount << endl;
    return 1;
}

ostream & operator << (ostream& out, const Personal & personal)
{   
    personal.display();

    return out;
}

Personal& Personal::operator = (const Personal& other)
{
    if (this == &other) return *this;

    Client::operator=(other);

    // Now copy the derived class’s own members
    this->preferredDomain = other.preferredDomain;
    this->emailAccountCount = other.emailAccountCount;

    return *this;
}

int Personal::input()
{
    Client::input();

    cout << "Enter Preferred Domain: ";
    cin >> preferredDomain;
    cin.ignore(100, '\n');

    cout << "Enter Email Account Count: ";
    cin >> emailAccountCount;
    cin.ignore(100, '\n');

    return 1;
}

// Business Implentation
// ----------------------
Business::Business()
{
    subdomainPrefix = "";
    emailForwardingEnabled = true;
}

Business::Business(const Business & other)  :   subdomainPrefix(other.subdomainPrefix), emailForwardingEnabled(other.emailForwardingEnabled)
{}

Business::~Business()
{
    subdomainPrefix = "";
    emailForwardingEnabled = true;
}

int Business::display() const
{
    Client::display();

    cout << "Subdomain Prefix: " << subdomainPrefix << endl;
    cout << "Forwarding Enabled: " << emailForwardingEnabled << endl;

    return 1;
}

ostream & operator << (ostream& out, const Business & business)
{   
    business.display();

    return out;
}

Business& Business::operator = (const Business& other)
{
    if (this == &other) return *this;

    Client::operator=(other);

    this->subdomainPrefix = other.subdomainPrefix;
    this->emailForwardingEnabled = other.emailForwardingEnabled;

    return *this;
}

int Business::input()
{
    Client::input();

    cout << "Enter Subdomain Prefix: ";
    cin >> subdomainPrefix;
    cin.ignore(100, '\n');

    return 1;
}


// Corporate Implementation
// ----------------------
Corporate::Corporate()
{
    departmentTag = nullptr;
    employeeEmailCount = 0;
}

Corporate::Corporate(const Corporate & other)   :   employeeEmailCount(other.employeeEmailCount)
{
    if(other.departmentTag)
    {
        departmentTag = new char[strlen(other.departmentTag) + 1];
        strcpy(departmentTag, other.departmentTag);
    }
    else departmentTag = nullptr;
}

Corporate::~Corporate()
{
    if(departmentTag) delete [] departmentTag;
    departmentTag = nullptr;
    employeeEmailCount = 0;
}

int Corporate::display() const
{
    Client::display();

    cout << "Department Tag: " << departmentTag << endl;
    cout << "Employee Email Count: " << employeeEmailCount << endl;
    return 1;
}

ostream & operator << (ostream& out, const Corporate & corporate)
{   
    corporate.display();

    return out;
}

Corporate& Corporate::operator=(const Corporate& other)
{
    if (this == &other) return *this;

    Client::operator=(other);

    if(departmentTag) delete[] departmentTag;
    departmentTag = nullptr;

    if (other.departmentTag)
    {
        departmentTag = new char[strlen(other.departmentTag) + 1];
        strcpy(departmentTag, other.departmentTag);
    }
    else
    {
        departmentTag = nullptr;
        throw errorCode("Null 'other' client name when attempting to assign");
    }

    employeeEmailCount = other.employeeEmailCount;

    return *this;
}

int Corporate::input()
{
    Client::input();

    char tag[30];

    cout << "Enter Department Tag: ";
    cin.get(tag, 30, '\n');
    departmentTag = new char[strlen(tag) + 1];
    strcpy(departmentTag, tag);

    cout << "Enter Employee Email Account: ";
    cin >> employeeEmailCount;
    cin.ignore(100, '\n');
    return 1;
}
