#include "library.h"
#include "Publishing.h"
#include <iostream>
#include <cstring>

Library::Library() : numPublications(0), maxPublications(5), numReaders(0), maxReaders(5) {
    publications = new Publishing * [maxPublications];
    readers = new User* [maxReaders];
}

Library::~Library() {
    for (int i = 0; i < numPublications; i++) {
        delete publications[i];
    }
    delete[] publications;

    for (int i = 0; i < numReaders; i++) {
        delete readers[i];
    }
    delete[] readers;
}
void Library::addPublication(Publishing* publication) {
    if (numPublications == maxPublications) {
        expandPublications();
    }
    publications[numPublications++] = publication;
}

void Library::removePublication(int libraryNumber) {
    for (int i = 0; i < numPublications; i++) {
        if (publications[i]->getLibraryNumber() == libraryNumber) {
            delete publications[i];
            publications[i] = publications[numPublications - 1];
            numPublications--;
            std::cout << "Publication with library number " << libraryNumber << " has been removed from the library." << std::endl;
            return;
        }
    }
    std::cout << "Publication with library number " << libraryNumber << " not found." << std::endl;
}

void Library::displayPublications() const {
    if (numPublications == 0) {
        std::cout << "No publications available in the library." << std::endl;
        return;
    }

    // Sort publications by year and title
    for (int i = 0; i < numPublications - 1; i++) {
        for (int j = 0; j < numPublications - i - 1; j++) {
            if (publications[j]->getYear() > publications[j + 1]->getYear()) {
                Publishing* temp = publications[j];
                publications[j] = publications[j + 1];
                publications[j + 1] = temp;
            }
            else if (publications[j]->getYear() == publications[j + 1]->getYear()) {
                if (strcmp(publications[j]->getTitle(), publications[j + 1]->getTitle()) > 0) {
                    Publishing* temp = publications[j];
                    publications[j] = publications[j + 1];
                    publications[j + 1] = temp;
                }
            }
        }
    }

    std::cout << "Available publications in the library:" << std::endl;
    for (int i = 0; i < numPublications; i++) {
        publications[i]->print();
        std::cout << std::endl;
    }
}

void Library::addUser(User* user) {
    if (numReaders == maxReaders) {
        expandReaders();
    }
    this->readers[numReaders++] = user;
}

void Library::removeUser(const char* userName) {
    for (int i = 0; i < numReaders; i++) {
        if (strcmp(readers[i]->getName(), userName) == 0) {
            delete readers[i];
            readers[i] = readers[numReaders - 1];
            numReaders--;
            std::cout << "User with name " << userName << " has been removed from the library." << std::endl;
            return;
        }
    }
    std::cout << "User with name " << userName << " not found." << std::endl;
}

void Library::displayOverduePublications() const {
    std::cout << "Overdue publications in the library:" << std::endl;
    for (int i = 0; i < numReaders; i++) {
        User* user = readers[i];
        const char* userName = user->getUsername();
        Publishing** borrowedPublication = user->getBorrowedPublications();

        while (borrowedPublication) {
            Publishing* publication = borrowedPublication->publication;
            if (publication->isOverdue()) {
                std::cout << "User: " << userName << std::endl;
                publication->print();
                std::cout << std::endl;
            }
            borrowedPublication = borrowedPublication->next;
        }
    }
}

void Library::displayUsersByNumBooksRead() const {
    if (numReaders == 0) {
        std::cout << "No users in the library." << std::endl;
        return;
    }

    // Sort users by number of books read
    for (int i = 0; i < numReaders - 1; i++) {
        for (int j = 0; j < numReaders - i - 1; j++) {
            if (readers[j]->getNumBooksRead() < readers[j + 1]->getNumBooksRead()) {
                User* temp = readers[j];
                readers[j] = readers[j + 1];
                readers[j + 1] = temp;
            }
        }
    }

    std::cout << "Users in the library sorted by number of books read:" << std::endl;
    for (int i = 0; i < numReaders; i++) {
        readers[i]->displayInfo();
        std::cout << std::endl;
    }
}

void Library::borrowPublication(const char* userName, int libraryNumber) {
    User* user = nullptr;
    for (int i = 0; i < numReaders; i++) {
        if (strcmp(readers[i]->getUsername(), userName) == 0) {
            user = readers[i];
            break;
        }
    }

    if (!user) {
        std::cout << "User with name " << userName << " not found." << std::endl;
        return;
    }

    Publishing* publication = nullptr;
    for (int i = 0; i < numPublications; i++) {
        if (publications[i]->getLibraryNumber() == libraryNumber) {
            publication = publications[i];
            break;
        }
    }

    if (!publication) {
        std::cout << "Publication with library number " << libraryNumber << " not found." << std::endl;
        return;
    }

    if (publication->isBorrowed()) {
        std::cout << "Publication with library number " << libraryNumber << " is already borrowed." << std::endl;
        return;
    }

    if (user->canBorrowPublication()) {
        user->borrowPublication(publication);
        std::cout << "User " << userName << " borrowed publication with library number " << libraryNumber << "." << std::endl;
    }
    else {
        std::cout << "User " << userName << " has reached the maximum number of borrowed publications." << std::endl;
    }
}

void Library::returnPublication(const char* userName, int libraryNumber) {
    User* user = nullptr;
    for (int i = 0; i < numReaders; i++) {
        if (strcmp(readers[i]->getUsername(), userName) == 0) {
            user = readers[i];
            break;
        }
    }

    if (!user) {
        std::cout << "User with name " << userName << " not found." << std::endl;
        return;
    }

    Publishing* publication = nullptr;
    for (int i = 0; i < numPublications; i++) {
        if (publications[i]->getLibraryNumber() == libraryNumber) {
            publication = publications[i];
            break;
        }
    }

    if (!publication) {
        std::cout << "Publication with library number " << libraryNumber << " not found." << std::endl;
        return;
    }

    if (!publication->isBorrowed()) {
        std::cout << "Publication with library number " << libraryNumber << " is not borrowed." << std::endl;
        return;
    }

    if (user->hasBorrowedPublication(publication)) {
        user->returnPublication(publication);
        std::cout << "User " << userName << " returned publication with library number " << libraryNumber << "." << std::endl;
    }
    else {
        std::cout << "User " << userName << " has not borrowed publication with library number " << libraryNumber << "." << std::endl;
    }
}

void Library::expandPublications() {
    maxPublications *= 2;
    Publishing** newPublications = new Publishing * [maxPublications];
    for (int i = 0; i < numPublications; i++) {
        newPublications[i] = publications[i];
    }
    delete[] publications;
    publications = newPublications;
}

void Library::expandReaders() {
    maxReaders *= 2;
    User** newUsers = new User * [maxReaders];
    for (int i = 0; i < numReaders; i++) {
        newUsers[i] = readers[i];
    }
    delete[] readers;
    readers = newUsers;
}

void Library::removeBorrowedPublication(User* user, int libraryNumber) {
    Publishing* borrowedPublication = user->getBorrowedPublications();
    Publishing* prevPublication = nullptr;

    while (borrowedPublication) {
        if (borrowedPublication->publication->getLibraryNumber() == libraryNumber) {
            if (prevPublication) {
                prevPublication->next = borrowedPublication->next;
            }
            else {
                user->setBorrowedPublications(borrowedPublication->next);
            }
            delete borrowedPublication;
            return;
        }
        prevPublication = borrowedPublication;
        borrowedPublication = borrowedPublication->next;
    }
}