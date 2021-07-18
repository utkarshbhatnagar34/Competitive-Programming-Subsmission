#include <bits/stdc++.h>
using namespace std;

class publication
{
public:
   string title;
   float price;
   publication() {
      title = "not given yet";
      price = 0;
   }
   publication(string a, float p) {
      title = a;
      price = p;
   }
   void getdata() {
      cout << "enter title\n";
      cin >> title;
      cout << "enter price\n";
      cin >> price;
   }
   void putdata() {
      cout << "title is " << title << "\n price is " << price << endl;
   }

};

class book:public publication
{
public:
   int page_count;
   book() {
      page_count = 0;
   }
   void getdata() {
      publication::getdata();
      cout << "enter number of pages of book\n";
      cin >> page_count;
   }
   void putdata() {
      publication::putdata();
      cout << "number of pages are =" << page_count << endl;
   }
};

class tape:public publication
{
public:
   int playing_min;
   tape() {
      playing_min = 0;
   }
   void getdata() {
      publication::getdata();
      cout << "enter number of playing_minutes \n";
      cin >> playing_min;
   }
   void putdata() {
      publication::putdata();
      cout << "length of casset " << playing_min << endl;
   }
};

int main()
{
   tape t;
   cout<<"for tape\n";
   t.getdata();
   t.putdata();

   book b;
   cout<<"for book\n";
   b.getdata();
   b.putdata();
   return 0;
}