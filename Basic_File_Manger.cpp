#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void listFiles(const string &path) {
  DIR *dir;
  struct dirent *entry;
  // open all directory
  if ((dir = opendir(path.c_str())) != nullptr) {
    while ((entry = readdir(dir)) != nullptr) {
      // print all directory name
      cout << entry->d_name << endl;
    }
    // close all directory
    closedir(dir);
  } else {
    cerr << "Error opening directory." << endl;
  }
}

void createFile(const string &filename) {
  ofstream file(filename);
  if (file.is_open()) {
    cout << "File " << filename << " created successfully." << endl;
  } else {
    cout << "Error creating file " << filename << endl;
  }
}

void deleteFile(const string &filename) {
  if (remove(filename.c_str()) == 0) {
    cout << "File " << filename << " deleted successfully." << endl;
  } else {
    cout << "Error deleting file " << filename << endl;
  }
}

int main() {
  string path = "./";
  int choice;
  string filename;

  cout << "Basic File Manger System" << endl;

  do {
    cout << "\n1. List files\n2. Create file\n3. Delete file\n4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      listFiles(path);
      break;
    case 2:
      cout << "Enter filename to create: ";
      cin >> filename;
      createFile(filename);
      break;
    case 3:
      cout << "Enter filename to delete: ";
      cin >> filename;
      deleteFile(filename);
      break;
    case 4:
      cout << "Exiting program." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  } while (choice != 4);

  return 0;
}
