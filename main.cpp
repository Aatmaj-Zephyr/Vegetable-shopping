// Program to help in making the vegitable grocery list.
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
  char word[20];
  char qty[300];
  ifstream finnn;
  cout << "Last time's list'--\n";
  finnn.open("list.txt");
  while (finnn.eof() == 0) {
    finnn.getline(qty, 300);
    cout << qty << "\n";
  }
  finnn.close();
repeat:
  cout << "\n\nplease enter quantities'--\n";
  ofstream fout, hout;
  ifstream fin;
  fin.open("in.txt");
  fout.open("list.txt");
  hout.open("index.html");
  hout << "<html><body bgcolor=lime text=blue><h3 align=\"center\"> List of "
          "vegetables for My address </h3><table width=1000 height=150 "
          "align=\"center\" border=2><tr><th>Sr. "
          "No.</th><th>Item</th><th>Quantity</th></tr>";
  int k = 0;
  while (fin.eof() == 0) {
    fin.getline(word, 20);
    cout << word << "- ";
    cin.getline(qty, 30);
    if (qty[0] != '\0') {
      k++;
      fout << k << ") " << word << "- " << qty << "\n";
      hout << "<tr><td align=\"center\">" << k << "</td><td align=\"center\">"
           << word << "</td><td align=\"center\">" << qty << "</tr>";
    }
  }
  fout.close();
  hout << "</table></body></html>";
  ifstream finn;
  cout << "\n\n\n\n\n\n\n\nHere is your list--\n";
  finn.open("list.txt");
  while (finn.eof() == 0) {
    finn.getline(qty, 300);
    cout << qty << "\n";
  }
  finn.close();
  cout << "\nany correction? ";
  cin.getline(qty, 300);
  if (qty[0] != '\0') {
    goto repeat;
  }

  return 0;
}
