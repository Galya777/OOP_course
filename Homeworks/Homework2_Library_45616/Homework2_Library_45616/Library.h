#include "Publishing.h"
#include "User.h"
class Library {
public:
    Library();
    ~Library();

    void addPublication(Publishing* publication);
    void removePublication(int libraryNumber);
    void displayPublications() const;
    void addUser(User* user);
    void removeUser(const char* name);
    void displayOverduePublications() const;
    void displayUsersByNumBooksRead() const;
    void displayReaders() const;
    void borrowPublication(const char* readerName, int libraryNumber);
    void returnPublication(const char* readerName, int libraryNumber);

private:

    Publishing** publications;
    User** readers;
    int numPublications;
    int maxPublications;
    int numReaders;
    int maxReaders;

    void expandPublications();
    void expandReaders();
    void removeBorrowedPublication(User* reader, int libraryNumber);
};

