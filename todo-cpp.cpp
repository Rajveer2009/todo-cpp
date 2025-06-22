#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

void print_todo() { cout << "\033[1m" << "TODO" << "\033[0m" << endl; }

int add(string path, string task);

int list(string path);

int listC(string path);

int listN(string path);

int main(int argc, char** argv) {
  string path = getenv("TODO_PATH");
  if (path.empty()) {
    cerr << "TODO_PATH not defined";
    exit(1);
  }

  if (argc == 1) {
    cerr << "Usage: ./todo-cpp [command] [arguments]";
    exit(2);
  }

  string command = argv[1];

  if (!command.compare("add")) {
    if (argc > 3) {
      exit(3);
    }
    string task = argv[2];
    if(int i = add(path, task)) {
      exit(i);
    }
  } else if (!command.compare("list")) {
    print_todo();
    if(int i = list(path)) {
      exit(i);
    }
  } else if (!command.compare("listC")) {
    print_todo();
    if(int i = listC(path)) {
      exit(i);
    } 
  } else if (!command.compare("listN")) {
    if (int i = listN(path)) {
      exit(i);
    }
  } else {
    cerr << "Commands: add, list, listC, listN, mark, remove, reset";
  }

  return 0;
}

int add(string path, string task) {
  ofstream f;
  f.open(path, ios::app);
  if (!f.is_open()) {
    return 1;
  }

  time_t t = time(0);
  char date_time[20];
  strftime(date_time, sizeof(date_time), "%d/%m/%Y %H:%M:%S", localtime(&t));
  
  f << date_time << " - [ ] " << task << '\n';

  f.close();

  return 0;
}

int list(string path) {
  ifstream f;
  f.open(path);
  if(!f.is_open()) {
    return 1;
  }

  string line;
  while(getline(f, line)) {
    cout << line.substr(20, line.size()) << endl; 
  }

  f.close();

  return 0;
}

int listC(string path) {
  ifstream f;
  f.open(path);
  if(!f.is_open()) {
    return 1;
  }

  string line;
  int i(1);
  while(getline(f, line)) {
    cout << i << ". " << line << endl;
    i++;
  }

  return 0;  
}

int listN(string path) {
  ifstream f;
  f.open(path);
  if(!f.is_open()) {
    return 1;
  }

  string line;
  int i(1);
  while(getline(f, line)) {
    cout << i << ". " << line.substr(26, line.size()) << endl;
    i++;
  }

  return 0;
}
